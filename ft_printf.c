/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:33:15 by miyuu             #+#    #+#             */
/*   Updated: 2024/07/03 20:19:40 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

size_t	ft_strlen(const char *s);

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
	size_t	i_len;

	i_len = ft_strlen(ft_itoa(d));
	write(1, ft_itoa(d), i_len);
}

void	ft_printf_c(int c)
{
	write(1, &c, 1);
}

void	ft_printf_s(char *s)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	write(1, s, s_len);
}

void	ft_printf_x(char *x)
{
	// size_t	s_len;
	int i = 0;
	int j = 0;
	int num;

	// s_len = ft_strlen(s);
	  char answer[10];
	  while(num > 0) {
    // 入力した数値を16で割り、その余りと商をだす
    j = num % 16;
    num = num / 16;
    answer[i] = x[j];
    i++;
  }
  i--;


  for(j=i; j>=0; j--) {
    printf("%c",answer[j]);
  }

	// write(1, &s, 10);
}
void	ft_printf_u(unsigned int u)
{
	size_t	i_len;

	i_len = ft_strlen(ft_itoa(u));
	write(1, ft_itoa(u), i_len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	ap;

	i = 0;
	if (!str)
		return (0);
	len = ft_strlen(str);
	va_start(ap, str);

	while (i < len)
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'i' || str[i] == 'd')
				ft_printf_i(va_arg(ap, int));
			else if (str[i] == 'c')
				ft_printf_c(va_arg(ap, int));
			else if (str[i] == 's')
				ft_printf_s(va_arg(ap, char*));
			// else if (str[i] == 'p')
			// 	ft_printf_p(va_arg(ap, char*));
			else if (str[i] == 'u')
				ft_printf_u(va_arg(ap, unsigned int));
			// else if (str[i] == 'x')
			// 	ft_printf_x(va_arg(ap, char*));
			else if (str[i] == '%')
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end (ap);
	return (0);
}


int	main(void)
{
printf("\x1b[31m"); // 前景赤色出力
	printf("Hello, World!\n");
	ft_printf("Hello, World!\n");
	printf("Hello, World!\n""1""2\n");
	ft_printf("Hello, World!\n""1""2\n");

	printf("\n");
	ft_printf("\n");

printf("\n以下%%c\n");
	char	c = 'i';
	printf("%%c = %c \n", c);
	ft_printf("%%c = %c \n", c);
	printf("%%c -> %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c\n", '1', '2', '3', '4', '5', '6', '7', 'i', 'I', 'B', 'a');
	ft_printf("%%c -> %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c\n", '1', '2', '3', '4', '5', '6', '7', 'i', 'I', 'B', 'a');

printf("\n以下%%s\n");
	char	s[] = "Hello, World!";
	printf("%%s = %s \n", s);
	ft_printf("%%s = %s \n", s);
	printf("%%s -> %s, %s, %s, %s\n", "1", "42Tokyo", "空白　。", "改行\n");
	ft_printf("%%s -> %s, %s, %s, %s\n", "1", "42Tokyo", "空白　。", "改行\n");

printf("\n以下%%p\n");
	void	*p = "16";
	printf("%%p = %p \n", p);
	ft_printf("%%p = %p \n", p);

printf("\n以下%%d\n");
	char	d_char = 10;
	printf("%%d_char = %d \n", d_char);
	ft_printf("%%d_char = %d \n", d_char);

	int	d_int = 100;
	printf("%%d_int = %d \n", d_int);
	ft_printf("%%d_int = %d \n", d_int);

printf("\n以下%%i\n");
	int	i = 123;
	int i_2 = -+000456;
	printf("%%iは　= %iです。%%i = %i\n", i, i_2);
	ft_printf("%%iは　= %iです。%%i = %i\n", i, i_2);
	printf("%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	ft_printf("%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

printf("\n以下%%u\n");
	unsigned int	u_unint = 0;
	unsigned int	u_unint_2 = 456;
	unsigned int	u_unint_3 = -+456;
	unsigned int	u_unint_4 = 4294967295;
	unsigned int	u_unint_5 = 2147483647;
	printf("%%u_unint = %u \n", u_unint);
	printf("%%u_unint_2 = %u \n", u_unint_2);
	printf("%%u_unint_3 = %u \n", u_unint_3);
	printf("%%u_unint_4 = %u \n", u_unint_4);
	printf("%%u_unint_4 = %u \n", u_unint_5);
	ft_printf("%%u_unint = %u \n", u_unint);
	ft_printf("%%u_unint_2 = %u \n", u_unint_2);
	ft_printf("%%u_unint_3 = %u \n", u_unint_3);
	ft_printf("%%u_unint_4 = %u \n", u_unint_4);
	ft_printf("%%u_unint_4 = %u \n", u_unint_5);

	unsigned short	u_unshort = 0;
	unsigned short	u_unshort_2 = 456;
	unsigned short	u_unshort_3 = -+456;
	unsigned short	u_unshort_4 = 65535;
	printf("%%u_unshort = %u \n", u_unshort);
	printf("%%u_unshort_2 = %u \n", u_unshort_2);
	printf("%%u_unshort_3 = %u \n", u_unshort_3);
	printf("%%u_unshort_4 = %u \n", u_unshort_4);
	ft_printf("%%u_unshort = %u \n", u_unshort);
	ft_printf("%%u_unshort_2 = %u \n", u_unshort_2);
	ft_printf("%%u_unshort_3 = %u \n", u_unshort_3);
	ft_printf("%%u_unshort_4 = %u \n", u_unshort_4);

printf("\n以下%%x\n");
	int	x_int = 0;
	int	x_int_1 = 10;
	int	x_int_2 = 42;
	int	x_int_3 = -420;
	printf("short %%x_int = %x \n", x_int);
	printf("short %%x_int_1 = %x \n", x_int_1);
	printf("short %%x_int_2 = %x \n", x_int_2);
	printf("short %%x_int_3 = %x \n", x_int_3);
	ft_printf("int %%x_int = %x \n", x_int);
	// printf("int %%x_int = %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x\n", x_int, 1, 2, 3, 10, 16, 42, '1', '2', '3', '10', '16', '42');

	short	x_short = 10;
	short	x_short_1 = 10;
	short	x_short_2 = 42;
	short	x_short_3 = -420;
	printf("short %%x_short = %x \n", x_short);
	printf("short %%x_short_1 = %x \n", x_short_1);
	printf("short %%x_short_2 = %x \n", x_short_2);
	printf("short %%x_short_3 = %x \n", x_short_3);
	ft_printf("short %%x_short = %x \n", x_short);

	unsigned int	x_unint = 10;
	printf("unsigned int %%x_unint = %x \n", x_unint);
	ft_printf("unsigned int %%x_unint = %x \n", x_unint);

	unsigned short	x_unshort = 10;
	printf("unsigned short %%x_unshot = %x \n", x_unshort);
	ft_printf("unsigned short %%x_unshot = %x \n", x_unshort);

	int	X = 10;
	printf("%%X = %X \n", X);
	ft_printf("%%X = %X \n", X);

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
