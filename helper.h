#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    char *url;
    char *function;
    int index;
} url;

void itoa(int n, char s[]);
void reverse(char s[]);

#endif