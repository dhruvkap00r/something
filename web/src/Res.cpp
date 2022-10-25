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
#include <vector>

#include "includes/File.h"
#include "Header.cpp"
 

std::map<std::string, char*> headers;

void process(char * buffer,int fd){
   File file;
  // std::string fil;
   extractor(buffer);
//   file.file_read(fd, "ind.txt", fil);
//   std::cout<<headers["resource"]<<'\n';
};

int main(){
   char buffer[] = "GET ind.html HTTP/1.0"
                  "MELLO: fdfaf"
                  "fafdf: fdfafd";
   int fd = open("ind.txt", O_RDONLY);
   process(buffer, fd);
   return 0;
};
