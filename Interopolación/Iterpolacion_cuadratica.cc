#include <iostream>
# include <cmath>

using namespace std;

void funcion(double x0,double y0,double x1,double y1,double x2,double y2,double x){
    
    double b0 = y0;
    double b1 = (y1-y0)/(x1-x0);
    double b2 = ((y2-y1)/(x2-x1) - b1)/(x2-x0);
    std::cout << "b0 = "<<b0 << std::endl;
    std::cout << "b1 = "<<b1 << std::endl;
    std::cout << "b2 = "<<b2 << std::endl;
    //f(x) = a0 + a1x + a2x^2
    double a0 = b0 - b1*x0 + b2*x0*x1;
    double a1 = b1 - b2*x0 - b2*x1;
    double a2 = b2;
    
    
    cout << "y = "<< a0 << " + "<<a1<<"x + "<<a2<<"x^2 "<<endl; 
    
    double y = a0 + a1*x + a2*pow(x,2);
    cout << "valor de y = " << y <<endl;
}

int main(){
    funcion(16,9.870,24,8.418,32,7.305,27); //el último parámetro es el valor de x del cuál queremos el resultado
    
    return 0;
    
}