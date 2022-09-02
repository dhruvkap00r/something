#include <sys/socket.h>
#include "Req.h"
#include <unistd.h>
#include <thread>
#include <sys/types.h>
#include <map>
#include <iostream>
#include <stdio.h>
#include <string.h>

namespace Web{
void Receive(int sockfd, char buffer[1024]){
    read(sockfd, &buffer, strlen(buffer));

};
void Read_req(){

};
};
