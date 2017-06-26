#include <iostream>
#include <cmath>
using namespace std;

double EPSILON = 0.005; // error iterativo como tolerancia

double x=1;
    double a=x; // copy of x
double y=2;
    double b=y; // copy of y
double z=3;
    double c=z; // copy of z

// augmented matrix
double rowA[]={1,-6,-4,9}; // 2x -y +1 = 7
double rowB[]={12,5,-1,15}; // x +2y -z = 6
double rowC[]={2,-3,8,5}; // x + y + z = 12

double anteriorX=-999999; // pseudo minus infinity
double anteriorY=-999999; // pseudo minus infinity
double anteriorZ=-999999; // pseudo minus infinity

int times=0;

void gaussSeidel(){
    while(true){
        times++;
        if(times>2){
            x=(rowA[3]-(rowA[1]*anteriorY)-(rowA[2]*anteriorZ))/rowA[0];
            y=(rowB[3]-(rowB[0]*anteriorX)-(rowB[2]*anteriorZ))/rowB[1];
            z=(rowC[3]-(rowC[0]*anteriorX)-(rowC[1]*anteriorY))/rowC[2];
        }else{
            x=(rowA[3]-(rowA[1]*b)-(rowA[2]*c))/rowA[0];
            y=(rowB[3]-(rowB[0]*a)-(rowB[2]*c))/rowB[1];
            z=(rowC[3]-(rowC[0]*a)-(rowC[1]*b))/rowC[2];
        }
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