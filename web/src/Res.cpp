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
#include "includes/File.h"


void check(int runing_status, std::string program_name){
    if(runing_status < 0){
        std::cout<<"failed "<<program_name<<'\n';
    };
};



struct Status{
    std::map<int, std::string> status = {
    {200, "OK"},
    {404, "Not Found"}
  };

    int stat;
   int Code(int fd){
        if(fd > 0){
            stat = 200;
        }
        else{
            stat = 404;
        };
        return stat;
    };           
    int code = Code(-1);

    std::string Name(){ return status[code];};
};


void temp(int fd, char *_file_name){
    Status status;
    File f;
    if(status.Code(fd) == 200){
        f.file_read(fd, _file_name);        
    };
};


int main(int argc, char** argv){
    int fd = open(argv[1], O_RDONLY);
    check(fd, "fd");
    temp(fd, argv[1]);
    std::cout<<argv[1]<<std::endl;
    return 0;
};
