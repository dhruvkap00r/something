#include <sys/socket.h>
#include <thread>
#include "client.hpp"
#include <iostream>
#include <string.h>
#include "server.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>

namespace DKC{
Client::Client(){

};
void Client::configuration(int PORT, const char *IP){
    int Sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (Sockfd < 0){
        std::cout<<"init error"<<std::endl;}
    else {
        std::cout<<"init"<<std::endl;
    };
    struct sockaddr_in Server_addr;
    int addrlen = sizeof(Server_addr);
    inet_pton(AF_INET, IP, &Server_addr.sin_addr);
    Server_addr.sin_port = htons(PORT);
    Server_addr.sin_family = AF_INET;
    if (connect(Sockfd, (sockaddr*)&Server_addr, addrlen) < 0){
        std::cout<<"binding error"<<std::endl;}
    else{
        std::cout<<"binding"<<std::endl;
    };

    char Recv_Buffer[512];
    Recv(Sockfd, Recv_Buffer);
    std::cout<<Recv_Buffer;
    std::string msg;
    std::cin >> msg;
    Send(Sockfd, msg);
};
void Client::Recv(int SockFD, char buffer[512]){
    read(SockFD, buffer, 512);
};
void Client::Send(int SockFD, std::string msg){
    send(SockFD, msg.c_str(), sizeof(msg), 0);
};
Client::~Client(){

};
};
int main(){
    DKC::Client client;
    client.configuration(9999, "127.0.0.1");
    return 0;
};
