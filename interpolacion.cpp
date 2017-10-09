//Programa del Metodo Interpolacion de Lagrange version 1.0
#include "interpolacion.h"
#include "ui_interpolacion.h"

interpolacion::interpolacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::interpolacion)
{
    ui->setupUi(this);//conexiones del programa con la interfaz
                      //program connections with the interface
    connect(ui->calcular,SIGNAL(clicked()),this,SLOT(Metodo()));
    connect(ui->borrar,SIGNAL(clicked()),this,SLOT(Borrar()));
    connect(ui->x,SIGNAL(valueChanged(double)),this,SLOT(Habilitar()));
}

interpolacion::~interpolacion()
{
    delete ui;
}
void interpolacion::Habilitar(){//declaracion del metodo Habilitar
                                //method declaration Enable
    double X=ui->x->value();//se guarda el valor del spinbox en la variable X
                            //save the value of the spinbox in the variable X
    QString resultado;//se declara una variable de tipo cadena
                      //a string-type variable is declared
    if(X!=0){//se declara la condicion para habilitar el boton calcular
             //declare the condition to enable the calculate button
        ui->calcular->setEnabled(true);
    }
    else
        resultado.append("Falta agregar el valor de X");//se imprime un mensaje si no se cumple la condicion
    ui->Resultado->setText(resultado);//se visualiza el mensaje en la interfaz
                                      //the message is displayed on the interface
}

void interpolacion::Metodo(){//se inicializa el codigo para la solucion del metodo
                             //initialize the code for the solution of the method

    QString resultado,valor1,valor2,valor3,valor4;//se declaran variables de tipo cadena
                                                  //string type variables are declared
    double polinomio,formula;//se declaran variables de tipo double
                             //double variables are declared
    x[0][0]=ui->X0->value();//se llena la matriz con los valores de los double spinbox de la interfaz
                            //the matrix is ​​filled with the values ​​of the double spinbox of the interface
    x[1][0]=ui->X1->value();
    x[2][0]=ui->X2->value();
    x[3][0]=ui->X3->value();
    x[4][0]=ui->X4->value();
    x[0][1]=ui->fx0->value();
    x[1][1]=ui->fx1->value();
    x[2][1]=ui->fx2->value();
    x[3][1]=ui->fx3->value();
    x[4][1]=ui->fx4->value();
    double X=ui->x->value();//se asigna el valor de la incognita
                            //is assigned the value of incognita
    int n=5,i,j,k;
    double lagrange[n];//se declara un vector del tamaño de n
                       //a vector of the size of n
    for(k=1;k<n;k++){//inicial el primer ciclo para el orden del polinomio
                     //initial the first cycle for the order of the polynomial
        polinomio=0;
        for(i=0;i<k+1;i++){//se crea el ciclo para el calculo de la formula del metodo
                           //the cycle is created for the calculation of the formula of the method
            formula=1;
            for(j=0;j<k+1;j++){
                if(i!=j){
                 formula=formula*((X-x[j][0])/(x[i][0]-x[j][0]));//se define los valores que tomara la formula
                                                                 //the values ​​that the formula
                }                
            }
            formula=formula*x[i][1];//se multiplica el resultado de la formula por el valor de F(x)
                                    //multiply the result of the formula by the value of F (x)
            polinomio=polinomio+formula;//se agrega el valor del polinomio
                                        //the value of the polynomial is added
        }        
        lagrange[k]=polinomio;//se guarda el polinomio en el vector lagrange
                              //the polynomial is stored in the lagrange vector
    }
    //se guarda el mensaje y las variables que se visualizaran en la interfaz
    //the message and the variables that are displayed in the interface are saved
   resultado.append("Los valores de la interpolacion de lagrange para F(x)=2 son: ").append("\nPrimera aproximacion= ").append(valor1.setNum(lagrange[1])).append("\nSegunda Aproximacion= ").append(valor2.setNum(lagrange[2]))
           .append("\nTercera aproximacion= ").append(valor3.setNum(lagrange[3])).append("\nCuarta Aproximacion= ").append(valor4.setNum(lagrange[4]));
   ui->Resultado->setText(resultado);//se visualiza en valor del String resultado en la interfaz
                                     //is displayed in value of the result String in the interface
}
void interpolacion::Borrar(){//se declara el metodo borrar
                             //declare the method to delete
    ui->X0->setValue(0.0);//se regresan todos los spinbox a 0
                          //all spinbox returns to 0
    ui->X1->setValue(0.0);
    ui->X2->setValue(0.0);
    ui->X3->setValue(0.0);
    ui->X4->setValue(0.0);
    ui->fx0->setValue(0.0);
    ui->fx1->setValue(0.0);
    ui->fx2->setValue(0.0);
    ui->fx3->setValue(0.0);
    ui->fx4->setValue(0.0);
    ui->x->setValue(0.0);
    ui->Resultado->clear();//se limpia el label Resultado
                           //the label Result is cleared
    ui->calcular->setEnabled(false);//se deshabilita el boton calcular
                                    //the calculate button is disabled
}
//elaborado por Jose Alfredo Mendoza Mota, Ana karen Razo Francisco, Gibran Omar Estrada Gomez, Antonio de Jesus Herrera Diaz
