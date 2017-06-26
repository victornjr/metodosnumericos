#include <iostream>
#include <cmath>
using namespace std;

double df(double x){    //derivada de la función
  return 1/(pow(x,2)-1.1);
}

double salto = 0.25;   //esta es la h
void euler(double x0,double y0,double xDeseada){
  double y1;
  while(x0<xDeseada){
    cout << "x:" << x0 << " y:" << y0 << endl;
    y1 = y0 + (df(x0)*salto);
    x0 += salto;
    y0 = y1;
  }
  cout << "\ny at " << xDeseada << ": " << y0 << endl;
}



void punto_medio(double x0,double y0,double xDeseada){
  double y1;
  while(x0<xDeseada){
      cout << "x:" << x0 << " -> y:" << y0 << endl;
      y1 = y0 + (df(x0)*salto);
      x0 += salto;
      y0 = y1;
  }
  cout << "\ny at " << xDeseada << ": " << y0 << endl;
}


int main(){
  punto_medio(0,1,2); 
  return 0;
}
