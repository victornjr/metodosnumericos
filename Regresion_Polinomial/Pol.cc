#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
int i,j,k,n,N;
cout.precision(4);
cout.setf(ios::fixed);
cout<<"\nIngresa el total de valores (pares) a tomar en cuenta:\n";
cin>>N;
double x[N],y[N];
cout<<"\nIngresa los valores en el eje de x:\n";
for (i=0;i<N;i++)
cin>>x[i];
cout<<"\nIngresa el valor de y:\n";
cin>>y[i];
cout<<"\nIngresa el grado del polinomio a utilizar:\n";
cin>>n;
double X[2*n+1];
for (i=0;i<2*n+1;i++)
{
X[i]=0;
for (j=0;j<N;j++)
X[i]=X[i]+pow(x[j],i);
}
double B[n+1][n+2],a[n+1];
for (j=0;j<=n;j++)
B[i][j]=X[i+j];
double Y[n+1];
for (i=0;i<n+1;i++)
{
Y[i]=0;
for (j=0;j<N;j++)
Y[i]=Y[i]+pow(x[j],i)*y[j];
}
for (i=0;i<=n;i++)
B[i][n+1]=Y[i];
n=n+1;

for (i=0;i<n;i++)
{
for (j=0;j<=n;j++)
cout<<B[i][j]<<setw(16);
cout<<"\n";
}
for (i=0;i<n;i++)
if (B[i][i]<B[k][i])
for (j=0;j<=n;j++)
{
double temp=B[i][j];
B[i][j]=B[k][j];
B[k][j]=temp;
}

for (i=0;i<n-1;i++)
for (k=i+1;k<n;k++)
{
double t=B[k][i]/B[i][i];
for (j=0;j<=n;j++)
B[k][j]=B[k][j]-t*B[i][j];
}
for (i=n-1;i>=0;i--)
{
a[i]=B[i][n];
for (j=0;j<n;j++)
if (j!=i)
a[i]=a[i]-B[i][j]*a[j];
a[i]=a[i]/B[i][i];
}
cout<<"\nCoeficientes:\n";
for (i=0;i<n;i++)
cout<<"x^"<<i<<"="<<a[i]<<endl;
cout<<"\nFunción:\ny=";
for (i=0;i<n;i++)
cout<<" + ("<<a[i]<<")"<<"x^"<<i;
cout<<"\n";
return 0;
}