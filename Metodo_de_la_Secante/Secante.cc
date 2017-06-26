#include <iostream>
#include <cmath>

int iteracion = 1;
double funcion(double x){
    return sin(x) - 0.25*x + 2;
}

float metodo(float x1, float x2){
    float fun1 = funcion(x1);
    float fun2 = funcion(x2);
    float raiz = x1 - (fun1*(x2-x1)/(fun2-fun1));
    float funRaiz = funcion(raiz);
    
    //std::cout << "X" << iteracion << ": " << raiz << std::endl;   //para mostrar el número de iteraciones
    
    if(funRaiz == 0 || fun1 == 0){
        return raiz;
    }
    else if(funRaiz < 0.0001 && funRaiz > -0.0001){ //ERROR
        return raiz;
    }
    else if(iteracion >= 50){   //detener por num de iteraciones
        std::cout << "No hay raiz, es divergente" <<  std::endl;
        return -1;
    }
    else{
        iteracion++;
        return metodo(raiz,x2);
    }
}

int main(){
    std::cout << "raiz 1: " << metodo(3.5,3.75) << std::endl;
    std::cout << "raiz 2: " << metodo(6,6.25) << std::endl;
    std::cout << "raiz 3: " << metodo(8.5,8.75) << std::endl;
}