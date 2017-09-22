//SERVER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() 
{
    int listenPort = 1111;
    int s0 = socket(AF_INET, SOCK_STREAM, 0);
    // Fill in the address structure containing self address
    struct sockaddr_in myaddr;
    memset(&myaddr, 0, sizeof(struct sockaddr_in));
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(listenPort);        // Port to listen
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // Bind a socket to the address
    int res = bind(s0, (struct sockaddr*) &myaddr, sizeof(myaddr));
    // Set the "LINGER" timeout to zero, to close the listen socket
    // immediately at program termination.
    struct linger linger_opt = { 1, 0 }; // Linger active, timeout 0
    setsockopt(s0, SOL_SOCKET, SO_LINGER, &linger_opt, sizeof(linger_opt));
    res = listen(s0, 1);    // "1" is the maximal length of the queue
    struct sockaddr_in peeraddr;
    socklen_t peeraddr_len;
    int s1 = accept(s0, (struct sockaddr*) &peeraddr, &peeraddr_len);
    res = close(s0);    // Close the listen socket
    write(s1, "Hello!\n", 7);
    char buffer[1024];
    res = read(s1, buffer, 1023);
    buffer[res] = 0;
    printf("Received %d bytes:\n%s", res, buffer);
    close(s1);          // Close the data socket
    return 0;
}
