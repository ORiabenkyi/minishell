/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/10 15:11:56 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	counter;
	size_t	length;
	char	*str;

	length = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == 0)
		return (str);
	counter = 0;
	while (counter < length)
	{
		str[counter] = (*f)(counter, s[counter]);
		counter++;
	}
	str[counter] = 0;
	return (str);
}
