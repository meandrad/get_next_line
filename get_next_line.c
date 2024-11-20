/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:44:32 by meandrad          #+#    #+#             */
/*   Updated: 2024/11/20 14:50:23 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
char	*ft_cut_line(char **buffer)
{
	int		i;
	char	*line;
	char	*rest;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	line = ft_substr(*buffer, 0, i + 1);
	line [i + 2] = '\0';
	if ((*buffer)[i] == '\n')
		rest = ft_strdup(*buffer + i + 1);
	free(*buffer);
	*buffer = rest;
	return (line);
}
char	*ft_read_line(int fd, char **buffer, int *bytes_read)
{
	char	*t_buffer;
	char	*temp;
	
	t_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!t_buffer)
		return (NULL);
	while (1)
	{
		*bytes_read = read(fd, t_buffer, BUFFER_SIZE);
		if (*bytes_read <= 0)
			break ;
		t_buffer[*bytes_read] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(temp, t_buffer);
		free(temp);
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
	free(t_buffer);
	return (*buffer);
}
char	*get_next_line(int fd)
{
	static char	*line;
	int	bytes;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	if (!line)
		line = ft_strdup("");
	line = ft_read_line(fd, &line, &bytes);
	if (bytes == -1 || bytes == '\0' || !*line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = ft_cut_line(&line);
	return (line);
}

#include <fcntl.h> // Para a função open
#include <stdio.h> // Para printf e perror

int	main(void)
{
	int		fd;
	char	*line;

	// Abrindo o arquivo de teste
	fd = open("texto.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}

	// Lendo o arquivo linha por linha
	printf("Conteúdo do arquivo:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // Imprime a linha lida
	}
	free(line); 

	// Fechando o arquivo após a leitura
	close(fd);
	return (0);
}
