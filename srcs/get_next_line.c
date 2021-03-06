/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: illarion <illarion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:56:31 by illarion          #+#    #+#             */
/*   Updated: 2022/03/24 01:20:39 by illarion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_smart_free(void	**memory)
{
	if (memory != NULL && *memory != NULL)
	{
		free(*memory);
		*memory = NULL;
	}
}

static char	*ft_read_line(int fd)
{
	char	*line;
	char	*buff;
	char	*backup;
	int		count;

	line = (char *)malloc(sizeof(char));
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	count = read(fd, buff, BUFFER_SIZE);
	if (count != -1)
		buff[count] = '\0';
	while (count > 0)
	{
		backup = line;
		line = ft_strjoin(line, buff);
		ft_smart_free((void *)&backup);
		if (ft_strchr(buff, '\n') != NULL)
			break ;
		count = read(fd, buff, BUFFER_SIZE);
		if (count != -1)
			buff[count] = '\0';
		else
			buff[0] = '\0';
	}
	ft_smart_free((void *)&buff);
	return (line);
}

char	*ft_get_line(char	**line)
{
	char	*result;
	char	*finded_symbol;
	char	*backup;

	if (line == NULL || *line == NULL)
		return (NULL);
	finded_symbol = ft_strchr(*line, (int) '\n');
	if (finded_symbol == NULL || *(finded_symbol + 1) == '\0')
	{
		result = ft_substr(*line, 0, ft_strlen(*line));
		ft_smart_free((void **)line);
	}
	else
	{
		result = ft_substr(*line, 0, (int)(finded_symbol - *line) + 1);
		backup = *line;
		*line = ft_substr(*line, (int)(finded_symbol - *line) + 1,
				ft_strlen(*line) - (int)(finded_symbol - *line) + 1);
		ft_smart_free((void *)&backup);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*backup;
	char		*new_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	else if (line == NULL || *line == '\0')
	{
		line = ft_read_line(fd);
		if (ft_strlen(line) == 0)
			ft_smart_free((void *)&line);
	}
	else if (ft_strchr(line, '\n') == NULL)
	{
		new_line = ft_read_line(fd);
		if (new_line != NULL)
		{
			backup = line;
			line = ft_strjoin(line, new_line);
			ft_smart_free((void *)&backup);
			ft_smart_free((void *)&new_line);
		}
	}
	return (ft_get_line(&line));
}
