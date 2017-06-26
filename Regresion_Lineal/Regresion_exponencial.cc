#include <iostream>
#include <cmath>

using namespace std;

void metodoExp(double*todasX,double*todasY,int tamano){
  double sumX= 0.0;
  double sumY = 0.0;
  double sumLny = 0.0; 
  double sumXlnY = 0.0;
  double sumXC = 0.0;
  
  for(int i=0;i<tamano;i++){
    sumX += todasX[i];
    sumY += todasY[i];
    sumLny += log(todasY[i]);
    sumXlnY += todasX[i] * log(todasY[i]);
    sumXC += pow(todasX[i],2);
  }
  
  double mediaX = sumX/tamano;
  double mediaY = sumY/tamano;
  double mediaLnY = sumLny/tamano;
  
  double a1 = (tamano * sumXlnY - sumX * sumLny) / (tamano * sumXC - pow(sumX, 2));
  double a0 = mediaLnY - a1 * mediaX;
  
  cout << "\nEcuación Exponencial" << endl;
  cout << "y = " << exp(a0) << "e^" << a1 << "x" << endl;
  
  double st = 0.0, sr = 0.0;
  for (int i = 0; i < tamano; i++) {
    sr += pow(todasY[i] - exp(a0) * exp(a1 * todasX[i]), 2);
    st += pow(todasY[i] - mediaY, 2);
  }

  // Error estandar
  double serr = sqrt(sr / (tamano - 2));
  cout << "STANDARD ERROR" << endl;
  cout << serr << endl;
  // Coeficiente de determinación
  double r = sqrt((st - sr) / st);
  cout << "CORRELATION COEFFICIENT" << endl;
  cout << r << endl;
  cout << "DETERMINATION COEFFICIENT" << endl;
  cout << pow(r, 2) << endl;
  
}

int main(int argc, char *argv[]) {
    double todasX[] = {1,2,3,4,5};
    double todasY[] = {0.5,1.7,3.4,5.7,8.4};
    int tamano = sizeof(todasX)/sizeof(double);
    //metodoExp(todasX,todasY,tamano);
    metodoExp(todasX,todasY,tamano);

  return 0;
}