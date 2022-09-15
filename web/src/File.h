#ifndef FILE_H 
#define FILE_H
class File{
public:
    File();
    int file_size_finder(char *_file_name);
    void file_read(int fd, char *_file_name);
    ~File();
private:

};
#endif
