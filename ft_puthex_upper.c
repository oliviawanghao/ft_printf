/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_upper.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:13:23 by hwang         #+#    #+#                 */
/*   Updated: 2023/03/03 17:13:24 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	int		length;
	char	*str;

	str = "0123456789ABCDEF";
	length = ft_hexlength(n);
	if (n > 15)
	{
		ft_puthex_upper(n / 16);
		ft_putchar(str[n % 16]);
	}
	else
		ft_putchar(str[n % 16]);
	return (length);
}
