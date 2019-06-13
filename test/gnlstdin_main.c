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

	if (!(fds = (int*)malloc(sizeof(int) * argc)))
		return (-1);
	i = 0;
	while (i <= argc)
	{
		fds[i] = open(argv[i + 1], O_RDONLY);
		printf("%d : %s\n", i, argv[i + 1]);
	}
	printf("-1 : Exit\n");
	
	while (get_next_line(0, &line) > 0 && (i = ft_atoi(line)) > - 1 && i <= argc)
	{
		get_next_line(fds[i], &line);
		printf("%s:\n%s\n",argv[i + 1], line);
	}
	free(fds);
	free(line);
	return (0);
}
