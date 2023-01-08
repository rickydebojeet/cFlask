#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "helper.h"

char *basic(char *);
char *square(char *);
char *cube(char *);
char *helloworld(char *);
char *pingpong(char *);
char *prime(char *);
char *fibonacci(char *);

static url url_list[7] = {
    {"/square", "square", 0},
    {"/cube", "cube", 1},
    {"/helloworld", "helloworld", 2},
    {"/pingpong", "pingpong", 3},
    {"/arithmetic/prime", "prime", 4},
    {"/arithmetic/fibonacci", "fibonacci", 5},
    {"/", "basic", 6}};

#endif
