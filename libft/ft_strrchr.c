/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2024/10/11 13:08:12 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	char	*copy_str;
	size_t	counter;

	copy_str = NULL;
	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == (char)symbol)
			copy_str = (char *) &str[counter];
		counter++;
	}
	if (str[counter] == (char)symbol)
		copy_str = (char *) &str[counter];
	return (copy_str);
}
