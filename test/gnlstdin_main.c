#include <stdio.h>
#include "../get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	char *line;

	printf("GNL returned :%i\n", get_next_line(0, &line));
	printf("line is: %s\n", line);
	return (0);
}
