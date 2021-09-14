#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 255

void error_macro(const char *error)
{
    perror(error);
    exit(1);
}

int main(void)
{
    char *ptr = NULL;
    int socket_fd = 0;
    char buf[BUF_SIZE] = {0};
    struct sockaddr_in client = {0};
    socklen_t client_socket_fd_size = 0;


    socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if (socket_fd == -1)
    {
        error_macro("SOCKET CREATE");
    }

    client_socket_fd_size = sizeof(struct sockaddr_in);

    do
    {
        if (recvfrom(socket_fd, buf, BUF_SIZE, 0, (struct sockaddr *)&client,
            &client_socket_fd_size) == -1)
        {
            error_macro("RECVFROM ERROR");
        }
        ptr = buf;
        ptr += 28;
        printf("%s\n", ptr);
    } while (strncmp(ptr, "exit", 255) != 0);

    return 0;
}
