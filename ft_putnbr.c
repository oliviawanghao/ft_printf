/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:13:26 by hwang         #+#    #+#                 */
/*   Updated: 2023/03/03 17:13:27 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	length;

	length = ft_intlength(n);
	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putchar('0' + n % 10);
		}
		else
			ft_putchar('0' + n);
	}
	return (length);
}

// int main()
// {
//     int i = -2147483648;
// 	printf("\n%i", ft_putnbr(i));
// }