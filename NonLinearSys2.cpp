#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void NDD(double x[10],double f[10][10])
{
    int n=10,i,j,ind=0;
    for(int i = 1; i < n; i++)
    {
        {
            f[i][0] = (f[i-1][1]-f[i-1][0])/(x[i]-x[0]);
            cout<<" b["<<i-1<<"]= " <<f[i][0]<<endl;
        }
    }
//show polynomial
        cout<<"\n\n";
        //1st Order polynomial
        cout<<" 1st Order polynomial:"<<endl;
        cout<<"f"<<ind+1<<"(x)="<<f[0][0]<<" + "<<f[1][0]<<"(x-"<<x[0]<<")\n";
        cout<<"f"<<ind+1<<"(x)="<<f[1][0]<<"x + "<<(f[1][0]*x[0])+f[0][0]<<endl;
        //2nd Order polynomial
        cout<<" \n2nd Order polynomial:"<<endl;
        cout<<"f"<<ind+2<<"(x)= "<<f[0][0]<<" + "<<f[1][0]<<"(x-"<<x[0]<<") + "<<f[2][0]<<"(x-"<<x[0]<<")"<<"(x-"<<x[1]<<")\n";
        cout<<"f"<<ind+2<<"(x)="<<f[2][0]<<"x^2 + "<<f[1][0]-(f[2][0]*x[1])-(f[2][0]*x[0])<<"x + "<<f[0][0]-(f[1][0]*x[0])-(f[2][0]*x[0]*x[1])<<endl;
        //3rd Order polynomial
        cout<<" \n3rd Order polynomial:"<<endl;
        cout<<"f"<<ind+3<<"(x)= "<<f[0][0]<<" + "<<f[1][0]<<"(x-"<<x[0]<<") + "<<f[2][0]<<"(x-"<<x[0]<<")"<<"(x-"<<x[1]<<") + "<<f[3][0]<<
        "(x-"<<x[0]<<")"<<"(x-"<<x[1]<<")"<<"(x-"<<x[2]<<")\n";
        cout<<"f"<<ind+3<<"(x)="<<f[3][0]<<"x^3 + "<<f[2][0]-(f[3][0]*(x[2]+x[1]+x[0]))<<"x^2 + "<<(f[1][0]-(f[2][0]*x[1])-(f[2][0]*x[0]))
        +(f[3][0]*x[2]*(x[0]+x[1]))<<"x + "<<f[0][0]-(f[1][0]*x[0])-(f[2][0]*x[0]*x[1])-(f[3][0]*x[0]*x[1]*x[2])<<endl;
}

int main()
{
    double b[10],firstb;
    int n=10,i,j;
    double x[10] = {0, 0.2, 0.4, 0.8, 1.0, 1.4, 1.6, 1.8, 2.0, 1.2};
    double f[10][10] = {1.000, 0.916, 0.836, 0.0741, 0.624, 0.224, 0.265, 0.291, 0.316, 0.429};
    double x_val= 1.90;
    double f3;

    cout<<" x=[0, 0.2, 0.4, 0.8, 1.0, 1.4, 1.6, 1.8, 2.0, 1.2]\n";
    cout<<" f(x)=[1.000, 0.916, 0.836, 0.0741, 0.624, 0.224, 0.265, 0.291, 0.316, 0.429]\n"<<endl;

    NDD(x,f);

    firstb=f[0][0];
    for(int i = 1;i<n;i++)
    {
        double k = 1;
        for(int j = 0; j<i;j++)
        {
            k=k*(x_val - x[j]);
        }
        firstb =firstb+(k * f[i][0]);
    }
    cout <<" \nApproximate value of f("<<x_val<< "): " <<firstb<< endl;

return 0;
}
