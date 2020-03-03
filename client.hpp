#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
using namespace std;

#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFMAX 4096

class Client {
public:
    Client(const string host, const int port, ifstream &in_file);
    ~Client();
    void senddata();

private:
    bool addressManage();
    void connectManage();
    string ho;
    int po;
    ifstream *is;
    struct sockaddr_in addr;
    int sockfd;
};

#endif // !__CLIENT_HPP__
