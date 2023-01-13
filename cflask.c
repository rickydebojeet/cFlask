#include "civetweb.h"
#include "functionslist.h"

// This function will be called by civetweb on every new request.
static int begin_request_handler(struct mg_connection *conn)
{
    const struct mg_request_info *request_info = mg_get_request_info(conn);
    char content[200];
    char arg[100] = {'\0'};
    char *result = malloc(100);
    int arg_length, content_length, error = 1;
    int num;

    for (int i = 0; i < FUNCTION_COUNT; i++)
    {
        if (!strcmp(request_info->uri, url_list[i].url))
        {
            error = 0;
            if (!request_info->query_string)
            {
                (*function[url_list[i].index])((void *)0, result);
            }
            else if (mg_get_var(request_info->query_string, strlen(request_info->query_string), "num", arg, sizeof(arg)) >= 1)
            {
                num = atoi(arg);
                (*function[url_list[i].index])((void *)&num, result);
            }
            else if (mg_get_var(request_info->query_string, strlen(request_info->query_string), "str", arg, sizeof(arg)) >= 1)
            {
                (*function[url_list[i].index])((void *)&arg, result);
            }
            else
            {
                sprintf(result, "Wrong Query String\nPlease use ?num= for number or ?str= for string");
            }

            content_length = snprintf(content, sizeof(content), "%s", result);
            mg_printf(conn,
                      "HTTP/1.1 200 OK\r\n"
                      "Content-Type: text/plain\r\n"
                      "Content-Length: %d\r\n" // Always set Content-Length
                      "\r\n"
                      "%s",
                      content_length, content);
        }
    }

    if (error == 1)
    {
        int content_length = snprintf(content, sizeof(content), "Error 404: Page not found");
        mg_printf(conn,
                  "HTTP/1.1 404 Not Found\r\n"
                  "Content-Type: text/plain\r\n"
                  "Content-Length: %d\r\n" // Always set Content-Length
                  "\r\n"
                  "%s",
                  content_length, content);
    }
    free(result);
    // Returning non-zero tells civetweb that our function has replied to
    // the client, and civetweb should not send client any more data.
    return 1;
}

// void constructFunctionsList()
// {
//     for (int i = 0; i < FUNCTION_COUNT; i++)
//     {
//         function[url_list[i].index] = url_list[i].function;
//     }
// }

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./cflask <port> <num_threads>\n");
        exit(1);
    }
    else if (atoi(argv[1]) < 1024 || atoi(argv[1]) > 65535)
    {
        printf("Port number must be between 1024 and 65535\n");
        exit(1);
    }
    else if (atoi(argv[2]) < 1 || atoi(argv[2]) > 10000)
    {
        printf("Number of threads must be between 1 and 10000\n");
        exit(1);
    }

    struct mg_context *ctx;
    struct mg_callbacks callbacks;

    // List of options for the server. Last element must be NULL.
    const char *options[] = {"listening_ports", argv[1], "num_threads", argv[2], NULL};

    // Prepare callbacks structure. We have only one callback, the rest are NULL.
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.begin_request = begin_request_handler;

    // Start the web server with the given options and callbacks structure.
    ctx = mg_start(&callbacks, NULL, options);
    printf("Server started on port %s with %s threads!\n", argv[1], argv[2]);
    printf("Go to http://localhost:%s/ to see it in action.\n", argv[1]);
    printf("Press enter to stop the server...\n");
    getchar();

    // Stop the server.
    mg_stop(ctx);

    return 0;
}
