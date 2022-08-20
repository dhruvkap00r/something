#include <sys/socket.h>
#include <sys/socket.h>
#include <string.h>
#include "Web_Server.hpp"
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <sys/types.h>

namespace Web{
void Base::check(int func, std::string name){
    if (func < 0){
        std::cout<<name<<" error!!!!!"<<std::endl;}
    else{
        std::cout<<name<<" working!!!!"<<std::endl;
    };
};
int Base::Configuration(){

    const char *IP = "127.0.0.1";
    //struct sockaddr_in Serv_addr;
    Serv_addr.sin_port = htons(9999);
    Serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, IP, &Serv_addr.sin_addr);
    int Sockfd = socket(AF_INET, SOCK_STREAM, 0);

    check(Sockfd, "Socket");

    return Sockfd;
};

void Base::Send(char Send_buffer[], int New_Sockfd){
    write(New_Sockfd, Send_buffer, strlen(Send_buffer));
};

void Base::Receive(char Recv_buffer[], int New_Sockfd){
    read(New_Sockfd, Recv_buffer, strlen(Recv_buffer));
};
void Base::Main(){
    int addrlen = sizeof(Serv_addr);
    int sock = Configuration();
    check(bind(sock, (sockaddr*)&Serv_addr, sizeof(Serv_addr)), "bind");
    check(listen(sock, 1), "Listening");
    int New_Sockfd = accept(sock, (struct sockaddr*)&Serv_addr, (socklen_t*)&addrlen);
    check(New_Sockfd, "Accept");
    char Send_buffer[2] = "1";
    Send(Send_buffer, New_Sockfd);
    close(sock);
    close(New_Sockfd);
};
};
int main(){
    Web::Base w;
    w.Main();
};
