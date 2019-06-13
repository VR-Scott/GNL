/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dponsonb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:16:07 by dponsonb          #+#    #+#             */
/*   Updated: 2019/06/13 10:47:42 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line;
	int		i;
//	size_t	count  = 1;

	if (argc < 2)
		return (-1);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	i = get_next_line(fd1, &line);
	printf("%s: %s\n",argv[1], line);
	i = get_next_line(fd2, &line);
	printf("%s: %s\n",argv[2], line);
	i = get_next_line(fd1, &line);
	printf("%s: %s\n",argv[1], line);
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
	//	printf("%s", line);
//	}
	return (0);
}
