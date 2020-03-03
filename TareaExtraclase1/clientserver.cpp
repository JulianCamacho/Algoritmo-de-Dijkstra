#include "clientserver.h"
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <QMessageBox>
#define PORT 8080
using namespace std;

int sock = 0, valread; /**< TODO: describe */
struct sockaddr_in serv_addr; /**< TODO: describe */
char msg; /**< TODO: describe */
char* hello = &msg; /**< TODO: describe */
char buffer[1024] = {0}; /**< TODO: describe */

/**
 * @brief Constructor para instanciar la clase cliente.
 *
 */
ClientServer::ClientServer(){}


/**
 * @brief Función para correr el socket de cliente.
 *
 * @param newMsg Mensaje que se desea transmitir a través del socket.
 * @return int
 */
int ClientServer::clientSocket(string newMsg){
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    char char_array[newMsg.size() + 1];
    strcpy(char_array, newMsg.c_str());
    send(sock , char_array , strlen(char_array) , 0 );
    printf("%s\n",char_array );

    valread = read( sock , buffer, 1024);
    string text;
    for (int i = 0; i < sizeof(buffer); i++){
        text += buffer[i];
    }
    QString qtext = QString::fromStdString(text);
    QMessageBox msgBox;
    msgBox.setText("El camino más corto entre los nodos es: \n" + qtext);
    msgBox.exec();


    printf("%s\n",buffer );
    return 0;
}
