#include <iostream>
#include <cmath>

using namespace std;

/*float functionX(float x){	//función para sin(x)
	return sin(x);
}*/
float functionX(float x){	//función para sin(2x)
	return sin(2*x);
}

float riemmanIzquierda(float x1, float x2, int division){

	float altura;
	float area = 0;
	float diferencial = (x2 - x1)/division;
	float base = diferencial;
	float left = x1;
	float right = left + diferencial;

	
	for(int i = 0; i < division ; i++){
		altura = functionX(left);
		area += abs(base*altura);
		left += diferencial;
		right += diferencial;
	}

	return area;
}

float riemmanDerecha(float x1, float x2, int division){

	float altura;
	float area = 0;
	float diferencial = (x2 - x1)/division;
	float base = diferencial;
	float left = x1;
	float right = left + diferencial;
	
	for(int i = 0; i < division; i++){
		altura = functionX(right);
		area += abs(base*altura);
		left += diferencial;
		right += diferencial;
	}

	return area;
}

int main(){
	//valor de pi
	float pi = 3.141592;
	
	//***PARA integral de sin(x)***
	/*for(int i=0;i<110;i+=10){
		std::cout << "área Izquierda con "<<i<<" segmentos :" << riemmanIzquierda(0, pi/3, i) << std::endl;
	}*/

	//***PARA integral de sin(2x)***
	for(int i=0;i<110;i+=10){
		std::cout << "área Izquierda con "<<i<<" segmentos :" << riemmanIzquierda(pi/3, pi/2, i) << std::endl;
	}
}
