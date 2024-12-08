/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oleksandr <o.riabenkyi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/08 20:16:46 by Oleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			counter;

	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	counter = 0;
	if ((!dest && !src))
		return (NULL);
	if (destination < source)
	{
		while (counter < length)
		{
			destination[counter] = source[counter];
			counter++;
		}
	}
	else
		while (length--)
			destination[length] = source[length];
	return (dest);
}
