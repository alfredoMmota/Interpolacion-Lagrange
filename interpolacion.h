#ifndef INTERPOLACION_H
#define INTERPOLACION_H

#include <QMainWindow>

namespace Ui {
class interpolacion;
}

class interpolacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit interpolacion(QWidget *parent = 0);
    ~interpolacion();
    double x[5][2];//creacion de la matriz para el calculo del metodo
                   //creation of the matrix for the calculation of the method

private slots:
    void Metodo();//declaracion de los metodos que se utilizaran
                  //declaration of the methods to be used
    void Borrar();
    void Habilitar();
private:
    Ui::interpolacion *ui;
};

#endif // INTERPOLACION_H
