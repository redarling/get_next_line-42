/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:08:58 by asyvash           #+#    #+#             */
/*   Updated: 2023/12/26 14:23:52 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*del_line(char *old_buffer, size_t i)
{
	char	*new_buffer;

	if (!old_buffer[i])
	{
		free(old_buffer);
		return (0);
	}
	new_buffer = malloc(ft_strlen(old_buffer) - i);
	if (!new_buffer)
		return (0);
	ft_strcpy(new_buffer, &old_buffer[i + 1]);
	free(old_buffer);
	return (new_buffer);
}

static char	*get_line(char *buffer, size_t i)
{
	char	*line;
	size_t	j;

	if (!buffer[0])
		return (0);
	line = malloc(i + 2);
	if (!line)
		return (0);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i++] = '\0';
	return (line);
}

static char	*read_file(int fd, char *file_content)
{
	char	*read_buffer;
	int		bytes;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (0);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(read_buffer);
			free(file_content);
			return (0);
		}
		read_buffer[bytes] = '\0';
		file_content = ft_strjoin_free(file_content, read_buffer, bytes);
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (file_content);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1025];
	char		*res_line;
	size_t		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(1);
		if (!buffer[fd])
			return (0);
		buffer[fd][0] = '\0';
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	while (buffer[fd][i] && buffer[fd][i] != '\n')
		i++;
	res_line = get_line(buffer[fd], i);
	buffer[fd] = del_line(buffer[fd], i);
	return (res_line);
}
