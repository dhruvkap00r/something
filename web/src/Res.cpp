#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>

struct Status{
    std::map<volatile int, std::string> status = {
    {200, "OK"},
    {404, "Not Found"}
  };
    volatile int Code = 200;

    std::string Name(){ return status[Code];};
} ;


void file_read(FILE *fd){
    char buffer[250];
    fread(buffer, strlen(buffer), 250, fd);
    std::cout<<buffer<<'\n';
};
void file_finder(FILE *fd){
    struct Status status;


    if (fd == nullptr){
        status.Code = 404;
        std::cout<<status.Name()<<'\n';
  } else{
        std::cout<<status.Name()<<'\n';
        file_read(fd);
    };

};



int main(int argc, char** argv){
    FILE *fd;
    fd = fopen(argv[1],"r");
    file_finder(fd);

    std::cout<<argv[1]<<std::endl;
    return 0;
};
