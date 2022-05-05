#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<complex>

using namespace std;

int n,itr,iter,error=0,set;
double x,xr,c,cold,xl,f,es,ea,y,test1,fa,fb,fc;
double fm(int n,double x)
{
	if(n==1){y = pow(x,3) - pow(x,2) - 1.0;}
	else if(n==2){y = x-exp(-pow(x,2));}
	else if(n==3){y = sqrt(x)-cos(x);}
	else if(n==4){y = log(x)+x;}
	else if(n==5){y = pow(x,4)+2.0*(pow(x,3))-7.0*(pow(x,2))-8.0*(x)+12.0;}
	else{y = sin(x)+3*cos(x)-2.0;}
	return y;
}
void bisect(double f,double a,double b,int n)
{
	cout.precision(10);
	cout.setf(ios::fixed);
	test1 = fm(n,a)*fm(n,b);
	if(test1>=0)
	{
		cout<<"\n There are no roots or even number of roots found b/w your bounded input, Please try another.";
		error = 1;
	}
	es=pow(10,-10);
	itr=0; c=a; ea=100;
	if(error==0)
	{
		cout<<"\nItr\t(xl)\t\tf(xl)\t\t(xu)\t\tf(xu)\t\t(xr)\t\tf(xr)\t\t\t|Ea|(%)\n";
	}
	while(error!=1&&set!=1)
	{
		cold=c;
		itr=itr+1;
		fa=fm(n,a);
	    fb=fm(n,b);
	    c=b-(fb*(a-b)/(fa-fb));
	    //c=(a+b)/2.0;
	    fc=fm(n,c);
	    if (fabs(a-c)>es)
		{
			iter=itr;
		}
		cout<<itr-1<<"\t"<<a<<"\t"<<fa<<"\t"<<b<<"\t"<<fb<<"\t"<<c<<"\t"<<fc<<"\t"<<ea<<endl;
		//if(c!=0){ea=abs((c-cold)/c)*100;}
		ea=abs((c-cold)/c)*100;
		double test = fa*fc;
		if(test<0)
		{
			b=c;
		}
		else if(test>0)
		{
			a=c;
		}
		else
		{
			ea=0;
		}
		if(ea<=es)
		{
			xr = c;
			cout<<" ROOT= "<<xr; 
			cout<<"\n ITERATION = "<<iter-1;
			char letter,letter1;
			cout << "\n Do You want to Reset (y/n)?  ";
			cin >> letter;
			if(letter=='y'){
				cout<<"\n a.) Reset the xl and xu only.\n b.) Choose diffirent Equation.\n (a or b): ";
				cin>>letter1;
				if(letter1=='a')
				{
					error=1;
				}
				else if(letter1=='b')
				{
					set=1;
				}
				else
				{
					break;
				}
			}
			if(letter=='n')
			{
				break;
			}
		}
	}	
}
int main()
{
	set:cout<<"\n Determine the root/s of the following functions:";set=0;
	cout<<"\n 1.f(X)=[x^3 + x^2 -1]\n 2.f(x)=[x-e^(-x^2)]";
	cout<<"\n 3.f(x)=[sqrt(x) - cos(x)]\n 4.f(x)=[log(x) + x]";
	cout<<"\n 5.f(x)=[x^4 + 2x^3 - 7x^2 - 8x + 12]";
	cout<<"\n 6.f(x)=[sin(x) + 3cos(x) - 2]";
	cout<<"\n\n Please specify any equation from (1-6) above: ";
	int n;
	cin>>n;
	error:cout<<"\n";error=0;
		if(n==1){cout<<" 1.f(X)=[x^3 + x^2 -1]\n";}
		else if(n==2){cout<<" 2.f(x)=[x-e^(-x^2)]\n";}
		else if(n==3){cout<<" 3.f(x)=[sqrt(x) - cos(x)]\n";}
		else if(n==4){cout<<" 4.f(x)=[log(x) + x]\n";}
		else if(n==5){cout<<" 5.f(x)=[x^4 + 2x^3 - 7x^2 - 8x + 12]\n";}
		else{cout<<"\n 6.f(x)=[sin(x) + 3cos(x) - 2]";}
	cout<<"\n Enter the value for bounded input [xl,xu]:";
	double xl,xu;
	cout<<"\n xl= ";
	cin>>xl;
	cout<<" xu= ";
	cin>>xu;	
	bisect(fm(n,x),xl,xu,n);
	if(error==1){goto error;}
	if(set==1){goto set;}
	return 0;
}
