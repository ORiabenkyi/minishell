/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/11 13:13:33 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *start, int symbol, size_t size)
{
	const unsigned char	*ptr;

	ptr = (unsigned char *)start;
	while (size--)
	{
		if (*ptr == (unsigned char)symbol)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
