#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
/*
char	*ft_strchr(const char	*str, int symbol)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)symbol)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == '\0' && (char)symbol == '\0')
		return ((char *)&str[i]);
	return (NULL);
}*/

int main(void)
{
	/*char	*str;
	char	*symbol;
	int		r;

	str = (char *)malloc(10 * sizeof(char));
	str = "qwertnuio\0";

	symbol = ft_strchr(str, 'n') + 1;

	r = 0;
	r = (int)(symbol - str);

	printf("%s\n%s\n%d\n", str, symbol, r);
*/

	char	*buff;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	buff = get_next_line(fd);
	printf("%s", buff);

	buff = get_next_line(fd);
	//if ()
	printf("%s", buff);
	close(fd);
	return (0);
}
