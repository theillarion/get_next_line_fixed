#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int	main(void)
{
	char	*buff;
	int		fd;

	fd = open("testers/gnlTester/files/multiple_line_no_nl", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	buff = get_next_line(fd);
	while (buff != NULL)
	{
		printf("S: %s", buff);
		free(buff);
		buff = get_next_line(fd);
	}
	close(fd);
	return (0);
}
