#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef FOPEN_MAX
#  define FOPEN_MAX 256
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX FOPEN_MAX
# endif

int		main(void);
char	*get_next_line(int fd);
char	*ft_strchr(const char	*str, int symbol);
char	*ft_strjoin(const char	*str1, const char	*str2);
char	*ft_substr(const char	*str, unsigned int start, size_t len);
size_t	ft_strlen(const char	*str);

#endif