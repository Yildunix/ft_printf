*This project has been created as part of the 42 curriculum by endyildi.*

# ft_printf

## Description

`ft_printf` is a recreation of the libc `printf()` function. The goal of the project is to learn how **variadic functions** work in C (`va_start`, `va_arg`, `va_end`) and to write well-structured code that is easy to extend.

The project is built as a static library, `libftprintf.a`, which exposes a single public function:

```c
int ft_printf(const char *format, ...);
```

Like the original, it writes the formatted output to the standard output and returns the number of characters printed (or `-1` if `format` is `NULL`). As the subject requires, there is no buffer management: every character is written directly with `write()`.

### Supported conversions

| Conversion | Output |
|------------|--------|
| `%c` | A single character |
| `%s` | A string (`(null)` if the pointer is `NULL`) |
| `%p` | A `void *` pointer in hexadecimal, prefixed with `0x` (`(nil)` if `NULL`) |
| `%d` | A signed decimal (base 10) integer |
| `%i` | A signed integer in base 10 |
| `%u` | An unsigned decimal (base 10) integer |
| `%x` | An unsigned number in lowercase hexadecimal |
| `%X` | An unsigned number in uppercase hexadecimal |
| `%%` | A literal percent sign |

## Instructions

### Compilation

```bash
make        # builds libftprintf.a at the root of the repository
make clean  # removes the object files (obj/)
make fclean # removes the object files and libftprintf.a
make re     # fclean + all
```

The library is compiled with `cc -Wall -Wextra -Werror` and archived with `ar rcs`.

### Usage

Include the header and link the library to your program:

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s, you are %d years old!\n", "world", 42);
    ft_printf("Printed %u chars, %x in hex, %X in HEX\n", len, 255, 255);
    ft_printf("Address: %p, char: %c, percent: %%\n", &len, 'A');
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Algorithm and data structure

### Project layout

| File | Role |
|------|------|
| `ft_printf.h` | Prototypes and includes (`unistd.h`, `stdarg.h`, `stddef.h`) |
| `printfori.c` | `ft_printf()` (main loop) and `ft_format()` (dispatcher) |
| `print_char.c` | `%c`, `%%` and `%s` |
| `print_int.c` | `%d`, `%i` and `%u` |
| `print_hexa.c` | `%x`, `%X` and `%p` |

### How it works

1. **Linear scan of the format string.** `ft_printf()` reads the format string one character at a time with an index. Ordinary characters are written immediately and counted.
2. **Dispatch on `%`.** When a `%` is followed by another character, that character is passed to `ft_format()` with the `va_list`. A chain of `if / else if` matches the conversion and calls the right helper with `va_arg` and the matching type (`int`, `unsigned int`, `char *`, `void *`). The index then moves forward by 2.
3. **Each helper returns how many characters it wrote.** The main loop adds these values together, so the return value of `ft_printf()` is the total length of the output, just like the real `printf()`.

### Number printing: recursion

Numbers are printed with a **recursive base conversion**: the function calls itself with `n / base` until the number is smaller than the base, then writes the digit `n % base`. Because digits are written as the recursion unwinds, they come out in the correct order (most significant first) **without any temporary buffer or `malloc`**.

- **Decimal (`%d`, `%i`, `%u`):** the value is copied into a `long` / `unsigned long` before it is negated, so `INT_MIN` (`-2147483648`) is handled without overflow. The printed length is computed separately by `count_nbr()`, which counts the digits and adds one for the minus sign (or for `0`).
- **Hexadecimal (`%x`, `%X`):** the same recursion in base 16. The base string is chosen from the conversion character (`"0123456789abcdef"` or `"0123456789ABCDEF"`), so one function handles both cases.
- **Pointer (`%p`):** the pointer is cast to `unsigned long` so the full 64-bit address fits, then `0x` is printed followed by the lowercase hex recursion. A `NULL` pointer prints `(nil)`, matching glibc's `printf()`.

### Why these choices

- **No data structure beyond the `va_list`.** The mandatory part has no flags, width or precision to store, so a parsing struct isn't needed. Reading the format once and dispatching on the character keeps the code short and easy to follow.
- **Recursion over a buffer.** It avoids dynamic allocation (no risk of leaks) and gets the digits in the right order naturally. The recursion depth stays very small (at most 20 calls for a 64-bit value in base 10).
- **One file per conversion family.** Characters/strings, integers and hexadecimal each live in their own file. Adding a new conversion only means writing a helper and adding one branch in `ft_format()`.

## Resources

- `man 3 printf`: reference behavior for every conversion
- `man 3 stdarg`: `va_start`, `va_arg`, `va_copy`, `va_end`
- [cppreference: printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference: Variadic arguments](https://en.cppreference.com/w/c/variadic)
- [GNU C Library: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- The 42 Norm (norminette) documentation

### Use of AI

AI (Claude) was used **only to write this README**, based on the subject and on the existing source code. All of the C code (`ft_printf()`, the conversion helpers and the Makefile) was written by me, without AI.
