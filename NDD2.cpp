#include<iostream>
#include<cmath>

using namespace std;

int main()
{   double start;


    double output;
    double T[8] = {0, 10, 20, 30, 40, 60, 80, 100};
    double P[8] = {0.0061, 0.0123, 0.0234, 0.0424, 0.0738, 0.1992, 0.4736, 1.0133};
    double h[7];
    double i[6];
    double j[5];
    double k[4];
    double l[3];
    double m[2];
    double q[8];
    q[0]=P[0];

    for (int o=0 ; o<7 ; o++)
    {
        h[o] = (P[o+1]-P[o])/(T[o+1]-T[o]);
    }
    q[1]=h[0];

    for (int o=0 ; o<6 ; o++)
    {
        i[o] = (h[o+1]-h[o])/(T[o+2]-T[o]);
    }
    q[2]=i[0];
    for (int o=0 ; o<5 ; o++)
    {
        j[o] = (i[o+1]-i[o])/(T[o+3]-T[o]);
    }
    q[3]=j[0];
    for (int o=0 ; o<4 ; o++)
    {
        k[o] = (j[o+1]-j[o])/(T[o+4]-T[o]);
    }
    q[4]=k[0];
    for (int o=0 ; o<3 ; o++)
    {
        l[o] = (k[o+1]-k[o])/(T[o+5]-T[o]);
    }
    q[5]=l[0];
    for (int o=0 ; o<2 ; o++)
    {
        m[o] = (l[o+1]-l[o])/(T[o+6]-T[o]);
    }
    q[6]=m[0];
    q[7]=(m[1]-m[0])/(T[7]-T[0]);
    for (int o=0 ; o<7 ; o++)
    {
        cout<<"\nDegree of Polynimial Order = "<<o+1<<endl;
        cout<<"F(T)= ";
        if (o==0)
         cout << q[0] << " + " << q[1] << "T\n";
        if(o==1)
         cout << q[0] << " + " << q[1] << "T + " << q[2] << "(T)(T-10)\n";
        if(o==2)
         cout << q[0] << " + " << q[1] << "T + " << q[2] << "(T)(T-10) + " << q[3] << "(T)(T-10)(T-20)\n";
        if(o==3)
         cout << q[0] << " + " << q[1] << "T + " << q[2] << "(T)(T-10) + " << q[3] << "(T)(T-10)(T-20) + " << q[4] << "(T)(T-10)(T-20)(T-30)\n";
        if(o==4)
        cout << q[0] << " + " << q[1] << "T + " << q[2] << "(T)(T-10) + " << q[3] << "(T)(T-10)(T-20) + " << q[4] << "(T)(T-10)(T-20)(T-30)"
         << (q[5]) << "(T)(T-10)(T-20)(T-30)(T-40)\n";
        if(o==5)
        cout << q[0] << " + " << q[1] << "T + " << q[2] << "(T)(T-10) + " << q[3] << "(T)(T-10)(T-20) + " << q[4] << "(T)(T-10)(T-20)(T-30) "
         << (q[5]) << "(T)(T-10)(T-20)(T-30)(T-40)\n\t\t\t + " << q[6] << "(T)(T-10)(T-20)(T-30)(T-40)(T-60)\n";
        if(o==6)
        cout << q[0] << " + " << q[1] << "T + " << q[2] << "(T)(T-10) + " << q[3] << "(T)(T-10)(T-20) + " << q[4] << "(T)(T-10)(T-20)(T-30) + "
         << abs(q[5]) << "(T)(T-10)(T-20)(T-30)(T-40)\n\t\t\t + " << q[6] << "(T)(T-10)(T-20)(T-30)(T-40)(T-60) " << (q[7]) << "(T)(T-10)(T-20)(T-30)(T-40)(T-60)(T-80)\n";
    }

    int x;
    cout.precision(10);
    cout.setf(ios::fixed);
    cout<<"\nOrder \t 1 \t\t 2 \t\t 3 \t\t 4 \t\t 5 \t\t 6 \t\t 7"<<endl;
    for(int x=0;x<=100;x=x+5)
    {
        double u,output=q[0];
        cout<<"f("<<x<<")";
        for(int o=0;o<7;o++)
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

}
