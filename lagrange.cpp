# include<iostream>
# include<cmath>
# include<iomanip>
using namespace std;
int main()
{
	int n;
	double xx=0;
	double yy=0;

	cin >> n;

	double *xi = new double[n];
	double *yi = new double[n];

	for(int i=0;i<n;i++)
	{
		cin >> xi[i] >> yi[i];
	}

	cin >> xx;

	for(int i=0;i<n;i++)
	{
		double t=1;
		for(int k=0;k<n;k++)
		{
			if(i == k) continue;
			t=t*((xx-xi[k])/(xi[i]-xi[k]));
		}
		yy = yy+t*yi[i];
	}

	cout << yy << endl;
	system("pause");
}