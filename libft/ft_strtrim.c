/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/11 12:42:18 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trim;

	if (!str1)
		return (0);
	start = 0;
	end = ft_strlen(str1);
	if (ft_strlen(str1) == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, str1[start]) && str1[start] != '\0')
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_strchr(set, str1[end - 1]) && end != 0)
		end--;
	trim = ft_substr(str1, start, end - start);
	return (trim);
}
