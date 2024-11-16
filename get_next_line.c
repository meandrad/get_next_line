/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:44:32 by meandrad          #+#    #+#             */
/*   Updated: 2024/11/16 17:50:05 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **line)
{
	char	*tmp_buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	
	bytes_read = read(fd, tmp_buffer, BUFFER_SIZE);
	
}
char	*get_next_line(int fd)
{
	static char *line;
	
	if (fd < 0)
		return (0);
	
}


/* #include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 34
int main (void)
{
	int	fd;
	char *buffer;
	ssize_t bytes_read;

	fd = open("test.txt", O_RDONLY || O_CREAT);
	printf("%d\n", fd);
	buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	printf("%s\n", buffer);
} */