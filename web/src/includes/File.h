#include <iostream>
#include <string>
#ifndef FILE_H 
#define FILE_H
class File{
public:
    File();
    int file_size_finder(std::string _file_name);
    void file_read(int fd, std::string _file_name, std::string container);
    ~File();
private:

};
#endif
