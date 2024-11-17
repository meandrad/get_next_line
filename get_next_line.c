/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:44:32 by meandrad          #+#    #+#             */
/*   Updated: 2024/11/17 16:25:14 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*read_line(int fd)
{
	char	*t_buffer;
	int		bytes_read;
	
	t_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!t_buffer)
		return (NULL);
	bytes_read = read(fd, t_buffer, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	*line;
	int	bytes;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

}
