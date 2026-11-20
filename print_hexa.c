/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endyildi <endyildi@mulhouse42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 15:45:16 by endyildi          #+#    #+#             */
/*   Updated: 2026/11/20 23:29:01 by endyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int nbr, char s)
{
	char	*base;
	int		i;

	i = 0;
	if (s == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
		i += ft_print_hexa(nbr / 16, s);
	write(1, &base[nbr % 16], 1);
	i++;
	return (i);
}

static int	ft_puthexa(unsigned long c)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (c >= 16)
		i += ft_puthexa(c / 16);
	i += write(1, &base[c % 16], 1);
	return (i);
}

int	ft_print_address(void *ptr)
{
	unsigned long	c;
	int				i;

	if (!ptr)
		return (write(1, "(nil)", 5));
	c = (unsigned long)ptr;
	i = write(1, "0x", 2);
	i += ft_puthexa(c);
	return (i);
}
