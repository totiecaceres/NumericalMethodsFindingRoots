#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double lagrange(int X, double x[8], double f[8])
{   double L, d;
    for(int i=1; i<=7; i++)
    {   L=0;
        for(int j=0; j<=i; j++)
        {   d=1;
            for(int k=0; k<=i; k++)
            {   if(j!=k)
                    d = d*((X-x[k])/(x[j]-x[k]));
            }
            L = L + d*f[j];
        }
    }
    cout.precision(10); cout.setf(ios::fixed);
    cout<<" F("<<X<<")= "<<L<<endl;
}

int main()
{   cout<<" Lagrange Interpolation: \n";
    cout<<" T[8] = {0, 10, 20, 30, 40, 60, 80, 100} \n";
    cout<<" P[8] = {0.0061, 0.0123, 0.234, 0.0424, 0.0738, 0.1992, 0.4736, 1.0133}";
    double x[8] = {0, 10, 20, 30, 40, 60, 80, 100};
    double f[8] = {0.0061, 0.0123, 0.0234, 0.0424, 0.0738, 0.1992, 0.4736, 1.0133};
    double X,n;
    for(double X=0;X<=100;X=X+5)
    {
        cout<<" \nFind the value of P(T) if T = "<<X<<endl;
        lagrange(X,x,f);
    }
    return 0;
}
