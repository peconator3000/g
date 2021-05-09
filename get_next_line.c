#include "get_next_line.h"
//////////////////#define BUFFER_SIZE 100

int filling(char **line, char **rem)
{
    char *res;
	char *mid;
	char *start;

    mid = *rem;
	while(*mid && *mid != '\n')
		mid++;
    if(*rem)
    {
        free(*rem);
        *rem = NULL;
        *rem = ft_strdup(mid);
    }    
	res = malloc(sizeof(**rem) * (mid - *rem + 1));
	if (!res)
		return (0);
	start = res;
	while(**rem != *mid)
		*(res++) = **(rem++);
    *res = '\0';
    *line = start;
    return (1);
}

int clean_all(char **line, char **rem, int y)
{
    if (y == 0 || y == 1)
        if (!filling(line, rem))
            y = -1;
    if (*rem && y == -1)
	{
        free(*rem);
        *rem = NULL;
    }
    return (y);
}

int get_next_line(int fd, char **line)
{
    int             f;
    char            buf[BUFFER_SIZE + 1];
    int             er;
    static char     *rem;
    

    er = 0;
    if (read(fd, buf, 0) == -1)
        return (-1);
    while(!ft_strchr(rem))
    {
        f = read(fd, buf, BUFFER_SIZE);
        if (!rem)
            rem = ft_strdup(buf);
        else
            ft_strjoin(&rem, buf);
        if (!rem)
            return (clean_all(line, &rem, -1));
    }
    if (f >= 0 && f < BUFFER_SIZE)
        return (clean_all(line, &rem, 0));
    if (!rem)
        return (clean_all(line, &rem, -1));
    return (clean_all(line, &rem, 1));
}
/*
int main(void)
{
    char *line;
	int fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &line) == -1)
	{
		printf("1 = '%s'\n", line);
		free(line);
	}
	printf("0 = '%s'\n", line);
}*/
