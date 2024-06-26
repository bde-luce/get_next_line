/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:12:25 by bde-luce          #+#    #+#             */
/*   Updated: 2024/06/26 13:21:48 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#define BUFFER_SIZE 12

char	*get_buf(int fd, char *rest)
{
	char		*buf;
	int			bytes_rd;
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_rd = 1;
	buf[0] = '\0';
	while (!check_nl(buf) && bytes_rd != 0)
	{
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		//printf("bytes_rd: %d\n", bytes_rd);
		if (bytes_rd == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_rd] = '\0';
		//printf("buf: %s\n", buf);
		rest = join_buf(rest, buf);
		//printf("rest: %s\n", rest);
	}
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = get_buf(fd, rest);
	//printf("rest: %s\n", rest);
	if (!rest)
		return (NULL);
	line = get_line(rest);
	//printf("next_line: %s\n", line);
	rest = get_rest(rest);
	//printf("rest: %s\n", rest);
	return (line);
}

/*int	main(void)
{
	int	fd;

	fd = open("empty.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
*/