#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>

using namespace std;
void regresionPolinomial(double*x, double*y, int n){

 const int grado = 2;            //Cambiar el grado para cambiar el grado del polinomio resultante <------- ESTE SI SE CAMBIA DEPENDIENDO DEL PROBLEMA

 double matrix[grado+1][grado+1];
 double solutions[grado+1];

 double sumX = 0;
 double sumXY = 0;

 cout << "------------SISTEMA DE ECUACIONES-------------" << endl;
 //Inicializamos el sistema de ecuaciones
 for (int i = 0; i < grado+1; ++i)
 {

  sumXY = 0;
  for (int k = 0; k < n; ++k)
  {
   sumXY += pow(x[k],i)*y[k];
  }
  solutions[i] = sumXY; //Get the solutiona of the ecuation system

  for (int j = 0; j < grado+1; ++j)
  {
   if (i == 0 && j == 0)
   {
    matrix[i][j] = n;   //Start the matrix[0,0] as n 
   }else{
    sumX = 0;
    for (int k = 0; k < n; ++k)
    {
     sumX += pow(x[k],(j+i));
    }

    matrix[i][j] = sumX;        //Get the other values of the matrix
   }

   cout << matrix[i][j] << ", ";
  }
  cout << "= " << solutions[i] << endl;
 }

 //Ahora resolvemos el sistema de ecuaciones con algun método conocido
 cout << "-------------------GAUSS SEIDEL---------------------" << endl;
 int size = grado +1;
 double EPSILON = 0.0000001; // error iterativo como tolerancia

 double S[size]; //Array with the solutions
 double OS[size];  //Array with old solutions
 double E[size]; //Array with th error of each variable
 for (int i = 0; i < size; ++i)
 {
  S[i] = 0;  //We initialize each solution at 0;
  OS[i] = 0; //Pseudo minus infinity at each old solution;

  E[i] = 0;
 }

 bool errorCheck = false;

 int counter=0;
 
 while(!errorCheck){
  for (int i = 0; i < size; ++i)
  {
   double sum = 0;
   for (int j = 0; j < size; ++j)
   {
    if (j != i)
    {
     sum += matrix[i][j]*S[j];
    }
   }
   OS[i] = S[i];  //The old value is the actual value
   S[i] = (solutions[i] - sum)/matrix[i][i];  //The actual value changes to the substitution of the variable

   E[i] = (S[i]-OS[i]);  //Error iterativo absoluto
   //E[i] = (S[i]-OS[i])/S[i];  // Error iterativo relativo
   //E[i] = ((S[i]-OS[i])/S[i])*100;  // Error iterativo porcentual
  }

  for (int i = 0; i < size; ++i)
  {
   if(abs(E[i]) > EPSILON){
    break;
   }
   errorCheck = true;
  }
  counter++;
 }

 for (int i = 0; i < size; ++i)
 {
  cout  << " a" << i << ": " << S[i] << endl;
 }
 cout << "it took " << counter << " times to terminate" << endl;
 //-------------------Aqui termina GaussSeidel------------------------

 cout << "------------------POLINOMIO---------------" << endl;
 for (int i = size-1; i >= 1; --i)
 {
  cout << S[i] << "X^"<< i << " + ";
 }
 cout << S[0] << endl;

 cout << "------------------ERRORES------------------" << endl;
 double e2[n]; //Calcula el error para cada X
 for (int i = 0; i < n; ++i)
 {
  double Ycalculada = 0;
  for (int j = size-1; j >= 1; --j)
  {
   Ycalculada += S[j]*(pow(x[i], j));
  }
  Ycalculada += S[0];
  e2[i] = pow(y[i]-Ycalculada,2);
 }

 double sr = 0;
 double sumY = solutions[0];
 double st = 0;
 for (int i = 0; i < n; ++i)
 {
  sr += e2[i];
  st += pow(y[i] - (sumY/n),2);
 }
 cout << "Sr: " << sr << endl;

 double sxy = sqrt(sr/(n-size));
 cout << "St: " << st << endl;

 double r2 = (st-sr)/st;
 double r = sqrt(r2);
 cout << "Error Estandar (Sx/y): " << sxy << endl;
 cout << "Coeficiente de determinacion (r2): " << r2 << endl;
 cout << "Coeficiente de correlacion (r): " << r << endl;
 cout << endl;
}

int main(){
 //Es necesario cambiar el grado del polinomio arriba y el error para Gauss Seidel.
 double x[] = {0,1,2,3,4,5};
 double y[] = {2.1,7.7,13.6,27.2,40.9,61.1};
 int dataNum = sizeof(x)/sizeof(double);
 
 regresionPolinomial(x,y,dataNum);
}