/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endyildi <endyildi@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 15:49:32 by endyildi          #+#    #+#             */
/*   Updated: 2026/11/19 16:31:44 by endyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void ft_putchar(char c)
{
	write (1 , &c, 1);
}
int count_nbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		n = -n;
		i++;
	}
	while(nbr > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int ft_printnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (nbr >= 10)
		ft_printnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
	return (count_nbr(nbr));
}

int ft_unsignedprintnbr(unsigned int nbr)
{
	if (nbr >= 10)
		ft_printnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
	return (count_nbr(nbr));
}