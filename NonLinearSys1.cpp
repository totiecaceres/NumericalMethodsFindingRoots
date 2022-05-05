#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void NDD(double x[8],double f[8][8])
{
    int n=8,i,j,ind=0;
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
        cout<<"P"<<ind+1<<"(t)="<<f[0][0]<<" + "<<f[1][0]<<"(t-"<<x[0]<<")\n";
        cout<<"P"<<ind+1<<"(t)="<<f[1][0]<<"t + "<<(f[1][0]*x[0])+f[0][0]<<endl;
        //2nd Order polynomial
        cout<<" \n2nd Order polynomial:"<<endl;
        cout<<"P"<<ind+2<<"(t)= "<<f[0][0]<<" + "<<f[1][0]<<"(t-"<<x[0]<<") + "<<f[2][0]<<"(t-"<<x[0]<<")"<<"(t-"<<x[1]<<")\n";
        cout<<"P"<<ind+2<<"(t)="<<f[2][0]<<"t^2 + "<<f[1][0]-(f[2][0]*x[1])-(f[2][0]*x[0])<<"x + "<<f[0][0]-(f[1][0]*x[0])-(f[2][0]*x[0]*x[1])<<endl;
        //3rd Order polynomial
        cout<<" \n3rd Order polynomial:"<<endl;
        cout<<"P"<<ind+4<<"(t)= "<<f[0][0]<<" + "<<f[1][0]<<"(t-"<<x[0]<<") + "<<f[2][0]<<"(t-"<<x[0]<<")"<<"(t-"<<x[1]<<") + "<<f[3][0]<<
        "(t-"<<x[0]<<")"<<"(t-"<<x[1]<<")"<<"(t-"<<x[2]<<")\n";
        cout<<"P"<<ind+3<<"(t)="<<f[3][0]<<"t^3 + "<<f[2][0]-(f[3][0]*(x[2]+x[1]+x[0]))<<"t^2 + "<<(f[1][0]-(f[2][0]*x[1])-(f[2][0]*x[0]))
        +(f[3][0]*x[2]*(x[0]+x[1]))<<"t + "<<f[0][0]-(f[1][0]*x[0])-(f[2][0]*x[0]*x[1])-(f[3][0]*x[0]*x[1]*x[2])<<endl;

}

int main()
{
    double firstb,b[10];
    int n=8,i,j;
    double x[8] = {0, 10, 20, 30, 40, 60, 80, 100};
    double f[8][8] = {0.0061, 0.0123, 0.234, 0.0424, 0.0738, 0.1992, 0.4736, 1.0133};
    double temp=5;

    cout<<" T[0, 10, 20, 30, 40, 60, 80, 100]\n";
    cout<<" P[0.0061, 0.0123, 0.234, 0.0424, 0.0738, 0.1992, 0.4736, 1.0133]\n"<<endl;

    NDD(x,f);
    cout<<" \nEnter Value of Temperature to estimate P(T): \n T= "<<temp;
//    cin>>temp;

    firstb=f[0][0];

    for(int i = 1;i<n;i++)
    {
        double k = 1;
        for(int j = 0; j<i;j++)
        {
            k=k*(temp - x[j]);
        }
        firstb =firstb+(k * f[i][0]);

        cout <<endl << "P" << i << "(" << temp << "): "  <<firstb<< endl;
    }

return 0;
}
