#include <iostream>
#include <cmath>

int iteracion = 1;
double funcion(double x){
    return atan(x)-0.3;
}
double derivada(double x){
    return 1/(pow(x,2)+1);
}

float metodo(float x){
    float fun = funcion(x);
    float der = derivada(x);
    float raiz = x - (fun/der);
    float funRaiz = funcion(raiz);
    
    std::cout << "X" << iteracion << ": " << raiz << std::endl;
    
    if(funRaiz == 0 || fun == 0){
        return raiz;
    }
    else if(funRaiz < 0.001 && funRaiz > -0.001){   //ERROR
        return raiz;
    }
    else if(der == 0){
        std::cout << "No hay raiz, pendiente = 0" <<  std::endl;
        return -1;
    }
    else if(iteracion >= 80){
        std::cout << "No hay raiz o converge lentamente" <<  std::endl;
        return -1;
    }
    else{
        iteracion++;
        return metodo(raiz);
    }
}

int main(){
    float x0 = 3;
    std::cout << "X0: " << x0 << std::endl;
    std::cout << "raiz: " << metodo(x0) << std::endl;
}