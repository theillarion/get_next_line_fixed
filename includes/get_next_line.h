#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int	main();
char	*get_next_line(int  fd);
void	*ft_calloc(size_t	count, size_t	size);
void	*ft_memset(void	*str, int symbol, size_t len);
char	*ft_strchr(const char	*str, int symbol);
char	*ft_strjoin(const char	*str1, const char	*str2);
char	*ft_substr(const char	*str, unsigned int start, size_t len);
size_t	ft_strlen(const char	*str);

#endif