#include <sys/socket.h>
#include <sys/socket.h>
#include <string.h>
#include "server.hpp"
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <sys/types.h>

int main(){
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in Server_addr;
    int addrlen = sizeof(Server_addr);
    Server_addr.sin_port = htons(1222);
    Server_addr.sin_addr.s_addr = INADDR_ANY;
    Server_addr.sin_family = AF_INET;

    bind(s, (struct sockaddr*)&Server_addr, sizeof(Server_addr));
    listen(s, 10);
    int ns = accept(s, (struct sockaddr*)&Server_addr, (socklen_t*)sizeof(Server_addr));

    char msg[300] ="HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html; charset=UTF-8\r\n\r\n"
    "<!DOCTYPE html><html><head><title>Bye-bye baby bye-bye</title>"
    "<style>body { background-color: #111 }"
    "h1 { font-size:4cm; text-align: center; color: black;"
    " text-shadow: 0 0 2mm red}</style></head>"
    "<body><h1>Goodbye, world!</h1></body></html>\r\n";
    char m[3];
    strcat(m, "hello");
    std::cout<<sizeof(msg);
    if(send(ns, m, 3,0) < 0)
        std::cout<<" fail";;
    close(ns);
    close(s);

    return 0;
};
