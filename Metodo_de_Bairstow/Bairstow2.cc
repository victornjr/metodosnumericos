#include <iostream>
#include <cmath>

using namespace std;
double EPSILON = 0.01; //ERROR

int iteraciones = 0;
void sinteticWeirdFormula( double *arr, double *arrOr, int size, double r, double s ) {
    iteraciones++;
    arr[size-1] = arrOr[size-1];
    arr[size-2] = arr[size-1] * r + arrOr[size-2];

    for ( int i = size - 3; i >= 0; i-- ) {
        arr[i] = ( arr[i + 1] * r ) + ( arr[i + 2] * s ) + arrOr[i];
    }
    return;
}

int main() {
    double arrVal[] = {-2.5,5.25,-4,1}; // Coeficientes del polinomio volteados

    int size = sizeof(arrVal) / sizeof(double);
    int count = 1;

    double arrB[size]; //Initial array B
    double arrC[size]; //Initial array C

    double r = -0.5;
    double s = 0.5;

    double dr; //delta r
    double ds; //delta s

    do {
        sinteticWeirdFormula( arrB, arrVal, size, r, s );
        sinteticWeirdFormula( arrC, arrB, size, r, s );
        dr = ( -arrB[1] * arrC[2] - arrC[3] * -arrB[0] ) / ( arrC[2] * arrC[2] - arrC[1] * arrC[3] );
        ds = ( -arrB[0] * arrC[2] - arrC[1] * -arrB[1] ) / ( arrC[2] * arrC[2] - arrC[1] * arrC[3] );

        double errorR = ( dr / r ) * 100;
        double errorS = ( ds / s ) * 100;

        if ( abs(errorR) <= EPSILON && abs(errorS) <= EPSILON ) {
            break;
        }
        r += dr;
        s += ds;
        count++;
    } while (true);

    double x1 = ( r + sqrt( r * r + 4 * s ) ) / 2;
    double x2 = ( r - sqrt( r * r + 4 * s ) ) / 2;

    cout << "Root 1: " << x1 << endl
    << "Root 2: " << x2 << endl;

    cout << "r: " << r << endl
    << "s: " << s << endl;
    double imag = r/2;
    double imagR = sqrt(-1*(pow(r,2)+4*s))/2;
    
    //***SOLO PARA RAICES IMAGINARIAS***
    cout<< "raices imaginarias: \n" << imag <<" + " << imagR <<"i\n"<< imag<<" - " << imagR <<"i\n"<<endl;

    for ( int i = 0; i < size; i++ ) {

        cout << "Coeficientes de la funcion con menor grado " << arrB[i] << endl;
        
    }
    cout<<"iteraciones totales: "<<iteraciones<<endl;
    
    return 0;
}
