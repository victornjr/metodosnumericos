#include <iostream>
#include <cmath>

double funcion(double x){ 
    return x+2;    //Aqui va la funcion 
}

double reglaTrapecio(int noX,double a, double b){
    double base = b-a;
    double baseDiv = base/noX;
    
    double sumaX = a;
    double sumatoria = 0;
    for(int i=1;i<noX;i++){
        sumaX += baseDiv;
        sumatoria += funcion(sumaX);
        //std::cout << sumatoria << std::endl;
    }
    
    double area = (b-a)*((funcion(a) + 2*sumatoria + funcion(b))/(2*noX));
    
    return area;
}

//---REGLA DE SIMPSON---

double reglaSimpson1TerSimple(){ 
    
    double b = 0.8;
    double a = 0;
    double xMedia = 0.4;
    
    //Normal
    double area = (b-a)*((funcion(a)+4*funcion(xMedia)+funcion(b))/6); //cuando solo hay tres puntos
    
    return area;
}

double reglaSimpson1TerAplicMult(){ 
    
    double x[] = {0,0.2,0.4,0.6,0.8}; //puntos que se utilizan para este método
    int tamano = sizeof(x)/sizeof(double);
    
    double b = x[tamano-1];
    double a = x[0];
    
    double sumatoriaI =0.0;
    double sumatoriaP =0.0;
    
    for(int i=1;i<tamano-1;i+=2){      //impares
        sumatoriaI += funcion(x[i]);
    }
    //std::cout <<sumatoriaI << std::endl;
    for(int j=2;j<tamano-2;j+=2){      //pares
        sumatoriaP += funcion(x[j]);
    }
    //std::cout <<sumatoriaP << std::endl;
    
    //De aplicación múltiple
    double area = (b-a)*((funcion(a)+4*sumatoriaI+2*sumatoriaP+funcion(b))/(3*tamano)); //cuando quieres saber de una serie de puntos
    
    return area;
}

double reglaSimpson3Oct(){ 
    
    double x[] = {0,0.2,0.4,0.6,0.8}; //puntos que se utilizan para este método
    int tamano = sizeof(x)/sizeof(double);
    double b = x[tamano-1];
    double a = x[0];
    
    double area = (b-a)*((funcion(a)+3*funcion(x[1])+3*funcion(x[2])+funcion(b))/8);
    
    return area;
}

//***PARA Romberg***
//la k depende de los grados, que dependen de la cantidad de integrales inciales.
//par romberg se utiliza la fórmula ((4^k-1)*IntegralMasExacta - IntegralMenosExacta)/((4^k-1)-1)

int main(){
    double resultado2 = reglaSimpson1TerAplicMult();       //para los trapecios
    double resultado = reglaSimpson3Oct();
    std::cout <<"Integral: "<< resultado << std::endl;
    std::cout <<"Integral: "<< resultado2 << std::endl;
}