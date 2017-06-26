#include <iostream>
# include <cmath>
using namespace std;

double EPSILON = 0.0001; // error iterativo como tolerancia

double x=0;
    double a=x; // copy of x
double y=0;
    double b=y; // copy of y
double z=0;
    double c=z; // copy of z

// augmented matrix
double rowA[]={1,-3,2,-3}; // 2x -y +1 = 7
double rowB[]={5,6,-1,13}; // x +2y -z = 6
double rowC[]={4,-1,3,8}; // x + y + z = 12

double anteriorX=-999999; // pseudo minus infinity
double anteriorY=-999999; // pseudo minus infinity
double anteriorZ=-999999; // pseudo minus infinity

int times=0;

void gaussSeidel(){
    while(true){
        times++;
        x=(rowA[3]-(rowA[1]*b)-(rowA[2]*c))/rowA[0];
        y=(rowB[3]-(rowB[0]*x)-(rowB[2]*c))/rowB[1]; // we use previously obtained value of x
        z=(rowC[3]-(rowC[0]*x)-(rowC[1]*y))/rowC[2]; // we use previously obtained values of x and y
        a=x;
        b=y;
        c=z;
        
        cout << "x: " << x << ", anteriorX: " << anteriorX << endl;
        cout << "y: " << y << ", anteriorY: " << anteriorY << endl;
        cout << "z: " << z << ", anteriorZ: " << anteriorZ << endl << endl;

        if(abs((x-anteriorX)/x)<=EPSILON && abs((y-anteriorY)/y)<=EPSILON && abs((z-anteriorZ)/z)<=EPSILON){
            break;
        }
        anteriorX=x;
        anteriorY=y;
        anteriorZ=z;
    }
}

int main(){
    gaussSeidel();
    cout << "FINAL ANSWER..." << endl;
    cout << "x: "<< x << endl;
    cout << "y: " << y <<endl;
    cout << "z: " << z << endl;
    cout << "it took " << times << " times to terminate";
    return 0;
}