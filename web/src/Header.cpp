#include <string.h>
#include <iostream>
#include <map>
#include "array.cpp"

enum class State{
   METHOD,
   RESOURCE,
   PROTOCOL,
   H_NAME,
};

std::map<std::string, std::string> head;
void extractor(char * buffer){
   State state = State::METHOD;
   for(int i = 0;i<strlen(buffer);++i){
      switch(state){
         case State::METHOD:
            head["method"] = element(buffer, i);
            std::cout<<"method: "<<head["method"]<<'\n';
            state = State::RESOURCE;
         case State::RESOURCE:
            head["resource"] = element(buffer, i);
            std::cout<<"resource: "<<head["resource"]<<'\n';
            state = State::PROTOCOL;
         case State::PROTOCOL:
            head["protocol"] = element(buffer, i);
            state = State::H_NAME;
         case State::H_NAME:
            int f = 2*i+1;
            head[element(buffer,i)] = element(buffer, f);
            state = State::H_NAME;
      };
   };

};
