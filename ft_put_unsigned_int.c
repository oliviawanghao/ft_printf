/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_unsigned_int.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:13:10 by hwang         #+#    #+#                 */
/*   Updated: 2023/03/03 17:13:11 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_int(unsigned int n)
{
	int	length;

	length = ft_unsigned_intlength(n);
	if (n > 9)
	{
		ft_put_unsigned_int(n / 10);
		ft_putchar('0' + n % 10);
	}
	else
		ft_putchar('0' + n);
	return (length);
}

// int main()
// {
//     int i = -214589;
// 	printf("%u\n", i);
// 	printf("\n%i", ft_put_unsigned_int(i));
// }