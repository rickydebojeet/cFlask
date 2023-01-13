#ifndef FUNCTIONS_LIST_H
#define FUNCTIONS_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    char *url;
    void (*function_ptr)(void *, char *);
    int index;

} url;

static void (*function[7])(void *, char *);

#endif