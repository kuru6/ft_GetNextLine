/* ************************************************************************** */
/*                                                                            */
/*                            :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tester <tester@student.42.tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:30:00 by tester            #+#    #+#             */
/*   Updated: 2025/04/25 12:30:00 by tester           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	size_t	line_no;

	if (argc != 2)
	{
		printf("Usage: %s <file_path>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	line_no = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%zu: %s", line_no++, line);
		free(line);
	}
	close(fd);
	return (0);
}
