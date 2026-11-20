/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endyildi <endyildi@mulhouse42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 15:49:32 by endyildi          #+#    #+#             */
/*   Updated: 2026/11/20 23:04:28 by endyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	count_nbr(long nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_ul(unsigned long n)
{
	if (n >= 10)
		ft_putnbr_ul(n / 10);
	ft_putchar((n % 10) + '0');
}

int	ft_printnbr(int nbr)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ft_putnbr_ul(n);
	return (count_nbr(nbr));
}

int	ft_unsignedprintnbr(unsigned int nbr)
{
	ft_putnbr_ul(nbr);
	return (count_nbr(nbr));
}
