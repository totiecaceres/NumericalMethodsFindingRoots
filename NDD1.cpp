#include<iostream>
#include<cmath>

using namespace std;

int main()
{   double start;


    //double output;
    double T[10] = {0,0.2,0.4,0.8,1,1.2,1.4,1.6,1.8,2};
    double P[10] = {1,0.916,0.836,0.714,0.624,0.429,0.224,0.265,0.291,0.316};
    double h[9];
    double i[8];
    double j[7];
    double k[6];
    double l[5];
    double m[4];
    double n[3];
    double r[2];
    double q[10];
    q[0]=P[0];

    for (int o=0 ; o<9 ; o++)
    {
        h[o] = (P[o+1]-P[o])/(T[o+1]-T[o]);
    }
    q[1]=h[0];

    for (int o=0 ; o<8 ; o++)
    {
        i[o] = (h[o+1]-h[o])/(T[o+2]-T[o]);
    }
    q[2]=i[0];
    for (int o=0 ; o<7 ; o++)
    {
        j[o] = (i[o+1]-i[o])/(T[o+3]-T[o]);
    }
    q[3]=j[0];
    for (int o=0 ; o<6 ; o++)
    {
        k[o] = (j[o+1]-j[o])/(T[o+4]-T[o]);
    }
    q[4]=k[0];
    for (int o=0 ; o<5 ; o++)
    {
        l[o] = (k[o+1]-k[o])/(T[o+5]-T[o]);
    }
    q[5]=l[0];
    for (int o=0 ; o<4 ; o++)
    {
        m[o] = (l[o+1]-l[o])/(T[o+6]-T[o]);
    }
    q[6]=m[0];
    for (int o=0 ; o<3 ; o++)
    {
        n[o] = (m[o+1]-m[o])/(T[o+7]-T[o]);
    }
    q[7]=n[0];
    for (int o=0 ; o<2 ; o++)
    {
        r[o] = (n[o+1]-n[o])/(T[o+8]-T[o]);
    }
    q[8]=r[0];
    q[9]=(r[1]-r[0])/(T[9]-T[0]);
    for (int o=0 ; o<7 ; o++)
    {
        cout<<"\nDegree of Polynimial Order = "<<o+1<<endl;
        cout<<"F(x)= ";
        if (o==0)
         cout << q[0] << " + " << q[1] << "x\n";
        if(o==1)
         cout << q[0] << " + " << q[1] << "x + " << q[2] << "(x)(x-0.2)\n";
        if(o==2)
         cout << q[0] << " + " << q[1] << "x + " << q[2] << "(x)(x-0.2) + " << q[3] << "(x)(x-0.2)(x-0.4)\n";
        if(o==3)
         cout << q[0] << " + " << q[1] << "x + " << q[2] << "(x)(x-0.2) + " << q[3] << "(x)(x-0.2)(x-0.4) + " << q[4] << "(x)(x-0.2)(x-0.4)(x-0.6)\n";
        if(o==4)
        cout << q[0] << " + " << q[1] << "x + " << q[2] << "(x)(x-0.2) + " << q[3] << "(x)(x-0.2)(x-0.4) + " << q[4] << "(x)(x-0.2)(x-0.4)(x-0.6)"
         << (q[5]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)\n";
        if(o==5)
        cout << q[0] << " + " << q[1] << "x + " << q[2] << "(x)(x-0.2) + " << q[3] << "(x)(x-0.2)(x-0.4) + " << q[4] << "(x)(x-0.2)(x-0.4)(x-0.6) "
         << (q[5]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)\n\t\t\t + " << q[6] << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)(x-1.0)\n";
        if(o==6)
        cout << q[0] << " + " << q[1] << "x + " << q[2] << "(x)(x-0.2) + " << q[3] << "(x)(x-0.2)(x-0.4) + " << q[4] << "(x)(x-0.2)(x-0.4)(x-0.6) + "
         << abs(q[5]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)\n\t\t\t + " << q[6] << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)(x-1.0) " << (q[7]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)(x-1.0)(x-1.2)\n";
         if(o==7)
        cout << q[0] << " + " << q[1] << "x + " << q[2] << "(x)(x-0.2) + " << q[3] << "(x)(x-0.2)(x-0.4) + " << q[4] << "(x)(x-0.2)(x-0.4)(x-0.6) + "
         << abs(q[5]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)\n\t\t\t + " << q[6] << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)(x-1.0) " << (q[7]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)(x-1.0)(x-1.2)"
         << (q[8]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)(x-1.0)(x-1.2)(x-1.4)\n";
         if(o==8)
        cout << q[0] << " + " << q[1] << "x + " << q[2] << "(x)(x-0.2) + " << q[3] << "(x)(x-0.2)(x-0.4) + " << q[4] << "(x)(x-0.2)(x-0.4)(x-0.6) + "
         << abs(q[5]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)\n\t\t\t + " << q[6] << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)(x-1.0) " << (q[7]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)(x-1.0)(x-1.2)"
         << (q[8]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)(x-1.0)(x-1.2)(x-1.4)" << (q[9]) << "(x)(x-0.2)(x-0.4)(x-0.6)(x-0.8)(x-1.0)(x-1.2)(x-1.4)\n";
    }

    double x;
    cout.precision(10);
    cout.setf(ios::fixed);
    cout<<"\nOrder \t\t 1st \t\t 2nd \t\t 3rd \t\t 4th \t\t 5th \t\t 6th \t\t 7th \t\t 8th \t\t 9th"<<endl;

    for(double x=0;x<=2;x=x+0.2)
    {
        cout<<"f("<<x<<")";
        double u,output=q[0];
        for(int o=0;o<9;o++)
        {
            u=1;
            for (int s=0 ; s<=o ; s++)
            {
                u=u*(x-T[s]);
            }
            output= output + q[o+1]*u;
            cout<<"\t"<<output;
        }
        cout<<"\n";
    }
    cout<<"f(1.9000000000)";
    double u,output=q[0];
    x=1.9;
    for(int o=0;o<9;o++)
        {
            u=1;
            for (int s=0 ; s<=o ; s++)
            {
                u=u*(x-T[s]);
            }
            output= output + q[o+1]*u;
            cout<<"\t"<<output;
        }
}