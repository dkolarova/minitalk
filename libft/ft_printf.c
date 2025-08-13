/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:19:31 by diana             #+#    #+#             */
/*   Updated: 2025/08/13 13:15:58 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar(va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstr(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_putptr(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putint(va_arg(va, int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_puthex(va_arg(va, unsigned int), counter, HEX_LOWER_BASE);
		else if (*str == 'X')
			ft_puthex(va_arg(va, unsigned int), counter, HEX_UPPER_BASE);
	}
	else if (*str == '%')
		ft_putchar(*str, counter);
}

int	ft_printf(char const *str, ...)
{
	va_list			va;
	size_t			counter;

	counter = 0;
	if (!str)
		return (0);
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, (char *)str, &counter);
		}
		else
			ft_putchar(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}
/* int	main(void)
{
	int	count;

	count = ft_printf("Hola como esta todo?\n");
	ft_printf("printed chars %d\n", count);
	
	ft_printf("char: %c\n", 'a');
	ft_printf("string: %s\n", "holis tu");
	ft_printf("pointer: %p\n", (void *)0x1234abcd);
	ft_printf("int: %d\n", 30);
	ft_printf("negative int: %d\n", -22);
	ft_printf("hex lowe: %x\n", 255);
	ft_printf("hex upper: %X\n", 233);
	ft_printf("sign: %%\n");
} */
