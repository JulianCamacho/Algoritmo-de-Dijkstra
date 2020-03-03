#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <QFileDialog>
using namespace std;

/**
 * @brief Función principal de la interfaz.
 *
 * @param argc
 * @param argv[]
 * @return int
 */
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

