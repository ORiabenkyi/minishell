/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/10 13:03:14 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substring;
	size_t	counter;
	size_t	length;

	if (!str)
		return (0);
	if (ft_strlen(str) < (size_t)start)
		return (ft_strdup(""));
	length = ft_strlen(str) - start;
	if (length < len)
		substring = (char *)malloc((length + 1) * sizeof(char));
	else
		substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	counter = 0;
	while (counter < len && str[start + counter])
	{
		substring[counter] = (char)str[counter + start];
		counter++;
	}
	substring[counter] = '\0';
	return (substring);
}
