#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

size_t	ft_strlen(char *str);
int get_next_line(int fd, char **line);
int ft_strjoin(char **s1, char*s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *str);
int	ft_strlcpy(char *dst,char *src, size_t size);

#endif
