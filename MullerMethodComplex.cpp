#include<iostream>
#include<cmath>
#include<iomanip>
#include<complex>

using namespace std;

complex<double> func(int n, complex<double> x)
{   complex<double> y;
//    if(n==1){y = 10.09*pow(x,2)+pow(x,4)+17.64;}
//    else if(n==2){y = pow(x,3)-4.5*pow(x,2)+0.86*x+94.24 ;}
//    else if(n==3){y = pow(x,5)-21*pow(x,2)-8*pow(x,3)-28*x+60.0 ;}
    if(n==1){y = 10.44*pow(x,2)+pow(x,4)+12.96;}
    else if(n==2){y = pow(x,4)+2.0*pow(x,3)-7.0*pow(x,2)-8.0*x+12.0;}
    else if(n==3){y = pow(x,3)-4.5*pow(x,2)+0.86*x+9.24;}
    else if(n==4){y = pow(x,3)-4.4*pow(x,2)+0.59*x+10.4;}
    else if(n==5){y = pow(x,2)-14.0*x+50.0;}
    return y;
}
complex<double> quad_eq(int s,complex<double> a, complex<double> b, complex<double> c)
{   complex<double> q;
    if(s>0){q = b + sqrt(abs(pow(b,2)-4.0*a*c));}
    else if(s<0){q = b - sqrt(abs(pow(b,2)-4.0*a*c));}
    return q;
}

void muller(int n, complex<double> x0, complex<double> x1, complex<double> x2, int dp)
{   int itr=0, s;   complex<double> xrev=x0;
    complex<double> ea=100, es=pow(10,-dp);
    if(imag(xrev)!=0)
    {   cout<<"itr \t\t x0 \t\t\t\t x1 \t\t\t\t x2 \t\t\t\t a \t\t\t\t b \t\t\t\t c \t\t\t\t |Ea|%"<<endl;
    }
    else
    {   cout<<"itr \t x0 \t\t x1 \t\t x2 \t\t a \t\t b \t\t c \t\t |Ea|%"<<endl;
    }
    while(itr!=200)
    {   complex<double> xrev_old=xrev;
        complex<double> f_x0=func(n,x0), f_x1=func(n,x1), f_x2=func(n,x2);
        complex<double> h0=x1-x0, h1=x2-x1;
        complex<double> d0=(f_x1-f_x0)/h0, d1=(f_x2-f_x1)/h1;
        complex<double> a=(d1-d0)/(h1+h0), b=(a*h1)+d1, c=f_x2;

//            if(real(quad_eq(1,a,b,c))>real(quad_eq(-1,a,b,c)))
//            {   s = 1;
//            }
//            else if(real(quad_eq(1,a,b,c))<real(quad_eq(-1,a,b,c)))
//            {   s = -1;
//            }
//            else
//            {   if(imag(quad_eq(1,a,b,c))>imag(quad_eq(-1,a,b,c)))
//                {   s = 1;
//                }
//                else if(imag(quad_eq(1,a,b,c))<imag(quad_eq(-1,a,b,c)))
//                {   s = -1;
//                }
//            }
            complex<double> q1, q2, m2;
            complex<double> m = b*b - 4.0*a*c;
            if(real(m)<0){m2 = -1.0*m;} else{m2=m;}
            q1 = b + sqrt(m2);
            q2 = b - sqrt(m2);
            if(real(q1)>real(q2)){xrev = xrev_old - 2.0*c/q1;}
            else{xrev = xrev_old - 2.0*c/q2;}
            cout.precision(dp); cout.setf(ios::fixed);
            if(imag(xrev)!=0)
            {   cout<<itr<<"\t"<<x0<<"\t"<<x1<<"\t"<<x2<<"\t"<<a<<"\t"<<b<<"\t"<<b*b<<"\t"<<real(ea)<<endl;
            }
            else
            {   cout<<itr<<"\t"<<real(x0)<<"\t"<<real(x1)<<"\t"<<real(x2)<<"\t"<<real(a)<<"\t"<<real(b)<<"\t"<<real(c)<<"\t"<<real(ea)<<endl;
            }

                    ea=abs((xrev-xrev_old)/xrev)*100;
                    if(real(ea)<=real(es)||real(ea)>pow(10,dp))
                    {   if(imag(xrev)!=0){cout<<" Root = "<<xrev_old<<"\t Iteration = "<<itr;}
                        else{cout<<" Root = "<<real(xrev_old)<<"\t Iteration = "<<itr;}
                        break;
                    }
                    else if(itr>180)// Diverge
                    {   cout<<" \nSorry the process has been Diverge, This Can't be solve by using Muller"<<endl;
                        break;
                    }
                    x0 = x1;
                    x1 = x2;
                    x2 = xrev;
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
        complex<double> x0;
        cin>>x0;
        cout<<" X1= ";
        complex<double> x1;
        cin>>x1;
        cout<<" X2= ";
        complex<double> x2;
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
