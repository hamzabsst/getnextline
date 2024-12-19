/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:51:20 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/19 12:12:59 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*reserve = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
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
