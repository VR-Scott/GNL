/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dponsonb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:16:07 by dponsonb          #+#    #+#             */
/*   Updated: 2019/06/11 16:50:25 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
//	size_t	count  = 1;

	if (argc < 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
//	printf("%i\n",fd);
	i = get_next_line(fd, &line);
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
	//	printf("%i\t",i);
		printf("%s", line);
//		if ((count++ % 2) == 0)
//			printf("\n");
//	}
	free(line);
	return (0);
}
