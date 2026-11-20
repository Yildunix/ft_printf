/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endyildi <endyildi@mulhouse42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 15:11:48 by endyildi          #+#    #+#             */
/*   Updated: 2026/11/20 23:01:55 by endyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *input, ...);
int		ft_print_char(char c);
int		ft_writelen(char *str);
void	ft_putchar(char c);
int		count_nbr(long nbr);
int		ft_printnbr(int nbr);
int		ft_unsignedprintnbr(unsigned int nbr);
int		ft_print_hexa(unsigned int nbr, char s);
int		ft_print_address(void *ptr);

#endif
