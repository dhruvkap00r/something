#include <sys/socket.h>
#include <iostream>
namespace DKC{
class Client{
public:
    void configuration(int PORT, const char *IP);
    int Process();
    Client();
    ~Client();

private:
    void Send();
    void Recv(int SockFD, char buffer[512]);
    void Send(int SockFD, std::string msg);
};
}
