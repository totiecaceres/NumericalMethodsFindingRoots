#include<iostream>
#include<cmath>

using namespace std;

double func(int n, double x)
{   double y;
    if(n==1){y=pow(x,5)-21*pow(x,2)-8*pow(x,3)-4*pow(x,4)-28*x+60;}
    else if(n==2){y=pow(x,3)-pow(x,2)+exp(x);}
    else if(n==3){y=x*exp(-x);}
    else if(n==4){y=sin(x)+3*cos(x)-2;}
    else if(n==5){y=pow(x,4)+2*pow(x,3)-7*pow(x,2)-8*x+12;}
    else if(n==6){y=pow(x,10)-1;}
    else{y=x-exp(-pow(x,2));}
    return y;
}
double derive_func(int n, double x)
{   double f_prime;
    if(n==1){f_prime=5*pow(x,4)-42*x-24*pow(x,2)-16*pow(x,3)-28;}
    else if(n==2){f_prime=3*pow(x,2)-2*x+exp(x);}
    else if(n==3){f_prime=exp(-x)-x*exp(-x);}
    else if(n==4){f_prime=cos(x)-3*sin(x);}
    else if(n==5){f_prime=4*pow(x,3)+6*pow(x,2)-14*x-8;}
    else if(n==6){f_prime=10*pow(x,9);}
    else{f_prime=1+2*x*exp(-pow(x,2));}
    return f_prime;
}
void newton_rap(int n, double xi,int dp)
{   int itr=0, itr_count;   double xrev=xi, ea=100, es=pow(10,-dp);
    cout<<"itr \t xr \t\t f(xr) \t\t\t f'(xr) \t\t |Ea|%"<<endl;
    while(itr!=75)
    {   double xrev_old=xrev, f_xrev=func(n,xrev), f_prime=derive_func(n,xrev);
        xrev=xrev-f_xrev/f_prime;
        cout.precision(dp); cout.setf(ios::fixed);
        cout<<itr<<"\t"<<xrev_old<<"\t"<<f_xrev<<"\t\t"<<f_prime<<"\t\t"<<ea<<endl;
            if(fabs(xrev_old-xrev)>=es)
            {   itr_count=itr;
            }
                ea=abs((xrev-xrev_old)/xrev)*100;
                if(ea<=es||ea>pow(10,dp))
                {   cout<<" Root= "<<xrev<<"\tIteration= "<<itr_count<<endl;
                    break;
                }
                else if(itr>50)// Diverge
                {   cout<<" \nSorry the process has been Diverge, This Can't be solve by using Newton-Rapson"<<endl;
                    break;
                }
                itr=itr+1;
    }
}

