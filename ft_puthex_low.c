/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_low.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:13:20 by hwang         #+#    #+#                 */
/*   Updated: 2023/03/03 17:13:21 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_low(unsigned int n)
{
	int		length;
	char	*str;

	str = "0123456789abcdef";
	length = ft_hexlength(n);
	if (n > 15)
	{
		ft_puthex_low(n / 16);
		ft_putchar(str[n % 16]);
	}
	else
		ft_putchar(str[n % 16]);
	return (length);
}

// int main()
// {
//     int i = -365;
// 	printf("%x\n", i);
// 	printf("\n%i\n", ft_puthex_low(i));
// }