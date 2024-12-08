/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/10 13:08:40 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char		*s;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	s = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!s)
		return (0);
	while (i < ft_strlen(str1))
	{
		s[i] = str1[i];
		i++;
	}
	while (j < ft_strlen(str2))
	{
		s[i + j] = str2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}
