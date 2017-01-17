#include<iostream>
#include<cmath>
using namespace std;

#define n 4  //ÐÐÁÐÊý+1

void myswap(double &a, double &b)  
{  
    double tmp = 0;  
    tmp = b;  
    b = a;  
    a = tmp;   
}  
int main()
{
	double e,t,a[n][n],b[n],x[n];
	cout<<"input a\n";
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			cin>>a[i][j];
	cout<<"input b\n";
	for(int i=1;i<n;i++)
		cin>>b[i];
	cout<<"input e\n";
	cin>>e;

	for(int k=1;k<n-1;k++)
	{
		for(int i=k;i<n;i++)
		{
			if(i==k)
				t=fabs(a[i][k]);
			else if(t<fabs(a[i][k]))
			{
				t=a[i][k];
				for(int j=k;j<n;j++)
					myswap(a[i][j],a[k][j]);
				myswap(b[i],b[k]);
			}
		}
		for(int i=k+1;i<n;i++)
		{
			t=a[i][k]/a[k][k];
			b[i]=b[i]-t*b[k];
			for(int j=1;j<n;j++)
					a[i][j]=a[i][j]-t*a[k][j];
		}
	}
	x[n-1]=b[n-1]/a[n-1][n-1];
		
	for(int i=n-2;i>=1;i--)
	{
		double sum=0;
			for(int j=i+1;j<n;j++)
			{
			sum=sum+(a[i][j]*x[j]);
			}
		x[i]=(b[i] - sum)/a[i][i];
	}
	for(int i=1;i<n;i++)
		cout<<x[i]<<endl;
	system("pause");
	
	return 0;
}