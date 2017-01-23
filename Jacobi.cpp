#include<iostream>
#include<cmath>
using namespace std;

void swap(double &a,double &b)
{
	double tem;
	tem = a;
	a = b;
	b = tem;
}

int main()
{
	int n; //n*n阶矩阵
	int k;
	int M;
	double T;
	double e;

	double **A;
	double *b;
	double *g;
	double *x;
	double *y;

	cout << "输入矩阵阶数：" << endl;
	cin >> n;

	A = new double*[n];
	for(int i=0;i<n;i++)
	{
		A[i] = new double[n];
	}

	b = new double[n];

	g = new double[n];

	x = new double[n];

	y = new double[n];


//输入A，b,Y及e
	cout << "输入A矩阵：" << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> A[i][j];
		}
	}

	cout << "输入右端项：" << endl;
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
	}

	cout << "输入初始向量Y：" << endl;
	for(int i=0;i<n;i++)
	{
		cin >> y[i];
	}

	cout << "输入容许误差e：" << endl;
	cin >> e;

	cout << "输入容许最大迭代次数M：" << endl;
	cin >> M;

	k = 1;
//形成迭代矩阵B（存放在A中）
	for(int i=0;i<n;i++)
	{
		if(fabs(A[i][i]) < e){
			cout << "求解失败" << endl;
			exit(1);
		}
		T = A[i][i];
		for(int j=0;j<n;j++)
		{
			A[i][j]= -(A[i][j]/T);
		}
		A[i][i] = 0;
		g[i] = b[i]/T;
	}

//迭代
	while(true)
	{
		for(int i=0;i<n;i++)
		{
			T = 0;
			for(int j=0;j<n;j++)
			{
				if(i == j) continue;
				T += A[i][j]*y[j];
			}
			x[i] = g[i] + T;
		}
		T = 0;
		for(int i=0;i<n;i++)
		{
			T += pow(x[i]-y[i],2);
		}

		if(fabs(sqrt(T)) < e){
			for(int i=0;i<n;i++)
			{
				cout << "x[" << i+1 << "] = " << x[i] << endl;
			}
			cout << "k = " << k << endl;
			break;
		}

		if(k >= M){
			cout << "T = " << sqrt(T) << endl;
			cout << "超出容许最大迭代次数，求解失败"  << endl;
			exit(1);
		}
		k++;
		for(int i=0;i<n;i++)
		{
			y[i] = x[i];
		}
	}

	system("pause");
}