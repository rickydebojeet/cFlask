#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define FUNCTION_COUNT 7

#include "helper.h"

void basic(void *, char *);
void square(void *, char *);
void cube(void *, char *);
void helloworld(void *, char *);
void pingpong(void *, char *);
void prime(void *, char *);
void fibonacci(void *, char *);

static url url_list[7] = {
    {"/square", "square", 0},
    {"/cube", "cube", 1},
    {"/helloworld", "helloworld", 2},
    {"/pingpong", "pingpong", 3},
    {"/arithmetic/prime", "prime", 4},
    {"/arithmetic/fibonacci", "fibonacci", 5},
    {"/", "basic", 6}};

#endif
