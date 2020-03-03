#ifndef CLIENTSERVER_H
#define CLIENTSERVER_H
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <QString>
#define PORT 8080
using namespace std;


class ClientServer
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char msg;
    char* hello = &msg;
    char buffer[1024] = {0};

public:
    ClientServer();
    int clientSocket(string msg);
};

#endif // CLIENTSERVER_H
