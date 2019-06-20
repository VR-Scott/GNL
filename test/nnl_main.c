int	main(void)
{
	char	*filename;
	int		fd;
	int		ret;
	char	*line;
	int		count;

	filename = "nnl.txt"
	fd = open(filename, O_RDONLY);

	if (fd > 2)
	{
		count = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			count++;
			printf("line is:\n%s\nret is:\n%d", line, ret);
			if (count > 50)
				break;
		}
	}
	return (0);
}
