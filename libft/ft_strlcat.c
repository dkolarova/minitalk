/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:23:07 by dkolarov          #+#    #+#             */
/*   Updated: 2025/05/29 16:25:40 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}

/*  int main(void)
{
    char dest[] = "Hello";
    char src[] = "world!";
    unsigned int result = ft_strlcat(dest, src, 11);

    printf("%s\n", dest);       
    printf("%u\n", result);     

    return 0;
} */ 