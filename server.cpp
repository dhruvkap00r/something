#include <sys/socket.h>
#include <string.h>
#include "server.hpp"
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <sys/types.h>
namespace DKS{
Server::Server(){
    std::cout<<"hello!!!";
}
void Server::configuration(int PORT){
    int Sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (Sockfd < 0){
        std::cout<<"init error"<<std::endl;
    }
    else{
        std::cout<<"init"<<std::endl;
    };

    struct sockaddr_in Server_addr;
    int addrlen = sizeof(Server_addr);
    Server_addr.sin_port = htons(PORT);
    Server_addr.sin_addr.s_addr = INADDR_ANY;
    Server_addr.sin_family = AF_INET;

    if (bind(Sockfd, (struct sockaddr*)&Server_addr, addrlen) < 0){
        std::cout<<"Binding error"<<std::endl;}
    else{
        std::cout<<"Binding"<<std::endl;
    };
    if (listen(Sockfd, 10)){
        std::cout<<"Listening"<<std::endl;
    };

    int New_Sockfd = accept(Sockfd, (struct sockaddr*)&Server_addr, (socklen_t*)&addrlen);

    char Read_Buffer[512];
    //std::string msg;
    char msg[300] ="HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html; charset=UTF-8\r\n\r\n"
    "<!DOCTYPE html><html><head><title>Bye-bye baby bye-bye</title>"
    "<style>body { background-color: #111 }"
    "h1 { font-size:4cm; text-align: center; color: black;"
    " text-shadow: 0 0 2mm red}</style></head>"
    "<body><h1>Goodbye, world!</h1></body></html>\r\n";
    Send(msg, New_Sockfd);

    std::string error;
    error = "recv error";
    int running = 1;
    std::cout<<Read_Buffer;
    try{
        while(running != 0){
            std::thread recv1(Receive, Read_Buffer, New_Sockfd);
            std::cout<<Read_Buffer;
            recv1.join();
        };

        throw(error);
    }
    catch(std::string m){
        std::cout<<m;
        std::thread recv2(Receive, Read_Buffer, New_Sockfd);
    };



    close(New_Sockfd);
    close(Sockfd);
};


void Server::Send(char buffer[], int &New_SockFD){
    send(New_SockFD, buffer, strlen(buffer),0);
};
void Server::Receive(char buffer[512], int New_SockFD){
    int data = read(New_SockFD, buffer, 512);

};
Server::~Server(){
    std::cout<<"bye!!!"<<std::endl;
};
};

int main(){
    std::cout<<"s ";
    DKS::Server serv;
    std::cout<<"m ";
    serv.configuration(9999);
    std::cout<<"end";
    return 0;
};
