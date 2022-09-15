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

File::File(){};

int File::file_size_finder(char *_file_name){
    FILE *fp;
    fp = fopen(_file_name, "r");
    if (fp == nullptr){
        std::cout<<"fopen error!"<<'\n';
    };
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    return size;
};

void File::file_read(int fd, char *_file_name){
    int file_size = file_size_finder(_file_name);
    char *ptr = (char *) mmap(nullptr, file_size, PROT_READ, MAP_SHARED, fd, 0);

    for(int i=0;i<file_size+1;i++){
        std::cout<<ptr[i];
    };
    int mptr = munmap(ptr, file_size);
};


File::~File(){};