int main()
{   string item[7];
    item[0]="1.F(x)= x^5 - 21x^2 - 8x^3 - 4x^4 - 28x + 60";
    item[1]="2.F(x)= x^3 - x^2 + exp(x)";
    item[2]="3.F(x)= x*exp(-x)";
    item[3]="4.F(x)= sin(x) + 3cos(x) - 2";
    item[4]="5.F(x)= x^4 + 2x^3 - 7x^2 - 8x + 12";
    item[5]="6.F(x)= x^10 - 1";
    item[6]="7.F(x)= x - exp(-x^2)";
    cout<<" Determine the roots of following function using Newton-Rapson Method. ";
    cout<<"\n"<<item[0]<<"\n"<<item[1]<<"\n"<<item[2]<<"\n"<<item[3]<<"\n"<<item[4]<<"\n"<<item[5]<<"\n"<<item[6];

    n:cout<<"\n Item number(1-7)? ";
    int n;
    cin>>n;
    if(n>7||n<=0){goto n;}
    cout<<item[n-1];

        cout<<" \nXi= ";
        double xi;
        cin>>xi;

        newton_rap(n,xi,10);
        goto n;
        cout<<"\n Reset(y/n)? ";
        char reset;
        cin>>reset;

            if(reset=='y')
            {   goto n;
            }
    return 0;
}
REGULA_FALSI_METHOD
void regula_falsi(int n, double xlower, double xupper,int dp)
{
	int itr=0, iter_count; double xrev=xlower, ea=100, et=0;// This is the value of [itr, ea and xrev] at 0 iteration.
        if(my_func(n,xlower)*my_func(n,xupper)>=0)            // Check if the sign are change.
        {   cout<<"\n There are no roots or even number of roots found b/w your bounded input, Please try another.";n=0;
        }
            cout<<"\nItr\t(xl)\t\tf(xl)\t\t(xu)\t\tf(xu)\t\t(xr)\t\tf(xr)\t\t\t|Ea|(%)\n";
            while(n!=0)                             // This is the Iteration Part Begins
            {   double fxlower = my_func(n,xlower); // This compute the values of f(xlower)
                double fxupper = my_func(n,xupper); // This compute the values of f(xupper)
                double xrev_old = xrev;             // Store first the old xrev before compute for the xrev in next iteration
                xrev = xupper - (fxupper*(xlower-xupper)/(fxlower-fxupper)); // This computes the values of xrev
                double fxrev = my_func(n,xrev);     // This computes the values of f(xrev)
                    cout.precision(dp); cout.setf(ios::fixed);// to display 10 decimal places and fix the indention of values.
                    cout<<itr<<"\t"<<xlower<<"\t"<<fxlower<<"\t"<<xupper<<"\t"<<fxupper<<"\t"<<xrev<<"\t"<<fxrev<<"\t"<<ea<<endl;

                        itr = itr + 1;                   // Count the number of iterations
                        if(fabs(xlower-xrev)>pow(10,-dp))// to stop the iteration count
                        {   iter_count=itr;              // to store the iteration count.
                        }

                        ea=abs((xrev-xrev_old)/xrev)*100;// Compute for the Approximate percent Error.
                        // This statements changes the value of every interval xlower and xupper to where the root is near.
                        if(fxlower*fxrev<0){xupper=xrev;} else if(fxlower*fxrev>0){xlower=xrev;} else{ea=0;}
                            if(ea<=pow(10,-dp))         // determine whether the value of desired |Ea|% is satisfy.
                            {
                                cout<<" Root = "<<xrev; cout<<"\n itr = "<<iter_count;// display the root and number of iteration
                                break;                  // STOP the Iteration Process.
                            }
            }
}
NEWTON_RAPSON_METHOD
void newton_rap(int n, double xi,int dp)
{   int itr=0, itr_count;   double xrev=xi, ea=100, es=pow(10,-dp);
    cout<<"itr \t xr \t\t f(xr) \t\t\t f'(xr) \t\t |Ea|%"<<endl;
    while(itr!=75)
    {   double xrev_old=xrev, f_xrev=func(n,xrev), f_prime=derive_func(n,xrev);
        xrev=xrev-f_xrev/f_prime;
        cout.precision(dp); cout.setf(ios::fixed);
        cout<<itr<<"\t"<<xrev_old<<"\t"<<f_xrev<<"\t\t"<<f_prime<<"\t\t"<<ea<<endl;
            if(fabs(xrev_old-xrev)>=es)
            {   itr_count=itr;
            }
                ea=abs((xrev-xrev_old)/xrev)*100;
                if(ea<=es||ea>pow(10,dp))
                {   cout<<" Root= "<<xrev<<"\tIteration= "<<itr_count<<endl;
                    break;
                }
                else if(itr>50)// Diverge
                {   cout<<" \nSorry the process has been Diverge, This Can't be solve by using Newton-Rapson"<<endl;
                    break;
                }
                itr=itr+1;
    }
}
SECANT_METHOD
void secant(int n, double xa,double xb,int dp)
{   int itr=0, itr_count;   double xrev=xa, ea=100, es=pow(10,-dp);
    cout<<"itr \t xa \t\t xb \t\t\t xrev \t\t |Ea|%"<<endl;
    while(itr!=75)
    {   double xrev_old=xrev, f_xa=func(n,xa), f_xb=func(n,xb), f_xrev=func(n,xrev);
        xrev=xb-(f_xb*(xa-xb)/(f_xa-f_xb));
        cout.precision(dp); cout.setf(ios::fixed);
        cout<<itr<<"\t"<<xa<<"\t"<<xb<<"\t\t"<<xrev<<"\t\t"<<ea<<endl;
            if(fabs(xrev_old-xrev)>=es)
            {   itr_count=itr;
            }
                ea=abs((xrev-xrev_old)/xrev)*100;
                if(ea<=es||ea>pow(10,dp))
                {   cout<<" Root= "<<xrev<<"\tIteration= "<<itr_count<<endl;
                    break;
                }
                else if(itr>50)// Diverge
                {   cout<<" \nSorry the process has been Diverge, This Can't be solve by using Secant"<<endl;
                    break;
                }
                xa=xb;
                xb=xrev;
                itr=itr+1;
    }
}

