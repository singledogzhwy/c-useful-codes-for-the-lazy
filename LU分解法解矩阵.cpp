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
	double a[n][n],l[n][n],u[n][n],b[n],x[n],y[n],e;
	cout<<"input a\n";
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			cin>>a[i][j];
	cout<<"input b\n";
	for(int i=1;i<n;i++)
		cin>>b[i];
	cout<<"input e\n";
	cin>>e;

	for(int k=1;k<n;k++)
	{
		for(int j=k;j<n;j++)
		{
			double sum=0; 
			for(int m=1;m<k;m++)
			{
				sum=sum+ l[k][m]*u[m][j];
			}
			u[k][j]=a[k][j]-sum;
			if(fabs(u[k][k])<e)
			{
				cout<<"fail\n";
				return 0;
			}
			for(int i=k+1;i<n;i++)
			{
				double sum=0; 
				for(int m=1;m<k;m++)
				{
					sum=sum+ l[i][m]*u[m][k];	
				}
				l[i][k]=(a[i][k]-sum)/u[k][k] ;
			}
		}
	}

	y[1]=b[1];
	for(int i=2;i<n;i++)
	{
		double sum=0;
		for(int m=1;m<i;m++)
		{
			sum=sum+ l[i][m]*y[m];
		}
		y[i]=b[i]-sum;
	}


	x[n-1]=y[n-1]/u[n-1][n-1];
	for(int i=n-2;i>=1;i--)
	{
		double sum=0;
		for(int m=i+1;m<n;m++)
		{
			sum=sum+ u[i][m]*x[m];
		}
		x[i]=(y[i]-sum)/u[i][i];
	}

	for(int i=1;i<n;i++)
	cout<<x[i]<<endl;
	system("pause");
	return 0;
}