#include<iostream>							// include iostream lib
#include<cmath>								// include cmath lib

using namespace std;

double roots(int n)
{
    double r;								// Initialize r
	if(n==1){r = 1.4655712319;}             // root on number 1
	else if(n==2){r = 0.6529186404;}        // root on number 2
	else if(n==3){r = 0.6417143709;}        // root on number 3
	else if(n==4){r = 0.5671432904;}        // root on number 4
	else if(n==5){r = 1.0000000000;}        // root on number 5
	else if(n==6){r = 1.2078276782;}        // root on number 6
	return r;
}
double my_func(int n,double x) 				// Create a function that will select one Equation given.
{
	double y;								// Initialize y
	if(n==1){y = pow(x,3) - pow(x,2) - 1.0;}    // Item number 1
	else if(n==2){y = x-exp(-pow(x,2));}        // Item number 2
	else if(n==3){y = sqrt(x)-cos(x);}          // Item number 3
	else if(n==4){y = log(x)+x;}                // Item number 4
	else if(n==5){y = pow(x,4)+2.0*(pow(x,3))-7.0*(pow(x,2))-8.0*(x)+12.0;}// Item number 5
	else{y = sin(x)+3*cos(x)-2.0;}              // Item number 6
	return y;
}
// This will Create a function that calculate the root every iteration using Regula-Falsi method.
void regula_falsi(int m,int n, double xlower, double xupper,int dp)
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
                if(m==1){xrev = (xlower+xupper)/2;}
                if(m==2){xrev = xupper - (fxupper*(xlower-xupper)/(fxlower-fxupper));} // This computes the values of xrev
                double fxrev = my_func(n,xrev);     // This computes the values of f(xrev)
                    cout.precision(dp); cout.setf(ios::fixed);// to display 10 decimal places and fix the indention of values.
                    //et=abs((roots(n)-xrev)/roots(n))*100;     // Compute for the the True Percent Error.
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

int main()	// Create the main function with neccessary prompt initial.
{   cout<<"\n Determine the root/s of the following functions:";
	string item[6]; // Create array to store strings to display specific equation.
	item[0] = " 1.f(X)=[x^3 + x^2 -1]";
	item[1] = " 2.f(x)=[x-e^(-x^2)]";
	item[2] = " 3.f(x)=[sqrt(x) - cos(x)]";
	item[3] = " 4.f(x)=[log(x) + x]";
	item[4] = " 5.f(x)=[x^4 + 2x^3 - 7x^2 - 8x + 12]";
	item[5] = " 6.f(x)=[sin(x) + 3cos(x) - 2]";
	cout<<"\n"<<item[0]<<"\n"<<item[1]<<"\n"<<item[2]<<"\n"<<item[3]<<"\n"<<item[4]<<"\n"<<item[5];// display the given functions.
	cout<<"\n\n Please specify any equation from (1-6) above: ";

		int n; 								// initialize n
		n:cout<<"\n Item number = "; cin>>n;// input n
		cout<<"\n"<<item[n-1];              // display the choosen equation.
		int m; 								// initialize m
		cout<<"\n Use method = "; cin>>m;   // input m

		double xlower, xupper;									// initialize lower and upper root estimate
		cout<<"\n\n lower root estimate xlower = "; cin>>xlower;// input xlower and xupper
		cout<<" upper root estimate xupper = "; cin>>xupper;
        // Call regula_falsi function w/ inputs xlower, xupper to return root accurate up to 10th dp
		regula_falsi(m,n,xlower,xupper,10);

        char reset;
			cout << "\n Do You want to Reset (y/n)?  ";         // Ask to continue.
			cin >> reset;                                       // Input your decision to continue.
			if(reset=='y'){goto n;}                             // goto line 63 if you input y.

	return 0;
}
