#include <iostream>
#include <cmath>

using namespace std;

void metodo(double*x,double*y,int tamano) {
  double xs = 0.0, ys = 0.0, logxs = 0.0, logys = 0.0, logxlogys = 0.0, logxsq;
  int n = tamano;

  // Setup calculations
  for (int i = 0; i < n; i++) {
    xs += x[i];
    ys += y[i];
    logxs += log10(x[i]);
    logys += log10(y[i]);
    logxlogys += log10(x[i]) * log10(y[i]);
    logxsq += pow(log10(x[i]), 2);
  }
  double xmean = xs / n;
  double ymean = ys / n;
  double logxmean = logxs / n;
  double logymean = logys / n;


  double a1 = (n * logxlogys - logxs * logys) / (n * logxsq - pow(logxs, 2));
  double a0 = logymean - a1 * logxmean;

  cout << "EQUATION" << endl;
  cout << "y = " << pow(10, a0) << "x^" << a1 << endl;
  double st = 0.0, sr = 0.0;
  for (int i = 0; i < n; i++) {
    sr += pow(y[i] - pow(10, a0) * pow(x[i], a1), 2);
    st += pow(y[i] - ymean, 2);
  }
  cout << "ST: " << st << endl;
  cout << "SR: " << sr << endl;
  // Standard error
  double serr = sqrt(sr / (n - 2));
  cout << "STANDARD ERROR" << endl;
  cout << serr << endl;
  // Determination coefficient
  double r = sqrt((st - sr) / st);
  cout << "CORRELATION COEFFICIENT" << endl;
  cout << r << endl;
  cout << "DETERMINATION COEFFICIENT" << endl;
  cout << pow(r, 2) << endl;
}

int main() {
  //se insertan los valores de x y y
  double x[] = {0.15,0.25,0.5,0.75,0.84,1,1.25,1.33,1.4,1.5};
  double y[] = {0.11036,0.30656,1.22625,2.75906,3.46096,4.905,7.66406,8.67645,9.6138,11.03625};
  int tamano = sizeof(x)/sizeof(double);
  //se utilizan los arreglos anteriores para correr el método
  metodo(x,y,tamano);
    
  return 0;
}