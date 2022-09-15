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
    std::map<volatile int, std::string> status = {
    {200, "OK"},
    {404, "Not Found"}
  };
    volatile int Code = 100;

    std::string Name(){ return status[Code];};
} ;

void file_finder(int fd, char *_file_name){
    struct Status status;
    if (fd < 0){
      status.Code = 404;
      std::cout<<status.Name()<<'\n';
} else{
      status.Code = 200;
      std::cout<<status.Name()<<'\n'<<std::flush;
      File file;
      file.file_read(fd, _file_name);

  };
}

void temp(int fd, char *_file_name){
    file_finder(fd, _file_name);
};
int main(int argc, char** argv){
    int fd = open(argv[1], O_RDONLY);
    check(fd, "fd");
    temp(fd, argv[1]);
    std::cout<<argv[1]<<std::endl;
    return 0;
};
