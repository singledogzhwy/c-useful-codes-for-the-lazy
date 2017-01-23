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
	int n; //n*n�׾���
	int k;
	int M;
	double T;
	double e;

	double **A;
	double *b;
	double *g;
	double *x;
	double *y;

	cout << "������������" << endl;
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


//����A��b,Y��e
	cout << "����A����" << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> A[i][j];
		}
	}

	cout << "�����Ҷ��" << endl;
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
	}

	cout << "�����ʼ����Y��" << endl;
	for(int i=0;i<n;i++)
	{
		cin >> y[i];
	}

	cout << "�����������e��" << endl;
	cin >> e;

	cout << "������������������M��" << endl;
	cin >> M;

	k = 1;
//�γɵ�������B�������A�У�
	for(int i=0;i<n;i++)
	{
		if(fabs(A[i][i]) < e){
			cout << "���ʧ��" << endl;
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

//����
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
			cout << "�����������������������ʧ��"  << endl;
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