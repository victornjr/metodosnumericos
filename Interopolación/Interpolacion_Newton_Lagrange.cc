#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/**
    Metodo utilizado en la interpolacion Polinomial de Newton
*/
double divisionDiscreta( double *y, double *x, int n, int i, int j, vector<double> *B ) {

    if ( n == 1 ) {

        if ( i == 0 ) {

            B->push_back( y[i] );
            cout << "f(x0): " << y[i] << endl;
        }

        return y[i];
    } else {
        //cout << "xi: " << i << endl;
        //cout << "xj: " << j << endl;
        double val = ( divisionDiscreta( y, x, n - 1, i, j + 1, B ) - divisionDiscreta( y, x, n - 1, i - 1, j, B ) ) / ( x[i] - x[j] );
        if ( j == 0 ) {
            B->push_back( val );
        }
        cout << "f[ x" << i << ", x" << j << " ]: " << val << endl;
        return val;
    }
}

void interpolacionPolinomialNewton() {
    /* Nota: La suma de los binomios son conmutativas */
    double y[] =
    //{2.31, 3.36, 4.59, 6};
    //{0, 1.386294, 1.791759, 1.609438};
    {0.1353, 7.3890, 20.0855};

    double x[] =
    //{0.1, 0.4, 0.7, 1};
    //{1, 4, 6, 5};
    {-2, 2, 3};

    double x_inc = -1;  //x a resolver

    vector<double> B;

    int n = sizeof( y ) / sizeof(double);

    divisionDiscreta( y, x, n, n - 1, 0, &B );

    //
    int j = B.size();
    double v = 0;

    cout << "Polinomio: ";                      //Print Function
    while ( j --> 0 ) {

        cout << B[j];                           //Print Function

        double temp = B[j];
        int k = j;
        while ( k --> 0 ) {

            cout << "(x - " << x[k] << ")";     //Print Function
            temp *= ( x_inc - x[k] );
        }

        if ( j != 0)                            //Print Function
            cout << " + ";                      //Print Function

        v += temp;
    }

    cout << "\nf(x) = " << v << endl;

    // El polinomio es: b0 + b1(x - x0) + b2(x - x0)(x - x1) + b3 (x - x0)(x - x1)(x - x2)
}

/**
    Formula utilizda en la iterpolacion de Lagrange
*/
double L( int i, double x_incognita, double *x, int n ) {

    int j = 0;
    double val = 1;

    while ( j < n ) {

        if ( i != j ) {

            val *= ( x_incognita - x[j] ) / ( x[i] - x[j] );
        }

        j++;
    }

    return val;
}

double f( double *y, double *x, double x_incognita, int n ) {

    int i = 0;

    double val = 0;

    while ( i < n ) {

        val += L( i, x_incognita, x, n ) * y[i];
        i++;
    }
    
    return val;
}

void interpolacionLagrange() {

    double y[] =    //aquí se insertan todos los valores de y
    {14.621,11.843,9.870,8.418,7.305,6.413};

    double x[] =    //aquí se insertan todos los valores de x
    {0,8,16,24,32,40};

    int n = sizeof( y ) / sizeof(double);
    double x_incognita = 27;        //cambiar aquí la x de la que se quiere el resultado

    cout << "y calculada: " << f( y, x, x_incognita, n ) << endl;;
}

int main() {
    
    interpolacionLagrange();

    return 0;
}