/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyamagi < kuyamagi@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:02:05 by kuyamagi          #+#    #+#             */
/*   Updated: 2025/04/30 14:25:28 by kuyamagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

static char	*stash_loop(int fd, char *buf, char *stash, size_t *len);
static char	*read_and_stash(int fd, char *stash);
static char	*extract_line(char **stash);
char		*gnl_append(char *stash, const char *buf, size_t cur_len);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}

static char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	size_t	len;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	len = ft_strlen_gnl(stash);
	stash = stash_loop(fd, buf, stash, &len);
	free(buf);
	if (!stash)
		return (NULL);
	return (stash);
}

static char	*stash_loop(int fd, char *buf, char *stash, size_t *len)
{
	ssize_t	r;

	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		buf[r] = '\0';
		stash = gnl_append(stash, buf, *len);
		if (!stash)
			return (NULL);
		*len += (size_t)r;
		if (ft_strchr_gnl(buf, '\n'))
			break ;
		r = read(fd, buf, BUFFER_SIZE);
	}
	if (r < 0)
	{
		free (stash);
		return (NULL);
	}
	return (stash);
}

char	*gnl_append(char *stash, const char *buf, size_t cur_len)
{
	char	*tmp;
	size_t	buf_len;

	buf_len = ft_strlen_gnl(buf);
	tmp = malloc(cur_len + buf_len + 1);
	if (!tmp)
	{
		free(stash);
		return (NULL);
	}
	if (stash)
		ft_memcpy_gnl(tmp, stash, cur_len);
	ft_memcpy_gnl(tmp + cur_len, buf, buf_len);
	tmp[cur_len + buf_len] = '\0';
	free(stash);
	return (tmp);
}

static char	*extract_line(char **stash)
{
	size_t	i;
	char	*line;
	char	*next;

	if (!*stash || **stash == '\0')
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	ft_memcpy_gnl(line, *stash, i);
	line[i] = '\0';
	next = ft_strdup_gnl(*stash + i);
	free(*stash);
	*stash = next;
	return (line);
}
