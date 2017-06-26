#include <iostream>
#include <iomanip>
#include <math.h>
#include <tuple>

using namespace std;

const int grado=3;
float p []={1,-4,5.25,-2.5}; //polinomio en orden normal

std::tuple<float, float> cramer(float* b, float* c){
    float x, y;
    x=((-b[grado-1]*c[grado-2]+c[grado-3]*b[grado])/(c[grado-2]*c[grado-2]-c[grado-1]*c[grado-3]));
    y=((-b[grado]*c[grado-2]+c[grado-1]*b[grado-1])/(c[grado-2]*c[grado-2]-c[grado-1]*c[grado-3]));
    return  std::make_tuple(x,y);
}

std::tuple<float, float, int> rs(float r, float s){
    float dr=0;
    float ds=0;
    int it=0;
    float b[grado+1]={0};
    do{
        float xr [grado+1]={0}, xs[grado+1]={0}, c[grado]{0};
        for(int i=1;i<grado+1;i++){
            xr[i]=(p[i-1]+xr[i-1]+xs[i-1])*r;
            xs[i]=(p[i-2]+xr[i-2]+xs[i-2])*s;
        }

        //cout<<"b: "<< endl;
        for(int i=0;i<grado+1;i++){
            b[i]=p[i]+xr[i]+xs[i];
            //cout << p[i] << " + " << xr[i] << " + " << xs[i] << " = " << b[i] << endl;
        }

        xr [0]=0; xs[0]=0;
        xr[1]=(b[0]+xr[0]+xs[0])*r;
        for(int i=2;i<grado;i++){
            xr[i]=(b[i-1]+xr[i-1]+xs[i-1])*r;
            xs[i]=(b[i-2]+xr[i-2]+xs[i-2])*s;
        }

        //cout<<"c: "<< endl;
        for(int i=0;i<grado;i++){
            c[i]=b[i]+xr[i]+xs[i];
            //cout << b[i] << " + " << xr[i] << " + " << xs[i] << " = " << c[i] << endl;
        }

        tie(dr,ds)= cramer(b,c);
        r+=dr;
        s+=ds;
        it++;
        //-cout << "r: " << r << " s: "<< s << endl;
    }
    while((fabs(dr/r)>pow(10,-2))&&(fabs(ds/s)>pow(10,-2))); //OR
    cout << "Nuevo polinomio: ";
    for(int i=0;i<grado-3;i++){
            cout <<setprecision(3)<< b[i] << "x^" <<grado-i-2<<" + ";
        }
            cout <<setprecision(3)<< b[grado-3] << "x" << " + ";
            cout <<setprecision(3)<< b[grado-2] << endl;
    return  std::make_tuple(r, s, it);
}

int main()
{
    float r, s, x1, x2;
    int it;
    cout << "Ingrese dos valores iniciales" << endl;
    cin >> r;
    cin >> s;
    tie(r,s,it)= rs(r,s);
    cout << "r: " << r << " s: "<< s << endl;

    if((r*r+4*s)<0){
        x1=r/2;
        x2=pow((-r*r-4*s),0.5)/2;
        cout <<"La raices son: ";
        cout <<setprecision(4)<< x1 <<" + "<< x2 <<"i, "<< x1 <<" - "<< x2 <<"i"<< endl;
    }else{
        x1=(r+pow((r*r+4*s),0.5))/2;
        x2=(r-pow((r*r+4*s),0.5))/2;
        cout <<setprecision(4)<<"La raices son: ";
        cout <<setprecision(4)<< x1 <<", "<< x2 << endl;
    }

    cout << "numero de iteraciones: " << it << endl;
    return 0;
}