/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:02:28 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/15 15:07:54 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*append_buffer_to_line(char *line, char *buffer)
{
	char	*new_line;
	size_t	len;
	size_t	i;

	len = ft_strlen(line) + ft_strlen(buffer);
	new_line = (char *)ft_calloc(len + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, line, ft_strlen(line) + 1);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		new_line[i + ft_strlen(line)] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		new_line[i + ft_strlen(line)] = '\n';
		i++;
	}
	new_line[i + ft_strlen(line)] = '\0';
	free (line);
	line = NULL;
	return (new_line);
}

void	remaining_buffer(char *buffer)
{
	char	*nl_ptr;
	size_t	size;

	nl_ptr = ft_strchr(buffer, '\n');
	if (nl_ptr != NULL)
	{
		size = ft_strlen(nl_ptr + 1) + 1;
		ft_strlcpy(buffer, nl_ptr + 1, size);
	}
	else
		ft_bzero(buffer, BUFFER_SIZE + 1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[4096][BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = (char *)ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	if (buffer[fd][0] != '\0')
		line = append_buffer_to_line(line, &buffer[fd][0]);
	if (!line)
		return (ft_bzero(&buffer[fd][0], BUFFER_SIZE), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(line, '\n') == NULL && line)
	{
		bytes_read = read(fd, &buffer[fd][0], BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), ft_bzero(&buffer[fd][0], BUFFER_SIZE), NULL);
		buffer[fd][bytes_read] = '\0';
		line = append_buffer_to_line(line, &buffer[fd][0]);
	}
	if (*line == '\0')
		return (free(line), ft_bzero(&buffer[fd][0], BUFFER_SIZE), NULL);
	return (remaining_buffer(&buffer[fd][0]), line);
}
