#include "civetweb.h"
#include "helper.h"
#include "functionslist.h"

// This function will be called by civetweb on every new request.
static int begin_request_handler(struct mg_connection *conn)
{
    const struct mg_request_info *request_info = mg_get_request_info(conn);
    char content[200];
    int content_length;
    int error = 1;

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(request_info->uri, url_list[i].url) == 0)
        {
            error = 0;
            char *result = malloc(50);
            char *arg = malloc(50);
            if (!request_info->query_string)
            {
                arg = (char *)request_info->query_string;
            }
            else
            {
                arg = strchr((char *)request_info->query_string, '=') + 1;
            }
            result = (*function[url_list[i].index])(arg);
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
    return 1;
}

int main(void)
{
    struct mg_context *ctx;
    struct mg_callbacks callbacks;
    char port[6];
    char num_threads[6];

    printf("Enter port number: ");
    scanf("%s", port);
    printf("Enter number of threads: ");
    scanf("%s", num_threads);

    // List of options. Last element must be NULL.
    const char *options[] = {"listening_ports", port, "num_threads", num_threads, NULL};
    // const char *options[] = {"listening_ports", "8080", "num_threads", "50", NULL};

    // Prepare callbacks structure. We have only one callback, the rest are NULL.
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.begin_request = begin_request_handler;

    // Start the web server.
    ctx = mg_start(&callbacks, NULL, options);
    printf("Server started on port %s with %s threads!\n", port, num_threads);
    printf("Go to http://localhost:%s/ to see it in action.\n", port);
    printf("Enter quit followed by enter stop the server...\n");
    scanf("%*s");

    // Stop the server.
    mg_stop(ctx);

    return 0;
}
