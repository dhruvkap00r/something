#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct Status{
    std::map<volatile int, std::string> status = {
    {200, "OK"},
    {404, "Not Found"}
  };
    volatile int Code = 200;

    std::string Name(){ return status[Code];};
} ;



void file_read(FILE *fd, int fds){
    void *ptr = mmap(nullptr, 200, PROT_READ, 0, fds, 0);
    char buffer[200];
    std::cout<<ptr<<'\n'<<std::flush;
    read(fds, buffer,0);
    std::cout<<buffer<<'\n';
    int mptr = munmap(ptr, 200);
};


void file_finder(FILE *fd, int fds){
    struct Status status;


    if (fd == nullptr){
        status.Code = 404;
        std::cout<<status.Name()<<'\n';
  } else{
        std::cout<<status.Name()<<'\n';
        file_read(fd, fds);
    };

};
int main(int argc, char** argv){
    FILE *fd;
    fd = fopen(argv[1],"r");
    int fds = open(argv[1], O_RDONLY);
    file_finder(fd, fds);

    std::cout<<argv[1]<<std::endl;
    return 0;
};
