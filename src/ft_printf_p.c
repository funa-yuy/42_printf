/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:19:31 by miyuu             #+#    #+#             */
/*   Updated: 2025/01/20 21:30:16 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"
#include <stdio.h>
#include <stdint.h>

int	ft_printf_p(void *p)
{
	char		*base;
	char		result[19];
	int			i;
	uintptr_t	p_ad;

	p_ad = (uintptr_t)p;
	base = "0123456789abcdef";
	result[18] = '\0';
	result[17] = base[p_ad % 16];
	i = 17;
	while (p_ad >= 16)
	{
		p_ad /= 16;
		result[--i] = base[p_ad % 16];
	}
	result[--i] = 'x';
	result[--i] = '0';
	return (write(1, result + i, 18 - i));
}
