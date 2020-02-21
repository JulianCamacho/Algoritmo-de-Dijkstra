#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>

int main(int argc, char *argv[ ]) {
    QApplication app(argc, argv);
    QLabel hello("Ingrese dos nodos para calcular el camino más corto entre ellos");
    hello.setWindowTitle("My First Qt Program");
    hello.resize(400, 400);
    hello.setAlignment(Qt::AlignHCenter);
    hello.show();

    QPushButton button("Calcular Djikstra");
    button.show();

    return app.exec();
}
