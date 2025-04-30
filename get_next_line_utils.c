/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurumi <kurumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:59:05 by kuyamagi          #+#    #+#             */
/*   Updated: 2025/04/25 12:53:35 by kurumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup_gnl(const char *s1)
{
	size_t	len = ft_strlen_gnl(s1);
	char	*copy = malloc(len + 1);
	size_t	i = 0;
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len1 = ft_strlen_gnl(s1);
	size_t	len2 = ft_strlen_gnl(s2);
	char	*new_str = malloc(len1 + len2 + 1);
	size_t	i = 0, j = 0;

	if (!new_str)
		return (NULL);
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	size_t	i = 0;

	if (!*stash || **stash == '\0')
		return (NULL);
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = ft_strdup_gnl(*stash);
	line[i] = '\0';
	new_stash = ft_strdup_gnl(*stash + i);
	free(*stash);
	*stash = new_stash;
	return (line);
}
