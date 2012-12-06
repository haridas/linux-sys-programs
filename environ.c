#include<stdio.h>
#include<stdlib.h>

/*
 * Use these functions to access the environment variables.
 *
 * $ export SERVER_NAME="testing.com" # for teseting.
 *
 */

int main()
{

    char* server_name = getenv("SERVER_NAME");

    if(server_name == NULL)
        /* If the SERVER_NAME environment variable was not set. Use
         * the default value. */

        server_name = "server.testing-c.com";

    printf("accessing server %s\n", server_name);

    /* Access the server name */

    return 0;
}
