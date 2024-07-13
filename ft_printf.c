/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:33:15 by miyuu             #+#    #+#             */
/*   Updated: 2024/07/14 00:50:25 by miyuu            ###   ########.fr       */
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
	size_t	len;
	va_list	ap;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	len = ft_strlen(str);
	va_start(ap, str);
	while (i < len)
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
	// printf("count = %d\n",count);
	return (count);
}


int	main(void)
{

	// printf("\n以下%%p\n");
	// void	*p = "16";
	// printf("or:%%p = %p \n", p);
	// printf("or:%%s = %s \n", p);
	// printf("or:%%i = %i \n", p);
	// printf("or:%%d = %d \n", p);
	// printf("or:%%x = %x \n", &p);
	// printf("or:%%X = %X \n", &p);
	// printf("or:%%p = %p \n", &p);

	// printf("\n以下%%p_2\n");
	// void	*p_2 = "hello";
	// printf("or:%%p = %p \n", p_2);
	// printf("or:%%s = %s \n", p_2);
	// printf("or:%%i = %i \n", p_2);
	// printf("or:%%d = %d \n", p_2);
	// printf("or:%%x = %x \n", &p_2);
	// printf("or:%%X = %X \n", &p_2);
	// printf("or:%%p = %p \n", &p_2);

	// ft_printf("ft:%%p = %p \n", p);

int count = 0;


printf("\x1b[31m"); // 前景赤色出力
// 	count = printf("Hello, World!\n");
// 	printf("count = %d\n", count);
// 	ft_printf("Hello, World!\n");
// 	count = printf("");
// 	printf("count = %d\n", count);
// 	ft_printf("");
// 	count = printf("Hello, World!\n""1""2\n");
// 	printf("count = %d\n", count);
// 	ft_printf("Hello, World!\n""1""2\n");

// 	count = printf("\n");
// 	printf("count = %d\n", count);
// 	ft_printf("\n");

printf("\n以下%%c\n");
	char	c = 'i';
	// count = printf("or:%%c = %c\n", c);
	// printf("count = %d\n", count);
	ft_printf("ft:%%c = %c\n", c);
	count = printf("or:%%c -> %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c\n", '1', '2', '3', '4', '5', '6', '7', 'i', 'I', 'B', 'a');
	printf("count = %d\n", count);
	ft_printf("ft:%%c -> %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c\n", '1', '2', '3', '4', '5', '6', '7', 'i', 'I', 'B', 'a');

printf("\n以下%%s\n");
	char	s[] = "Hello, World!";
	count = printf("or:%%s = %s\n", s);
	printf("count = %d\n", count);
	ft_printf("ft:%%s = %s\n", s);
	count = printf("or:%%s -> %s, %s, %s, %s\n", "1", "42Tokyo", "空白　。", "改行\n");
	printf("count = %d\n", count);
	ft_printf("ft:%%s -> %s, %s, %s, %s\n", "1", "42Tokyo", "空白　。", "改行\n");

printf("\n以下%%p\n");
	void	*p_3 = "42";
	count = printf("or:%%p = %p\n", p_3);
	printf("count = %d\n", count);
	ft_printf("ft:%%p = %p\n", p_3);

printf("\n以下%%d\n");
	char	d_char = 10;
	count = printf("or:%%d_char = %d\n", d_char);
	printf("count = %d\n", count);
	ft_printf("ft:%%d_char = %d\n", d_char);

	int	d_int = 100;
	count = printf("or:%%d_int = %d\n", d_int);
	printf("count = %d\n", count);
	ft_printf("ft:%%d_int = %d\n", d_int);

printf("\n以下%%i\n");
	int	i = 123;
	int i_2 = -+000456;
	count = printf("or:%%iは　= %iです。%%i = %i\n", i, i_2);
	printf("count = %d\n", count);
	ft_printf("ft:%%iは　= %iです。%%i = %i\n", i, i_2);
	count = printf("or:%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	printf("count = %d\n", count);
	ft_printf("ft:%i, %i, %i, %i, %i, %i, %i, %i, %i, %i, %i\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

printf("\n以下%%u\n");
	unsigned int	u_unint = 0;
	unsigned int	u_unint_2 = 456;
	unsigned int	u_unint_3 = -+456;
	unsigned int	u_unint_4 = 4294967295;
	unsigned int	u_unint_5 = 2147483647;
	count = printf("or:%%u_unint = %u\n", u_unint);
	printf("count = %d\n", count);
	count = printf("or:%%u_unint_2 = %u\n", u_unint_2);
	printf("count = %d\n", count);
	count = printf("or:%%u_unint_3 = %u\n", u_unint_3);
	printf("count = %d\n", count);
	count = printf("or:%%u_unint_4 = %u\n", u_unint_4);
	printf("count = %d\n", count);
	count = printf("or:%%u_unint_4 = %u\n", u_unint_5);
	printf("count = %d\n", count);
	ft_printf("ft:%%u_unint = %u\n", u_unint);
	ft_printf("ft:%%u_unint_2 = %u\n", u_unint_2);
	ft_printf("ft:%%u_unint_3 = %u\n", u_unint_3);
	ft_printf("ft:%%u_unint_4 = %u\n", u_unint_4);
	ft_printf("ft:%%u_unint_4 = %u\n", u_unint_5);

	unsigned short	u_unshort = 0;
	unsigned short	u_unshort_2 = 456;
	unsigned short	u_unshort_3 = -+456;
	unsigned short	u_unshort_4 = 65535;
	count = printf("or:%%u_unshort = %u\n", u_unshort);
	printf("count = %d\n", count);
	count = printf("or:%%u_unshort_2 = %u\n", u_unshort_2);
	printf("count = %d\n", count);
	count = printf("or:%%u_unshort_3 = %u\n", u_unshort_3);
	printf("count = %d\n", count);
	count = printf("or:%%u_unshort_4 = %u\n", u_unshort_4);
	printf("count = %d\n", count);
	ft_printf("ft:%%u_unshort = %u\n", u_unshort);
	ft_printf("ft:%%u_unshort_2 = %u\n", u_unshort_2);
	ft_printf("ft:%%u_unshort_3 = %u\n", u_unshort_3);
	ft_printf("ft:%%u_unshort_4 = %u\n", u_unshort_4);

printf("\n以下%%x\n");
	int	x_int = 0;
	int	x_int_1 = 10;
	int	x_int_2 = 42;
	int	x_int_3 = -420;
	count = printf("or:%%x_int = %x\n", x_int);
	printf("count = %d\n", count);
	count = printf("or:%%x_int_1 = %x\n", x_int_1);
	printf("count = %d\n", count);
	count = printf("or:%%x_int_2 = %x\n", x_int_2);
	printf("count = %d\n", count);
	count = printf("or:%%x_int_3 = %x\n", x_int_3);
	printf("count = %d\n", count);
	ft_printf("ft:%%x_int = %x\n", x_int);
	ft_printf("ft:%%x_int_1 = %x\n", x_int_1);
	ft_printf("ft:%%x_int_2 = %x\n", x_int_2);
	ft_printf("ft:%%x_int_3 = %x\n", x_int_3);
	// printf("int %%x_int = %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x\n", x_int, 1, 2, 3, 10, 16, 42, '1', '2', '3', '10', '16', '42');

	short	x_short = 10;
	short	x_short_1 = 10;
	short	x_short_2 = 42;
	short	x_short_3 = -420;
	count = printf("or:%%x_short = %x\n", x_short);
	printf("count = %d\n", count);
	count = printf("or:%%x_short_1 = %x\n", x_short_1);
	printf("count = %d\n", count);
	count = printf("or:%%x_short_2 = %x\n", x_short_2);
	printf("count = %d\n", count);
	count = printf("or:%%x_short_3 = %x\n", x_short_3);
	printf("count = %d\n", count);
	ft_printf("ft:%%x_short = %x\n", x_short);
	ft_printf("ft:%%x_short_1 = %x\n", x_short_1);
	ft_printf("ft:%%x_short_2 = %x\n", x_short_2);
	ft_printf("ft:%%x_short_3 = %x\n", x_short_3);

	unsigned int	x_unint = 10;
	count = printf("or:%%x_unsigned int  = %x\n", x_unint);
	printf("count = %d\n", count);
	ft_printf("ft:%%x_unsigned int  = %x\n", x_unint);

	unsigned short	x_unshort = 10;
	count = printf("or:%%x_unsigned short  = %x\n", x_unshort);
	printf("count = %d\n", count);
	ft_printf("ft:%%x_unsigned short  = %x\n", x_unshort);

	int	X = 10;
	count = printf("or:%%X = %X\n", X);
	printf("count = %d\n", count);
	ft_printf("ft:%%X = %X\n", X);

	count = printf("or:%% = %%\n");
	printf("count = %d\n", count);
	ft_printf("ft:%% = %%\n");

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

