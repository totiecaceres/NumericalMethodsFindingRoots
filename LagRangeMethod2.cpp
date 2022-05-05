#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double lagrange(double X, double x[10], double f[10])
{   double L, d;
    for(int i=1; i<=9; i++)
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
    cout<<" x[10] = {0, 0.2, 0.4, 0.8, 1.0, 1.4, 1.6, 1.8, 2.0, 1.2} \n";
    cout<<" f[10] = {1.000, 0.916, 0.836, 0.741, 0.624, 0.224, 0.265, 0.291, 0.316, 0.429}";
    double x[10] = {0, 0.2, 0.4, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0};
    double f[10] = {1.000, 0.916, 0.836, 0.741, 0.624, 0.429, 0.224, 0.265, 0.291, 0.316};
    double X,n;

    for(double X=0;X<=2;X=X+0.2)
    {
        cout<<" \nFind the value of P(T) if T = "<<X<<endl;
        lagrange(X,x,f);
    }
    cout<<" \nFind the value of P(T) if T = 1.9"<<endl;
    lagrange(1.9,x,f);
    return 0;
}
