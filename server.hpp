#include <sys/socket.h>
#include <iostream>
namespace DKS{
class Server{
public:
    Server();
    void configuration(int PORT);
    ~Server();
private:
   static void Send(char buffer[], int &New_SockFD);
    static void Receive(char buffer[512], int New_SockFD);

};

};
