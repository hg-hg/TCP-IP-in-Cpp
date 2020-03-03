#ifndef __SERVER_HPP__
#define __SERVER_HPP__

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFMAX 4096

using namespace std;

class Server
{
public:
    Server(const int port, ofstream &out_file);
    ~Server();
    void run();

private:
    void addressManage();
    void bindManage();
    int po;
    ofstream *os;
    struct sockaddr_in serveraddr;
    int sockfd;
};

// class BindException:public exception
// {
// public:
//     BindException(const string);
//     const char* what()const throw()
//     {

//     }
// };

// BindException::BindException(/* args */)
// {
// }


#endif // !__SERVER_HPP__