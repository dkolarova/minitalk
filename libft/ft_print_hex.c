/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 07:02:35 by diana             #+#    #+#             */
/*   Updated: 2025/08/13 13:18:08 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int num, size_t *counter, char *base)
{
	char	*str;

	str = ft_extra(num, base);
	if (!str)
		return ;
	ft_putstr(str, counter);
	free(str);
}
