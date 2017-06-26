#include <iostream>
# include <cmath>

using namespace std;
int iteracion = 0;

float funcion (float x){
    //se ingresa la función que se quiere evaluar
    return sin(x) - 0.25*x + 2;
    
}

float metodo(float x1, float x2){
    float num1 = funcion(x1);
    float num2 = funcion(x2);
    float raiz = (x1+x2)/2;
    float raizE = funcion(raiz);
    //si la función evaluada en raiz es 0
    //el resultado es la variable raiz
    
    
    if (raizE == 0){
        return raiz;
    }
    //Si no es 0, se busca que la evaluación en los intervalos
    //sean de signos diferentes
    else if(num1*num2 < 0){
        //si la variable raiz es muy chica, ya no se hace nada
        //y el resultado sería la raiz
        //aquí se muestra el error permitido.
        if(num1 <= 0.0001 && num1 >= -0.0001 && num2>= -0.0001 && num2<= 0.0001){   //ERROR
            return raiz;
        }
        else{
            if (raizE*num1 < 0){
                iteracion++;
                return metodo(x1,raiz);
            }
            else if (raizE*num1 > 0){
                iteracion++;
                return metodo(raiz,x2);
            }
        }
    }
    else{
        cout << "No se encontró la raiz" << endl;
        return -999;
    }
}

int main(){
    //la funcion metodo recibe dos parámetros
    //que es el intervalo inicial.º
    cout << "raiz 1: " << metodo(4,4.5) << endl;
    cout << "raiz 2: " << metodo(5.5,6) << endl;
    cout << "raiz 3: " << metodo(9,9.25) << endl;
}