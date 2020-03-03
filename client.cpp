#include "client.hpp"

Client::Client(const string host, const int port, ifstream &in_file)
{
    this->ho = host;
    this->po = port;
    this->is = &in_file;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return;
    }

    if (!addressManage())
    {
        return;
    }

    connectManage();
}

Client::~Client()
{
    delete this->is;
}

bool Client::addressManage()
{
    bzero(&(addr.sin_zero), sizeof(addr.sin_zero));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(po);
    if (inet_pton(AF_INET, ho.c_str(), &addr.sin_addr) <= 0)
    {
        return false;
    }
    return true;
}

void Client::connectManage()
{
    int judge = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (judge < 0)
    {
        string er = "connect error ";
        er += ho;
        er += ":";
        er += po;
        const string coner = er;
        throw coner;
    }
}

void Client::senddata()
{
    int length;
    char *buffer;

    (this->is)->seekg(0, ios::end);
    length = (this->is)->tellg();
    (this->is)->seekg(0, ios::beg);
    buffer = new char[length];
    (this->is)->read(buffer, length);

    write(sockfd, buffer, length);

    close(sockfd);
}