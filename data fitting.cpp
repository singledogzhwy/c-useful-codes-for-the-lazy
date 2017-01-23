# include<iostream>
# include<cmath>
# include<iomanip>
using namespace std;
int main()
{
	int n;
	double a=0;
	double b=0;
	double sx=0;
	double sy=0;
	double sxx=0;
	double sxy=0;

	cin >> n;

	double *xi = new double[n];
	double *yi = new double[n];

	for(int i=0;i<n;i++)
	{
		cin >> xi[i] >> yi[i];
	}
	
	for(int i=0;i<n;i++)
	{
		sx += xi[i];
		sy += yi[i];
		sxx += pow(xi[i],2);
		sxy += xi[i]*yi[i];
	}

	a = (sxx*sy - sx*sxy)/(n*sxx - pow(sx,2));
	b = (n*sxy - sx*sy)/(n*sxx - pow(sx,2));

	cout << "a = " << a << "   " << "b = " << b << endl;

	system("pause");
}