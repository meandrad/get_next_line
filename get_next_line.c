/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:44:32 by meandrad          #+#    #+#             */
/*   Updated: 2024/11/17 14:00:54 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*read_line(int fd, int *bytes)
{
	char	*t_buffer;
	
	t_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!t_buffer)
		return (NULL);
	*bytes = read(fd, t_buffer, BUFFER_SIZE);
	if (*bytes < 0)
		//break ;
}

char	*get_next_line(int fd)
{
	static char	*line;
	int	bytes;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	line = read_line(fd, &bytes);
	
}
