#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <boolstd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif



int	main();
char	*get_next_line(int  fd);

#endif