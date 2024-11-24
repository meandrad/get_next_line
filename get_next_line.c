/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:34:22 by meandrad          #+#    #+#             */
/*   Updated: 2024/11/24 12:27:18 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_buff(char *buff, char *read_buff)
{
	free(read_buff);
	free(buff);
	return (NULL);
}

static char	*ft_read_line(int fd, char	*buff)
{
	char	*read_buff;
	char	*temp_line;
	int		bytes_read;

	bytes_read = 1;
	read_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buff)
		return (NULL);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, read_buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_buff(buff, read_buff));
		read_buff[bytes_read] = '\0';
		temp_line = buff;
		buff = ft_strjoin(temp_line, read_buff);
		free(temp_line);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(read_buff);
	return (buff);
}

static char	*ft_cut_line(char *buff)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	new_line = ft_substr(buff, 0, i + 1);
	return (new_line);
}

static char	*ft_new_line(char *buff)
{
	int		i;
	char	*temp_line;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	temp_line = ft_substr(buff, i + 1, ft_strlen(buff) - 1);
	free(buff);
	return (temp_line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_strdup("");
	buff = ft_read_line(fd, buff);
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	line = ft_cut_line(buff);
	buff = ft_new_line(buff);
	return (line);
}
