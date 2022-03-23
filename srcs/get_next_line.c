#include "get_next_line.h"

static char	*ft_read_line(int fd)
{
	char	*line;
	char	*buff;
	char	*backup;
	int		count;

	line = (char *)ft_calloc(1, sizeof(char));
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	count = read(fd, buff, BUFFER_SIZE);
	buff[count] = '\0';
	backup = line;
	line = ft_strjoin(line, buff);
	free(backup);
	while (count == BUFFER_SIZE && ft_strchr(buff, '\n') == NULL)
	{
		backup = line;
		line = ft_strjoin(line, buff);
		free(backup);
		count = read(fd, buff, BUFFER_SIZE);
		buff[count] = '\0';
	}
	free(buff);
	return (line);
}

char	*ft_get_line(char	**line)
{
	char	*result;
	char	*finded_symbol;
	char	*backup;
	if (line == NULL || *line == NULL)
		return (NULL);
	finded_symbol = ft_strchr(*line, (int)'\n');
	if (finded_symbol == NULL)
	{
		result = ft_substr(*line, 0, ft_strlen(*line));
		free(*line);
		*line = NULL;
	}
	else
	{
		result = ft_substr(*line, 0, (int)(finded_symbol - *line) + 1);
		if (*(finded_symbol + 1) == '\0')
		{
			free(*line);
			*line = NULL;
		}
		else
		{
			backup = *line;
			*line = ft_substr(*line, *(finded_symbol + 1), ft_strlen(*line) - *(finded_symbol + 1));
			free(backup);
		}
	}
	return (result);
}
// 0 1 2 3 4  5
// 0 0 0 f n \0
// 

char	*get_next_line(int fd)
{
	static char	*line;
	//char		*symbol;
	//char		*buff;

	if (BUFFER_SIZE <= 0 || fd < 0)
	    return (NULL);
    else if (line == NULL || *line == '\0')
    {
		line = ft_read_line(fd);
		if (ft_strlen(line) == 0)
		{
			free(line);
			line = NULL;
		}
    }
	/*else
	{
		symbol = ft_strchr(line, (int)'\n');
		if (symbol == NULL)
			return (line);
		else
		{
			buff = ft_substr(line, 0, (int)(symbol - line) + 1);
			line = symbol + 1;
			return (buff);
		}
	}*/
    return (ft_get_line(&line));
}
