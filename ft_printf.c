/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:33:15 by miyuu             #+#    #+#             */
/*   Updated: 2024/07/14 02:06:00 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_printf_format(const char *str, va_list ap, size_t i)
{
	int	count;

	count = 1;
	i += 1;
	if (str[i] == '%')
		write(1, &str[i], 1);
	else if (str[i] == 'i' || str[i] == 'd')
		count = ft_printf_d(va_arg(ap, int));
	else if (str[i] == 'c')
		count = ft_printf_c(va_arg(ap, int));
	else if (str[i] == 's')
		count = ft_printf_s(va_arg(ap, char*));
	else if (str[i] == 'p')
		count = ft_printf_p(va_arg(ap, void*));
	else if (str[i] == 'u')
		count = ft_printf_u(va_arg(ap, unsigned int));
	else if (str[i] == 'x')
		count = ft_printf_x(va_arg(ap, unsigned int));
	else if (str[i] == 'X')
		count = ft_printf_x_upper(va_arg(ap, unsigned int));
	else
		write(1, &str[i], 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	ap;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += ft_printf_format(str, ap, i);
			i++;
			if (str[i] != '%')
				va_arg(ap, char*);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end (ap);
	return (count);
}
