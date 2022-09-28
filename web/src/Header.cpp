#include "includes/Header.h"
#include <iostream>
#include <vector>

/*
enum headers{
    User-Agent,
    Host,
    Content-Type,
    Content-Length,
    Accept-Language,
    Accept-Encoding,
    Connection
};
*/

/*
 *how to set position ?
   we have to go through evry single thing like
   method
   file it requested
   protocol type 
   headers

   how to extract headers and save them differently ?
      first: extract name of the header and save it somewhere;
      second: set name as variable and set its value from i to new-line;
   how it will read the text ?
      first it will identify the position where to cut off
      then it will go from the offset to the last line like i;
 * */
//TODO: make a fast method to do extraction thing rather than variables;


Header::Header(){};

void Header::extractor(vector<char> buffer, headers header, m_method method){
   bool is_newline = [&](char* obj){
      if(obj == '\r\n'){return true}
      else {return false};
   };
   bool is_space = [&](char* obj){
      if(obj == " "){return true}
      else {return false};
   };
   int offset = 0;
   int i;
   char current_byte = [&](){
      for(i = 1; i<buffer.size()+1; ++i){
         return buffer[i];
      };
   };
   
   char get_chars = [&](){
      for(int j; j!=i; ++j){
         buffer[j]
      };
   };

   header = h_method;
   switch(header){
      case h_method:
         buffer
         

   };

};



Header::~Header(){};
int main(){
   char buffer[] = "stay aside";
   Header header;
   header.extractor(buffer);
};

