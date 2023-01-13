#include "functions.h"

void basic(void *arg, char *result)
{
    sprintf(result, "Hello World from cflask!");
    return;
}

void square(void *arg, char *result)
{
    if (!arg)
    {
        sprintf(result, "1");
        return;
    }
    else
    {
        int x = *((int *)arg);
        x = x * x;
        sprintf(result, "%d", x);
        return;
    }
}

void cube(void *arg, char *result)
{
    if (!arg)
    {
        sprintf(result, "1");
        return;
    }
    else
    {
        int x = *((int *)arg);
        x = x * x * x;
        sprintf(result, "%d", x);
        return;
    }
}
void helloworld(void *arg, char *result)
{
    if (!arg)
    {
        sprintf(result, "%s", "Hello");
        return;
    }
    else
    {
        sprintf(result, "Hello, %s", (char *)arg);
        return;
    }
}

void pingpong(void *arg, char *result)
{
    if (!arg)
    {
        sprintf(result, "%s", "PingPong");
        return;
    }
    else
    {
        sprintf(result, "%s", (char *)arg);
        return;
    }
}

void prime(void *arg, char *result)
{
    if (!arg)
    {
        sprintf(result, "False");
        return;
    }
    else
    {
        int x = *((int *)arg);
        int i;
        for (i = 2; i < x; i++)
        {
            if (x % i == 0)
            {
                sprintf(result, "False");
                return;
            }
        }
        sprintf(result, "True");
        return;
    }
}

void fibonacci(void *arg, char *result)
{
    if (!arg)
    {
        sprintf(result, "1");
        return;
    }
    else
    {
        int x = *((int *)arg);
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
        sprintf(result, "%d", c);
        return;
    }
}