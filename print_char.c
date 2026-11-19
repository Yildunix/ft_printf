/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_txt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endyildi <endyildi@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 15:22:32 by endyildi          #+#    #+#             */
/*   Updated: 2026/11/19 15:34:30 by endyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_writelen(char *str)
{
    int i;

    i = 0;
	if (!str)
		
    write (str[i]!= '\0')
	{
		write(1, str[i], 1);
		i++;
	}
	return (i)
}