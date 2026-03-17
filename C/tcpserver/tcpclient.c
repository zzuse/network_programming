#include "../lib/common.h"

#define MESSAGE_SIZE 10240000

void send_data(int sockfd)
{
    char *query;
    query = (char *)malloc(MESSAGE_SIZE + 1);
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        query[i] = 'a';
    }
    query[MESSAGE_SIZE] = '\0';

    const char *cp;
    cp = query;
    size_t remaining = strlen(query);
    while (remaining) {
        /*
        The %zd format specifier in C is used within functions like printf or fprintf to properly format and print
        variables of the type ssize_t (signed size type).

        Here is a breakdown of what that means:

        z (Length Modifier): This tells the formatting function that the variable is sized according to size_t (or its
        signed counterpart, ssize_t). d (Conversion Specifier): This stands for decimal and indicates that the value
        should be printed as a signed base-10 integer. Why use %zd instead of %d or %ld? Functions like

        send()
        or

        read()
        in POSIX systems return an ssize_t instead of a standard int.

        size_t is an unsigned type used to represent sizes and counts (like the length of an array). It is guaranteed to
        be big enough to hold the size of the largest possible object on your system. ssize_t is exactly the same size
        as size_t, but it is signed (it can be negative). This is crucial because functions like

        send()
        need to return a positive number for the amount of bytes sent, but they also need a way to return -1 to indicate
        an error. The actual size in bytes of ssize_t depends on your system's architecture:

        On a 32-bit system, ssize_t is usually 32 bits (like an int).
        On a 64-bit system (like your Mac), ssize_t is 64 bits (like a long).
        If you use %d (which expects a standard 32-bit int) or %ld (which expects a long), you might run into
        type-mismatch warnings because the compiler knows the size of ssize_t might not exactly match int or long across
        all platforms.

        By using %zd, you are telling the compiler, "Whatever size ssize_t happens to be on this machine, format it as a
        signed integer of exactly that size." This makes your code robust and completely cross-platform!

        (Note: If you were printing a standard size_t which can't be negative, you would use %zu instead).

        */
        ssize_t n_written = send(sockfd, cp, remaining, 0);
        fprintf(stdout, "send into buffer %zd \n", n_written);
        if (n_written <= 0) {
            error(1, errno, "send failed");
            return;
        }
        remaining -= n_written;
        cp += n_written;
    }

    return;
}

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2) error(1, 0, "usage: tcpclient <IPaddress>");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    int connect_rt = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (connect_rt < 0) {
        error(1, errno, "connect failed ");
    }
    send_data(sockfd);
    exit(0);
}
