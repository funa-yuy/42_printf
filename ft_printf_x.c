/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:19:31 by miyuu             #+#    #+#             */
/*   Updated: 2024/07/13 22:31:47 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf_x(unsigned int x)
{
	char	*base;
	char	memo[9];
	int		i;

	base = "0123456789abcdef";
	memo[8] = '\0';
	memo[7] = base[x % 16];
	i = 7;
	while (x >= 16)
	{
		x /= 16;
		memo[--i] = base[x % 16];
	}
	return (write(STDOUT_FILENO, memo + i, 8 - i));
}
