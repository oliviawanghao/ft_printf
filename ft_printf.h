/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 17:13:07 by hwang         #+#    #+#                 */
/*   Updated: 2023/03/03 17:13:08 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);

int		ft_intlength(int n);
int		ft_putnbr(int n);

int		ft_unsigned_intlength(unsigned int n);
int		ft_put_unsigned_int(unsigned int n);

int		ft_hexlength(unsigned int n);
int		ft_puthex_low(unsigned int n);
int		ft_puthex_upper(unsigned int n);

int		ft_putptr(void *ptr);

int		ft_printf(const char *input, ...);

#endif
