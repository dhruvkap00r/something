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
#include <string>
#include "includes/File.h"

File::File(){};

int File::file_size_finder(std::string _file_name){
    FILE *fp;
    std::string f;
    fp = fopen(_file_name.c_str(), "r");
    if (fp == nullptr){
        std::cout<<"fopen error!"<<'\n';
    };
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    return size;
};

void File::file_read(int fd, std::string _file_name, std::string container){
   int file_size = file_size_finder(_file_name);
   char *ptr = (char *) mmap(nullptr, file_size, PROT_READ, MAP_SHARED, fd, 0);

#if 0
   for(int i=0;i<file_size+1;i++){
      std::cout<<ptr[i];
   };
#endif
   container = ptr;
   std::cout<<container;
   int mptr = munmap(ptr, file_size);
};


File::~File(){};

