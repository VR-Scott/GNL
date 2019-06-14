#include <stdio.h>
#include "../get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	char *line;
	int *fds;
	int i;
	int fi;

	if (!(fds = (int*)malloc(sizeof(int) * argc)))
		return (-1);
	i = 0;
	while (i < argc - 1)
	{
		fds[i] = open(argv[i + 1], O_RDONLY);
		printf("%d\t: %s\n", i, argv[i + 1]);
		i++;
	}
	printf("-1\t: Exit\n");
	while (get_next_line(0, &line) > 0 && (i = ft_atoi(line)) > - 1 && i <= argc)
	{
		get_next_line(fds[i], &line);
		printf("%s:\n%s\n",argv[i + 1], line);
		fi = 0;
		while (fi < argc - 1)
		{
			printf("%d\t: %s\n", fi, argv[fi + 1]);
			fi++;
		}
		printf("-1\t: Exit\n");
	}
	i = 0;
	while (i < argc - 1)
	{
		close(fds[i]);
		printf("closing :\t%s\n",argv[i + 1]);
		i++;
	}
	free(fds);
	free(line);
	return (0);
}
