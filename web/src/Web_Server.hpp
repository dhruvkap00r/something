#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
namespace Web{
class Base{
public:
    int Configuration();
    void Main();
    void check(int func, std::string name);
    struct sockaddr_in Serv_addr;
protected:
    char Recv_buffer[512];
    char Send_buffer[512];

private:
    void Send(char buffer[], int New_Sockfd);
    void Receive(char buffer[], int New_Sockfd);
    void Read_msg(int New_Sockfd);

};
class Security{
public:
private:
};

};
