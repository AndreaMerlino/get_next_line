
#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	*ft_calloc(size_t count, size_t size);
char *get_next_line(int fd);
int	newline(char *s);
int	ft_strlen(const char *s);
char	*ft_substr(char *s, int start, int len);
char  *ft_strlcpy(char *dst,  char *src, int dstsize);
char 	*ft_strlcat(char *dst,  char *src, int dstsize);
#endif
