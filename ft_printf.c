/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:13:03 by hwang         #+#    #+#                 */
/*   Updated: 2023/03/03 17:13:04 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_argprint(char c, va_list args)
{
	int	add_length;

	add_length = 0;
	if (c == 's')
		add_length = ft_putstr(va_arg(args, char *));
	if (c == 'c')
		add_length = ft_putchar(va_arg(args, int));
	if (c == 'i' || c == 'd')
		add_length = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		add_length = ft_put_unsigned_int(va_arg(args, int));
	if (c == 'x')
		add_length = ft_puthex_low(va_arg(args, int));
	if (c == 'X')
		add_length = ft_puthex_upper(va_arg(args, int));
	if (c == 'p')
		add_length = ft_putptr(va_arg(args, void *));
	if (c == '%')
		add_length = ft_putchar('%');
	return (add_length);
}

int	ft_realprint(const char *input, va_list args, size_t length)
{
	while (*input)
	{
		if (*input != '%')
		{
			ft_putchar(*input);
			length++;
		}
		else if (*input == '%')
		{
			input++;
			length += ft_argprint(*input, args);
		}
		input++;
	}
	return (length);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		ret;

	va_start(args, input);
	ret = ft_realprint(input, args, 0);
	va_end(args);
	return (ret);
}

// int main()
// {
// 	char str[] = "1234";
// 	char str2[] = "bpmf";
// 	char c = 'n';
// 	int i = -365;
// 	printf("this is %s, that is %c, these are %s, 
// 		the end is %i. I'm %%%% happy.\n", str, c, str2, i);
// 	ft_printf("this is %s, that is %c, these are %s, 
// 		the end is %i. I'm %%%% happy.\n", str, c, str2, i);
// 	int ret = ft_printf("he%s,she%c,it%i\n", str2, c, i);
// 	printf("%i\n", ret);
// 	int ret1 = printf("%u\n", i);
// 	int ret2 = ft_printf("%u\n", i);
// 	printf("%i\n", ret1);
// 	printf("%i\n", ret2);
// 	int ret3 = printf("Hex is %x\n", i);
// 	int ret4 = ft_printf("Hex is %x\n", i);
// 	printf("%i\n", ret3);
// 	printf("%i\n", ret4);
// 	int ret5 = printf("Pointer is %p\n", str2);
// 	int ret6 = ft_printf("Pointer is %p\n", str2);
// 	printf("%i\n", ret5);
// 	printf("%i\n", ret6);
// 	int ret7 = printf("Pointer is %p\n", LONG_MAX);
// 	int ret8 = ft_printf("Pointer is %p\n", LONG_MAX);
// 	printf("%i\n", ret7);
// 	printf("%i\n", ret8);
// 	return (0);
// }

// gcc ft_printf.c ft_intlength.c ft_put_unsigned_int.c ft_putchar.c 
// ft_putnbr.c ft_putstr.c ft_strlen.c ft_unsigned_intlength.c 
// ft_puthex_low.c ft_hexlength.c ft_puthex_upper.c ft_putptr.c