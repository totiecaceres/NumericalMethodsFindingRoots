#include<iostream>
#include<cmath>
#include<iomanip>
#include<complex>
using namespace std;

complex<double> func(int n, complex<double> x)
{   complex<double> y;
    if(n==1){y = 10.44*pow(x,2)+pow(x,4)+12.96;}
    else if(n==2){y = pow(x,4)+2.0*pow(x,3)-7.0*pow(x,2)-8.0*x+12.0;}
    else if(n==3){y = pow(x,3)-4.5*pow(x,2)+0.86*x+9.24;}
    else if(n==4){y = pow(x,3)-4.4*pow(x,2)+0.59*x+10.4;}
    else if(n==5){y = pow(x,2)-14.0*x+50.0;}
    return y;
}
double quad_eq(int s,double a, double b, double c)
{   double q;
    if(s>0){q = b + sqrt(fabs(pow(b,2)-4*a*c));}
    else if(s<0){q = b - sqrt(fabs(pow(b,2)-4*a*c));}
    return q;
}

double muller(int n, double x0, double x1, double x2, int dp)
{   int itr=0, itr_count, s;   double xrev=x0;
    double ea=100, es=pow(10,-dp);
    cout<<"itr \t x0 \t\t x1 \t\t x2 \t\t a \t\t b \t\t c \t\t |Ea|%"<<endl;
    while(itr!=50)
    {   double xrev_old=xrev;
        double f_x0=real(func(n,(pow(10,-dp),x0))), f_x1=real(func(n,(pow(10,-dp),x1))), f_x2=real(func(n,(pow(10,-dp),x2)));
        double h0=x1-x0, h1=x2-x1;
        double d0=(f_x1-f_x0)/h0, d1=(f_x2-f_x1)/h1;
        double a=(d1-d0)/(h1+h0), b=(a*h1)+d1, c=f_x2;
            if(quad_eq(1,a,b,c)>=quad_eq(-1,a,b,c)){s = 1;} else{s = -1;}
            xrev = xrev_old - 2*c/quad_eq(s,a,b,c);
            cout.precision(dp); cout.setf(ios::fixed);
            cout<<itr<<"\t"<<x0<<"\t"<<x1<<"\t"<<x2<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<ea<<endl;
                if(fabs(xrev_old-xrev)>=es)
                {   itr_count=itr;
                }
                    ea=abs((xrev-xrev_old)/xrev)*100;
                    if(ea<=es||ea>pow(10,dp))
                    {   cout<<" Root= "<<xrev<<"\tIteration= "<<itr<<endl;
                        break;
                    }
                    else if(itr>40)// Diverge
                    {   cout<<" \nSorry the process has been Diverge, This Can't be solve by using Muller"<<endl;
                        break;
                    }
//                    x0 = x1;
//                    x1 = x2;
//                    x2 = xrev;
                    double r1=abs(x0-xrev), r3=abs(x2-xrev);
                        if(r1<r3)
                        {   if(xrev<x0)
                            {   x2=x1;
                                x1=x0;
                                x0=xrev;
                            }
                            else
                            {   x2=x1;
                                x1=xrev;
                            }
                        }
                        else if(r3<r1)
                        {   if(xrev>x2)
                            {   x0=x1;
                                x1=x2;
                                x2=xrev;
                            }
                            else
                            {   x0=x1;
                                x1=xrev;
                            }
                        }
                    itr=itr+1;
    }
}
int main()
{

    n:cout<<"\n Item number(1-5)? ";
    int n;
    cin>>n;
    if(n>5||n<=0){goto n;}

        cout<<"\n X0= ";
        double x0;
        cin>>x0;
        cout<<" X1= ";
        double x1;
        cin>>x1;
        cout<<" X2= ";
        double x2;
        cin>>x2;

        muller(n,x0,x1,x2,8);
        goto n;
        cout<<"\n Reset(y/n)? ";
        char reset;
        cin>>reset;

            if(reset=='y')
            {   goto n;
            }
    return 0;
}
