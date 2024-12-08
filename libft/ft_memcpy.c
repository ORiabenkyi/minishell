/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oleksandr <o.riabenkyi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/08 19:18:40 by Oleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			counter;
	char			*destination;
	const char		*source;

	counter = 0;
	destination = dest;
	source = src;
	if (!dest && !src)
		return (NULL);
	while (counter < n)
	{
		destination[counter] = source[counter];
		counter++;
	}
	return (dest);
}
