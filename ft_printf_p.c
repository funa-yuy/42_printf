/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:19:31 by miyuu             #+#    #+#             */
/*   Updated: 2024/07/13 23:31:03 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf_p(void *p)
{
	char		*base;
	char		memo[19];
	int			i;
	uintptr_t	p_ad;

	p_ad = (uintptr_t)p;
	base = "0123456789abcdef";
	memo[18] = '\0';
	memo[17] = base[p_ad % 16];
	i = 17;
	while (p_ad >= 16)
	{
		p_ad /= 16;
		memo[--i] = base[p_ad % 16];
	}
	memo[--i] = 'x';
	memo[--i] = '0';
	return (write(STDOUT_FILENO, memo + i, 18 - i));
}
