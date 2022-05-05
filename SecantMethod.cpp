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

int main()
{   string item[7];
    item[0]="1.F(x)= x^5 - 21x^2 - 8x^3 - 4x^4 - 28x + 60";
    item[1]="2.F(x)= x^3 - x^2 + exp(x)";
    item[2]="3.F(x)= x*exp(-x)";
    item[3]="4.F(x)= sin(x) + 3cos(x) - 2";
    item[4]="5.F(x)= x^4 + 2x^3 - 7x^2 - 8x + 12";
    item[5]="6.F(x)= x^10 - 1";
    item[6]="7.F(x)= x - exp(-x^2)";
    cout<<" Determine the roots of following function using Secant Method. ";
    cout<<"\n"<<item[0]<<"\n"<<item[1]<<"\n"<<item[2]<<"\n"<<item[3]<<"\n"<<item[4]<<"\n"<<item[5]<<"\n"<<item[6];

    n:cout<<"\n Item number(1-7)? ";
    int n;
    cin>>n;
    if(n>7||n<=0){goto n;}
    cout<<item[n-1];

        cout<<" \nXa= ";
        double xa;
        cin>>xa;

        cout<<" \nXb= ";
        double xb;
        cin>>xb;

        secant(n,xa,xb,10);

        cout<<"\n Reset(y/n)? ";
        char reset;
        cin>>reset;

            if(reset=='y')
            {   goto n;
            }
    return 0;
}
