#include "functions.h"

char *basic(char *arg)
{
    return "Hello World!!";
}

char *square(char *arg)
{
    if (!arg)
    {
        return "1";
    }
    else
    {
        int x = atoi(arg);
        x = x * x;
        char *result = malloc(10);
        itoa(x, result);
        return result;
    }
}

char *cube(char *arg)
{
    if (!arg)
    {
        return "1";
    }
    else
    {
        int x = atoi(arg);
        x = x * x * x;
        char *result = malloc(10);
        itoa(x, result);
        return result;
    }
}

char *helloworld(char *arg)
{
    if (!arg)
    {
        return "Hello";
    }
    else
    {
        char *result = malloc(strlen(arg) + 7);
        sprintf(result, "Hello, %s", arg);
        return result;
    }
}

char *pingpong(char *arg)
{
    if (!arg)
    {
        return "PingPong";
    }
    else
    {
        return arg;
    }
}

char *prime(char *arg)
{
    if (!arg)
    {
        return "False";
    }
    else
    {
        int x = atoi(arg);
        int i;
        for (i = 2; i < x; i++)
        {
            if (x % i == 0)
            {
                return "False";
            }
        }
        return "True";
    }
}

char *fibonacci(char *arg)
{
    if (!arg)
    {
        return "1";
    }
    else
    {
        int x = atoi(arg);
        int i;
        int a = 0;
        int b = 1;
        int c;
        for (i = 0; i < x; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        char *result = malloc(10);
        itoa(c, result);
        return result;
    }
}