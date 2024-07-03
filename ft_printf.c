/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:33:15 by miyuu             #+#    #+#             */
/*   Updated: 2024/07/03 16:59:14 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

// size_t	ft_strlen(const char *s);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total_size;
	size_t	i;

	if (count != 0 && size != 0 && SIZE_MAX / count <= size)
		return (NULL);
	total_size = count * size;
	i = 0;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	while (total_size > i)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

static size_t	ft_intlen(long n, int len)
{
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*dst;
	int				len;
	unsigned int	nb;

	dst = ft_calloc((ft_intlen(n, 1) + 1), sizeof(char));
	if (!dst)
		return (NULL);
	len = ft_intlen(n, 1);
	dst[len] = '\0';
	if (n < 0)
	{
		dst[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	while (len-- && dst[len] != '-')
	{
		dst[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dst);
}


void	ft_printf_i(int d)
{
	size_t	i_len = ft_strlen(ft_itoa(d));
	write(1, ft_itoa(d), i_len);
}

void	ft_printf_c(int c)
{
	write(1, &c, 1);
}
void	ft_printf_c(int c)
{

	write(1, &c, 1);
}

int	ft_printf(const char *str, ...)
{

	size_t	num = 0;
	size_t	hiki_let = 0;
	size_t	i = 0;


    va_list ap;
    va_start(ap, str);


	while(str[i] != '\0')
	{
		if('%' == str[i])
			hiki_let = 1;
		i++;
	}
    // while (num <= hiki_let)
    // {
		i = 0;
		size_t	len = ft_strlen(str);

		while (i < len)
		{
			if(str[i] == '%')
			{
				i++;
				if (str[i] == 'i' || str[i] == 'd')
					ft_printf_i(va_arg(ap, int));
				else if (str[i] == 'c')
					ft_printf_c(va_arg(ap, int));
				else if (str[i] == 's')
					ft_printf_s(va_arg(ap, int));
				else if (str[i] == '%')
					write(1, &str[i], 1);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
        // int d = va_arg(ap, int);
		// len = ft_strlen(str);
		// write(1, ft_itoa(d), len);
		// num++;
    // }
    va_end(ap);
	return (0);
}


int	main(void)
{
	// ft_printf("Hello, World!\n");
	// printf("Hello, World!\n""1""2\n");

	char	c = 'i';
	printf("%%c = %c \n", c);
	ft_printf("%%c = %c \n", c);
	printf("%c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c\n", '1', '2', '3', '4', '5', '6', '7', '8', '9', 'B', 'a');
	ft_printf("%c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c\n", '1', '2', '3', '4', '5', '6', '7', '8', '9', 'B', 'a');


	char	s[] = "Hello, World!";
	printf("%%s = %s \n", s);
	ft_printf("%%s = %s \n", s);

	// void	*p = "16";
	// printf("%%p = %p \n", p);
	// ft_printf("%%p = %p \n", p);

	// char	d_char = 10;
	// printf("%%d_char = %d \n", d_char);
	// ft_printf("%%d_char = %d \n", d_char);

	// int	d_int = 10;
	// printf("%%d_int = %d \n", d_int);
	// ft_printf("%%d_int = %d \n", d_int);

	int	i = 123;
	int i_2 = -+000456;
	printf("%%iは　= %iです。%%i = %i\n", i, i_2);
	ft_printf("%%iは　= %iです。%%i = %i\n", i, i_2);
	printf("%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	ft_printf("%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

	// unsigned int	u_unint = 1000;
	// printf("%%u_unint = %u \n", u_unint);
	// ft_printf("%%u_unint = %u \n", u_unint);

	// unsigned short	u_unshort = 1000;
	// printf("%%u_unshort = %u \n", u_unshort);
	// ft_printf("%%u_unshort = %u \n", u_unshort);

	// int	x_int = 10;
	// printf("int %%x_int = %x \n", x_int);
	// ft_printf("int %%x_int = %x \n", x_int);

	// short	x_short = 10;
	// printf("short %%x_short = %x \n", x_short);
	// ft_printf("short %%x_short = %x \n", x_short);

	// unsigned int	x_unint = 10;
	// printf("unsigned int %%x_unint = %x \n", x_unint);
	// ft_printf("unsigned int %%x_unint = %x \n", x_unint);

	// unsigned short	x_unshort = 10;
	// printf("unsigned short %%x_unshot = %x \n", x_unshort);
	// ft_printf("unsigned short %%x_unshot = %x \n", x_unshort);

	// int	X = 10;
	// printf("%%X = %X \n", X);
	// ft_printf("%%X = %X \n", X);

	// printf("%% = %% \n");
	// ft_printf("%% = %% \n");

	return (0);
}


// • %c 1 文字を出力します。
// • %s 文字列を出力します (一般的な C 規約で定義されています)。
// • %p void * ポインター引数は 16 進形式で出力する必要があります。
// • %d 10 進数 (基数 10) を出力します。
// • %i 10 進数の整数を出力します。
// • %u 符号なし 10 進数 (基数 10) を出力します。
// • %x 16 進数 (基数 16) 小文字形式で数値を出力します。
// • %X 16 進数 (基数 16) 大文字形式で数値を出力します。
// • %% パーセント記号を出力します
