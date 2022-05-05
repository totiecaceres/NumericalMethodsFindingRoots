#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double I1(double x2)
{   double y1=((5*x2 +15)/15);    return y1;
}
double I2(double x1, double x3)
{   double y2=((5*x1 +5*x3)/20);    return y2;
}
double I3(double x2, double x4)
{   double y3=((5*x2 +5*x4)/20);    return y3;
}
double I4(double x3)
{   double y4=(5*x3/30);    return y4;
}

double gauss_seidel_2(double x1, double x2, double x3, double x4, int dp)
{   int itr=0;  double es=pow(10,-dp);
    cout<<"itr \t I1 \t\t I2 \t\t I3 \t\t I4"<<endl;
    while(itr!=100)
    {   double y1=I1(x2), y2=I2(x1,x3), y3=I3(x2,x4), y4=I4(x3);
        cout.precision(dp); cout.setf(ios::fixed);
        if(fabs(y1-x1)<es && fabs(y2-x2)<es && fabs(y3-x3)<es && fabs(y4-x4)<es)
        {   cout<<"\n I1= "<<x1<<"\n I2= "<<x2<<"\n I3= "<<x3<<"\n I4= "<<x4<<endl;
            cout<<" Iteration= "<<itr<<endl;
            break;
        }
        cout<<"\n"<<itr;
        if(fabs(y1-x1)>es){y1=I1(x2);     cout<<"\t"<<x1; x1=y1;}else{cout<<"\t"<<x1;}
        if(fabs(y2-x2)>es){y2=I2(x1,x3);  cout<<"\t"<<x2; x2=y2;}else{cout<<"\t"<<x2;}
        if(fabs(y3-x3)>es){y3=I3(x2,x4);  cout<<"\t"<<x3; x3=y3;}else{cout<<"\t"<<x3;}
        if(fabs(y4-x4)>es){y4=I4(x3);     cout<<"\t"<<x4; x4=y4;}else{cout<<"\t"<<x4;}
        ++itr;
    }
}

int main()
{   double x1, x2, x3, x4, x5;
    cout<<" Item 2:";
    n:cout<<"\n I1= ";
    cin>>x1;
    cout<<" I2= ";
    cin>>x2;
    cout<<" I3= ";
    cin>>x3;
    cout<<" I4= ";
    cin>>x4;
    gauss_seidel_2(x1,x2,x3,x4,10);

    goto n;

    return 0;
}
