#include "server.hpp"

Server::Server(const int port, ofstream &out_file)
{
    this->po = port;
    this->os = &out_file;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        return;
    }

    addressManage();

    bindManage();
}

Server::~Server()
{
    delete this->os;
}

void Server::addressManage()
{
    bzero(&(serveraddr.sin_zero),sizeof(serveraddr.sin_zero));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(po);
    serveraddr.sin_addr.s_addr = inet_addr("0.0.0.0");
}

void Server::bindManage()
{
    int judge = bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (judge == -1)
    {
        string er = "bind error ";
        er += this->po;
        const string coner = er;
        throw coner;
    }
}

void Server::run()
{
    if (listen(sockfd, 10) == -1)
    {
        return;
    }

    struct sockaddr_in clientaddr;
    socklen_t size = sizeof(clientaddr);
    int connfd = accept(sockfd, (struct sockaddr *)&clientaddr, &size);

    char buff[BUFFMAX];
    int judge = read(connfd, buff, BUFFMAX);

    while (judge != 0)
    {
        string str = buff;
        *(this-> os) << str;
        judge = read(connfd, buff, BUFFMAX);
    }

    close(connfd);
    close(sockfd);
}