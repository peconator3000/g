#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *res;
    char *str = "kerberous dank";
    char *tt;
    char *nachalo;

    res = str;
    while(*res != 'd')
        res++;
    tt = malloc(sizeof(*str) * (res - str + 1));
    if (!tt)
        return (0);
    nachalo = tt;
    while(*str != *res)
        *tt++ = *str++;
	*tt = '\0';
}