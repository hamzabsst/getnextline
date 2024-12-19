/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:51:20 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/19 14:40:19 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_reserve(int fd, char *reserve)
{
	char	*buffer;
	ssize_t	byte_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read == -1)
	{
		free (buffer);
		return (-1);
	}
	buffer[byte_read] = '\0';
	reserve = ft_strjoin(buffer, reserve);
	free (buffer);
	return(reserve);
}
char *get_next_line(int fd)
{
	static char	*reserve = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	reserve = ft_reserve(fd, reserve);
	if (!reserve)
		return (NULL);
	
	return (line);
}

int main()
{
	int fd;

	fd = open ("text.txt", O_CREAT | O_RDWR, 0777);
	write(fd, "hamza is him", 12);
	char *line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
