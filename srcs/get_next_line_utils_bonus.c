#include "get_next_line_bonus.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
}

static size_t	ft_strlen_safe(const char	*str)
{
	size_t	i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(const char	*str, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_str;
	size_t	size;

	if (str == NULL)
		return (NULL);
	size = len;
	if (start >= ft_strlen(str))
		size = 0;
	if (len > ft_strlen(str) - start)
		size = ft_strlen(str) - start;
	new_str = (char *)malloc((size + 1) * sizeof(char));
	if (new_str == NULL)
		return (new_str);
	i = 0;
	if (start < ft_strlen(str))
	{
		while (i < len && str[start + i])
		{
			new_str[i] = str[i + start];
			i++;
		}
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(const char	*str1, const char	*str2)
{
	size_t	i;
	size_t	length_str1;
	size_t	length_str2;
	char	*new_str;

	length_str1 = ft_strlen_safe(str1);
	length_str2 = ft_strlen_safe(str2);
	if ((str1 == NULL && str2 == NULL))
		return (NULL);
	new_str = (char *)malloc((length_str1 + length_str2 + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < length_str1 && str1[i])
	{
		new_str[i] = str1[i];
		i++;
	}
	while (i < length_str1 + length_str2 && str2[i - length_str1])
	{
		new_str[i] = str2[i - length_str1];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
