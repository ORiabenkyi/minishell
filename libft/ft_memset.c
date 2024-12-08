/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oleksandr <o.riabenkyi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/08 19:16:05 by Oleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *start, int symbol, size_t length)
{
	unsigned char	*pointer;
	size_t			counter;

	pointer = (unsigned char *) start;
	counter = 0;
	while (counter < length)
		pointer[counter++] = (unsigned char) symbol;
	return (pointer);
}
