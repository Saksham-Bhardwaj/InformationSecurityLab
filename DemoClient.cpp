//CLIENT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


int main()
 {
    int s0 = socket(AF_INET, SOCK_STREAM, 0);
    // Fill in the address of server
    struct sockaddr_in peeraddr;
    int peeraddr_len;
    memset(&peeraddr, 0, sizeof(peeraddr));
    char* peerHost = "localhost";
    // Resolve the server address (convert from symbolic name to IP number)
    struct hostent *host = gethostbyname(peerHost);
    peeraddr.sin_family = AF_INET;
    short peerPort = 1111;
    peeraddr.sin_port = htons(peerPort);
    // Connect to a remote server
    int res = connect(s0, (struct sockaddr*) &peeraddr, sizeof(peeraddr));
    printf("Connected. Reading a server message.\n");
    char buffer[1024];
    res = read(s0, buffer, 1024);  
    printf("Received:\n%s", buffer);
    write(s0, "Thanks! Bye-bye...\r\n", 20);
    close(s0);
    return 0;
}
