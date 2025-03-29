#include "../lib/common.h"

/*
set(yolanda_lib log.c sock_ntop.c read.c tcp_server.c tcp_client.c event_loop.c channel.c acceptor.c channel_map.c poll_dispatcher.c thread_pool.c event_loop_thread.c utils.c buffer.c tcp_connection.c http_server.c http_request.c http_response.c )
/Users/zhen/Documents/code/yolanda/lib/CMakeLists.txt(47):  add_library(yolanda ${yolanda_lib} )
/Users/zhen/Documents/code/yolanda/lib/CMakeLists.txt(48):  target_link_libraries(yolanda pthread )
/Users/zhen/Documents/code/yolanda/lib/CMakeLists.txt(50):  install(TARGETS yolanda DESTINATION lib )
/Users/zhen/Documents/code/yolanda/CMakeLists.txt(34):  add_subdirectory(chap-4/ )
/Users/zhen/Documents/code/yolanda/chap-4/CMakeLists.txt(1):  add_executable(make_socket make_socket.c )
/Users/zhen/Documents/code/yolanda/chap-4/CMakeLists.txt(2):  target_link_libraries(make_socket yolanda )
*/

# define MESSAGE_SIZE 102400

void send_data(int sockfd) {
    char *query;
    query = (char*)malloc(MESSAGE_SIZE + 1);
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        query[i] = 'a';
    }
    query[MESSAGE_SIZE] = '\0';

    const char *cp;
    cp = query;
    size_t remaining = strlen(query);
    while (remaining) {
        int n_written = send(sockfd, cp, remaining, 0);
        fprintf(stdout, "send into buffer %ld \n", n_written);
        if (n_written <= 0) {
            error(1, errno, "send failed");
            return;
        }
        remaining -= n_written;
        cp += n_written;
    }

    return;
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2)
        error(1, 0, "usage: tcpclient <IPaddress>");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    int connect_rt = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (connect_rt < 0) {
        // error(1, errno, "connect failed ");
    }
    send_data(sockfd);
    exit(0);
}
