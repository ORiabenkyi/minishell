/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:00:40 by oriabenk          #+#    #+#             */
/*   Updated: 2024/11/10 15:42:17 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

static char	*take_line(int fd, char *str, char *buffer_string)
{
	ssize_t	quantyti;
	char	*temp_string;

	quantyti = 1;
	while (quantyti != 0)
	{
		quantyti = read(fd, str, BUFFER_SIZE);
		if (quantyti == -1)
			return (0);
		else if (quantyti == 0)
			break ;
		str[quantyti] = '\0';
		if (!buffer_string)
			buffer_string = ft_strdup("");
		temp_string = buffer_string;
		buffer_string = ft_strjoin(temp_string, str);
		free(temp_string);
		temp_string = NULL;
		if (ft_strchr (str, '\n'))
			break ;
	}
	return (buffer_string);
}

static char	*line_to_buffer(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*buffer_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = take_line(fd, buf, buffer_string);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(buffer_string);
		buffer_string = NULL;
		return (NULL);
	}
	buffer_string = line_to_buffer(line);
	return (line);
}
