
#if !defined(GET_NEXT_LINE_H)
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#if !defined(BUFFER_SIZE)
#define BUFFER_SIZE 34
#endif

char    *get_next_line(int fd);
char	*ft_strdup(const char *str1);
size_t  ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif // GET_NEXT_LINE_H



