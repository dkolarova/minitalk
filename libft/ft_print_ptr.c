/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 07:11:43 by diana             #+#    #+#             */
/*   Updated: 2025/08/13 13:17:57 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(void *ptr, size_t *counter)
{
	char				*str;
	unsigned long		ptr_address;

	ptr_address = (unsigned long)ptr;
	ft_putstr("0x", counter);
	str = ft_extra(ptr_address, HEX_LOWER_BASE);
	ft_putstr(str, counter);
	free(str);
}
