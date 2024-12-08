/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/11 12:42:37 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlength;
	size_t	surcelength;
	size_t	counter;

	destlength = ft_strlen(dest);
	surcelength = ft_strlen(src);
	counter = 0;
	if (size <= destlength)
		surcelength += size;
	else
		surcelength += destlength;
	while (((destlength + counter) < size - 1) && src[counter] && size)
	{
		dest[destlength + counter] = src[counter];
		counter++;
	}
	dest[destlength + counter] = '\0';
	return (surcelength);
}
