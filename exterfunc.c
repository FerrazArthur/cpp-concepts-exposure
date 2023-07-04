#include<stdio.h>
#include<stdlib.h>

extern void eprintf(const char *format, ...) 
__attribute__((format (printf, 1, 2)));

void eprintf(const char*format, ...)
{
    printf(format);
}

int main()
{
    eprintf("B = %d\n", "asd");
    return(0);
}