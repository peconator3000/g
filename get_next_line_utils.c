#include "get_next_line.h"

int ft_strjoin(char**s1, char *s2)
{
	char			*res;
	char			*start;
    char            *mid1;
    char            *mid2;

	mid1 = *s1;
    mid2 = s2;
    while(*mid1)
        mid1++;
    while(*mid2)
        mid2++;
	res = malloc(sizeof(*res) * (mid1 - *s1 + mid2 - s2 + 1));
    mid1 = *s1;
    if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (!res)
		return (0);
	start = res;
	while (*mid1)
		*res++ = *mid1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
    *s1 = start;
	return (1);
}

// int	ft_strlcpy(char *dst, char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!dst && !src && !size)
// 		return (0);
// 	while (src[i] && i < (size) - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (1);
// }

char	*ft_strdup( char *s1)
{
	char	*res;
	char	*start;
	char	*mid;

	if (!s1)
		return (NULL);
    mid = s1;
	while(*mid)
		mid++;
	res = malloc(sizeof(char) * (mid - s1 + 1));
	start = res;
    if (!res)
        return (NULL);
	while (*s1)
		*res++ = *s1++;
	*res = '\0';
	return (start);
}

char	*ft_strchr(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (ft_strdup(str));
		str++;
	}
	return (NULL);
}