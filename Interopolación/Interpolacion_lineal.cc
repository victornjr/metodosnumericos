#include <iostream>
# include <cmath>

using namespace std;

double funcion(double x1,double y1,double x2,double y2,double x){
    double m = (y2-y1)/(x2-x1);
    double valX = (x-x1);
    cout << "y = "<< y1 << " + " << m << "(x-x1)" <<endl;
    //cout <<"Donde x = x - x1"<<endl;
    double y = y1 + m*valX;
    return y;
}

int main(){
    cout << "y = " << funcion(0,72.5,0.5,78.1,0.3) <<endl;   //usando una función de y

}