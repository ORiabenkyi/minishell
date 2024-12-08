/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/10 12:33:02 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *where, const char *what, size_t size)
{
	char	*big;
	char	*small;
	size_t	count;
	int		c;

	big = (char *)where;
	small = (char *)what;
	count = 0;
	if (*what == '\0')
		return ((char *)where);
	while (count < size && *(big + count))
	{
		if (*(big + count) == *small)
		{
			c = 0;
			while ((*(big + count + c) == *(small + c)) && (count + c < size))
			{
				c++;
				if (!(*(small + c)))
					return ((big + count));
			}
		}
		count++;
	}
	return (NULL);
}
