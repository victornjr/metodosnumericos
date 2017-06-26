#include <iostream>
# include <cmath>

using namespace std;

void metodo(float*todasX, float*todasY, int size){
    float sumXY =0.0;
    float sumX =0.0;
    float sumY = 0.0;
    float sumXC =0.0;
    int tamano = size;
    int c =0;
    while(c<tamano){
        sumXY+= todasX[c]*todasY[c];
        sumX+= todasX[c];
        sumY+= todasY[c];
        sumXC+= pow(todasX[c],2);
        c++;
    }
    
    float mediaY = sumY/tamano;
    float mediaX = sumX/tamano;
    //ecuaciones normales
    float a1 = (tamano*sumXY-sumX*sumY)/(tamano*sumXC-pow(sumX,2));
    float a0 = mediaY-a1*mediaX;
    
    cout << "Función de la recta: \ny = " << a0 << " + "<< a1 << "x"<< endl;
}

int main(){
    float todasX[] = {1,2,3,4,5};
    float todasY[] = {0.5,1.7,3.4,5.7,8.4};
    int tamano = sizeof(todasX)/sizeof(float);
    metodo(todasX,todasY,tamano);
}




