/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:13:28 by hwang         #+#    #+#                 */
/*   Updated: 2023/03/03 17:13:29 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_hexlength(unsigned long n)
{
	int	i;

	i = 1;
	while (n / 16 != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_ptr_puthex_low(unsigned long n)
{
	int		length;
	char	*str;

	str = "0123456789abcdef";
	length = ft_ptr_hexlength(n);
	if (n > 15)
	{
		ft_ptr_puthex_low(n / 16);
		ft_putchar(str[n % 16]);
	}
	else
		ft_putchar(str[n % 16]);
	return (length);
}

int	ft_putptr(void *ptr)
{
	int	addlength;

	if (!ptr)
		return (write(1, "0x0", 3));
	addlength = write(1, "0x", 2);
	addlength += ft_ptr_puthex_low((unsigned long)ptr);
	return (addlength);
}
