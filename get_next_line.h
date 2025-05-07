/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyamagi < kuyamagi@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:02:05 by kuyamagi          #+#    #+#             */
/*   Updated: 2025/04/30 14:17:30 by kuyamagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*gnl_append(char *stash, const char *buf, size_t rsize);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);

#endif
