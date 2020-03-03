#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientserver.h"
#include <iostream>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include <QString>
#include <vector>
using namespace std;

string finalMsg;
/**
 * @brief Función para administrar los widgets de la interfaz.
 *
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QPixmap pix("/home/julian_camacho/DatosII/TareaExtraclase1/Grafo_base1.png");
    int w = ui->label_4->width();
    int h = ui->label_4->height();
    ui -> label_4 -> setPixmap(pix.scaled(w+65, h+45, Qt::KeepAspectRatio));
}

/**
 * @brief Función para eliminar la ventana principal.
 *
 */
MainWindow::~MainWindow() {
    delete ui;
}


/**
 * @brief Función que controla los eventos del cuando se pulsa el botón de "Calcular Dijkstra".
 *
 */
void MainWindow::on_pushButton_clicked() {
    ClientServer c;
    c.clientSocket(this->nodosACalcular());

}

/**
 * @brief Función que lee los espacios de entrada del usuario para saber cuáles nodos calcular.
 *
 * @return char
 */
string MainWindow::nodosACalcular(){
    QString nodo1 = ui -> lineEdit -> text();
    QString nodo2 = ui -> lineEdit_2 -> text();
    string result = nodo1.toStdString().c_str();
    string result2 = nodo2.toStdString().c_str();
    finalMsg = (result+result2) + finalMsg;
    return finalMsg;
}

/**
 * @brief Función que controla los eventos del cuando se pulsa el botón de "Cargar Grafo".
 *
 * @return string Nombre del archivo seleccionado.
 */
void MainWindow::on_pushButton_2_clicked() {
    QString file_name = QFileDialog::getOpenFileName(this, "Cargar grafo", "");
    cout << file_name.toStdString().c_str() << endl;
    finalMsg += file_name.toStdString().c_str();
    QMessageBox msgBox;
    msgBox.setText("Grafo correctamente cargado");
    msgBox.exec();
}

void MainWindow::displayMessageBox(string msg){
    QString qmsg = QString::fromStdString(msg);
    QMessageBox msgBox2;
    msgBox2.setText(qmsg);
}
