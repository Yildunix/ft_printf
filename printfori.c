/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfori.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endyildi <endyildi@mulhouse42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 21:21:28 by endyildi          #+#    #+#             */
/*   Updated: 2026/11/20 23:35:50 by endyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (c == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (c == 's')
		len += ft_writelen(va_arg(args, char *));
	else if (c == 'x')
		len += ft_print_hexa(va_arg(args, unsigned int), c);
	else if (c == 'X')
		len += ft_print_hexa(va_arg(args, unsigned int), c);
	else if (c == 'p')
		len += ft_print_address(va_arg(args, void *));
	else if (c == 'u')
		len += ft_unsignedprintnbr(va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	size_t	i;
	int		len;

	if (input == NULL)
		return (-1);
	len = 0;
	i = 0;
	va_start(arg, input);
	while (input[i] != 0)
	{
		if (input[i] == '%' && input[i + 1])
		{
			len += ft_format(arg, input[i + 1]);
			i += 2;
		}
		else
		{
			len += ft_print_char(input[i]);
			i++;
		}
	}
	va_end(arg);
	return (len);
}
