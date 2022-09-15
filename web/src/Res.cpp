#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "File.h"


void check(int runing_status, std::string program_name){
    if(runing_status < 0){
        std::cout<<"failed "<<program_name<<'\n';
    };
};



struct Status{
    std::map<volatile int, std::string> status = {
    {200, "OK"},
    {404, "Not Found"}
  };
    volatile int Code = 100;

    std::string Name(){ return status[Code];};
} ;

void file_finder(int fd){
    struct Status status;
    if (fd < 0){
      status.Code = 404;
      std::cout<<status.Name()<<'\n';
} else{
      status.Code = 200;
      std::cout<<status.Name()<<'\n';

  };
}

int temp(int fd){

    File file;
    Status status;
    file_finder(fd);
    std::cout<<status.Code<<std::endl;
    if (status.Code = 200){
        file.file_read(fd, argv[1]);
    };
}
int main(int argc, char** argv){
    int fd = open(argv[1], O_RDONLY);
    check(fd, "fd");
    temp(fd);
    std::cout<<argv[1]<<std::endl;
    return 0;
};
