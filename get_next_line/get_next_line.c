/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewonki <taewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:10:26 by taewonki          #+#    #+#             */
/*   Updated: 2025/06/04 08:39:09 by taewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *stash)
{
	char	*line;
	char	*temp;
	size_t	len;
	size_t	i;

	temp = ft_strchr(stash, '\n');
	if (temp != NULL)
		len = (temp - stash) + 1;
	else
		len = ft_strlen(stash);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static int	trimming_static(char **stash, char *line)
{
	char	*temp;
	size_t	line_len;
	size_t	stash_len;

	if (!stash || !*stash || !line)
		return (0);
	temp = *stash;
	line_len = ft_strlen(line);
	stash_len = ft_strlen(*stash);
	*stash = ft_substr(*stash, line_len, stash_len - line_len);
	free(temp);
	if (!*stash)
		return (0);
	return (1);
}

static void	free_all(char **stash, char **line)
{
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	if (line && *line)
		free(*line);
}

static int	save_static(int fd, char **stash, char *buf)
{
	int		read_byte;
	char	*temp;

	read_byte = 1;
	if (*stash == NULL)
	{
		*stash = ft_strdup("");
		if (!*stash)
			return (-1);
	}
	while (!ft_strchr(*stash, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte < 0)
			return (-1);
		buf[read_byte] = '\0';
		temp = *stash;
		*stash = ft_strjoin(*stash, buf);
		free(temp);
		if (!*stash)
			return (-1);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int			read_byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_byte = save_static(fd, &stash, buf);
	free(buf);
	if (read_byte == -1 || !stash || *stash == '\0')
	{
		free_all(&stash, NULL);
		return (NULL);
	}
	line = extract_line(stash);
	if (trimming_static(&stash, line) == 0)
	{
		free_all(&stash, &line);
		return (NULL);
	}
	return (line);
}
