#include <iostream>
#include <string>
#include <stdlib.h>

std::string ArrayToString(char * buffer){
   const std::string buf = buffer;
   return buf;
};

char * element(char * buffer, int n){
   int count = -1;
   int index = 0;
   auto new_el = [&](){
      if(buffer[index] == ' ' || buffer[index] == '\r\n' || buffer[index] == '\n'){
         return true;}
      else{
         return false;};
   };
   int offset = 0;
   size_t f = index - offset;
   char * buf;
   buf = (char*)malloc(f);
   auto extract = [&](){
      int i = 0;
      for(offset; offset <= index; ++offset){
         buf[i] = buffer[offset];
         ++i;
      };
   };
   while(count < n && index < 100){
      if(new_el()){
         extract();
         ++index;
         ++count;
         offset = index;
      }
      else{
         ++index;
         
      };
   };
   return buf;
   free(buf);
};

void Append(char * buffer, const char * data, int n){
   int i =0;
   for(n; n<=sizeof((*data)+n+1); ++n){
      buffer[n] = data[i];
      ++i;
   };
};


