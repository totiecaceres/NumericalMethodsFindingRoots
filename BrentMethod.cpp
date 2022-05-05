#include<iostream>
#include<cmath>
#include<iomanip>
#include<complex>

using namespace std;

complex<double> func(int n, complex<double> x)
{   complex<double> y;
    if(n==1){y = pow(x,5) -21.0*pow(x,2) -8.0*pow(x,3) -4.0*pow(x,4) -28.0*x +60.0;}
    else if(n==2){y = pow(x,4)+2.0*pow(x,3)-7.0*pow(x,2)-8.0*x+12.0;}
    else if(n==3){y = pow(x,3)-4.5*pow(x,2) +0.86*x +9.24;}
    return y;
}

complex<double> brent(int n, complex<double> x1, complex<double> x2, complex<double> x3, int dp)
{   int itr=0, itr_count; complex<double> xrev=x1, ea=100, es=pow(10,-dp);
    cout<<"itr \t\t x0 \t\t\t\t x1 \t\t\t\t x2 \t\t\t\t f(x1) \t\t\t\t f(x2) \t\t\t\t f(x3) \t\t\t\t |Ea|%"<<endl;
    while(itr!=80)
    {   complex<double> xrev_old=xrev, f_x1=func(n,x1), f_x2=func(n,x2), f_x3=func(n,x3);
        complex<double> u=f_x2/f_x3, v=f_x2/f_x1, w=f_x1/f_x3;
        complex<double> p=v*(w*(u-w)*(x3-x2)-(1.0-u)*(x2-x1));
        complex<double> q=(u-1.0)*(v-1.0)*(w-1.0);
        xrev=x2+p/q;

        cout.precision(dp); cout.setf(ios::fixed);
        if(imag(xrev)!=0)
        {
            cout<<itr<<"\t"<<x1<<"\t"<<x2<<"\t"<<x3<<"\t"<<f_x1<<"\t"<<f_x2<<"\t"<<f_x3<<"\t"<<real(ea)<<endl;
        }
        else
        {
            cout<<itr<<"\t"<<real(x1)<<"\t"<<real(x2)<<"\t"<<real(x3)<<"\t"<<real(f_x1)<<"\t"<<real(f_x2)<<"\t"<<real(f_x3)<<"\t"<<real(ea)<<endl;
        }
            ea=abs((xrev_old-xrev)/xrev)*100;
            if(real(ea)<=real(es)||real(ea)>pow(10,dp)||xrev_old==xrev)
            {   if(imag(xrev)!=0){cout<<" Root = "<<xrev<<"\t Iteration = "<<itr;}
                else{cout<<" Root = "<<xrev<<"\t Iteration = "<<itr;}
                break;
            };
            x1=x2;
            x2=x3;
            x3=xrev;
            itr++;
    }

}

int main()
{   cout<<" Number: ";
    int n;
    n:cin>>n;

    cout<<"\n x0= ";
    complex<double> x1;
    cin>>x1;
    cout<<" x1= ";
    complex<double> x2;
    cin>>x2;
    cout<<" x2= ";
    complex<double> x3;
    cin>>x3;

    brent(n,x1,x2,x3,10);
    goto n;
    return 0;
}
