/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/10 14:38:45 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countaraysize(char const *str, char symbol)
{
	int	counter;
	int	result;

	counter = 0;
	result = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] != symbol)
		{
			while (str[counter] != symbol && str[counter] != '\0')
				counter++;
			result++;
		}
		else
			counter++;
	}
	return (result);
}

static char	**ft_deletearray(char **array, size_t len)
{
	while (len > 0)
	{
		len--;
		free(array[len]);
	}
	free(array);
	return (NULL);
}

static char	**ft_createarray(char **array, char const *str, char c)
{
	size_t		i;
	size_t		len;
	size_t		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			len = 0;
			while (str[i + len] != c && str[i + len])
				len++;
			array[j] = ft_substr(str, i, len);
			if (!array[j])
				return (ft_deletearray(array, j));
			j++;
			i += len;
		}
		else
			i++;
	}
	array[j] = 0;
	return (array);
}

char	**ft_split(char const *str, char c)
{
	char		**result;

	if (!str)
		return (NULL);
	result = (char **)malloc((countaraysize(str, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = ft_createarray(result, str, c);
	return (result);
}
