// # ifndef malloc 
// int g_malloc_cnt;
// # include <stdlib.h> 
// # define malloc(x) (g_malloc_cnt++ == MALLOC_COUNT ? ((void*)0) : malloc(x)) 
// # endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif // !BUFFER_SIZE 1

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *str1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif // GET_NEXT_LINE_H
