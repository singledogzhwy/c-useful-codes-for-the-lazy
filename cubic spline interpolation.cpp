# include<iostream>
# include<cmath>
# include<iomanip>
using namespace std;
int main()
{
	int n;
	char judge;
	double xx=0;
	double yy=0;

	cin >> n;

	double *xi = new double[n+1];
	double *yi = new double[n+1];
	double *alpha = new double[n+1];
	double *beta = new double[n+1];
	double *ai = new double[n+1];
	double *bi = new double[n+1];
	double *mi = new double[n+1];
	double *hi = new double[n];

	for(int i=0;i<n+1;i++)
	{
		cin >> xi[i] >> yi[i];
	}

	cin >> xx;

	for(int i=0;i<n;i++)
	{
		hi[i] = xi[i+1]-xi[i];
	}

	cout << "请输入属第几种边界条件（1或2）:";
	while(cin >> judge)
	{
		if(judge < 49 || judge > 50)
		{
			cout << "非法输入，请重新输入边界条件（1或2）:";
			continue;
		}
		break;
	}

	if(judge == 1)
	{
		cout << "请输入m0，mn" << endl;
		cin >> mi[0] >> mi[n];
		alpha[0] = 0;
		beta[0] = 2*mi[0];
		alpha[n] = 1;
		beta[n] = 2*mi[n];
	}
	else
	{
		alpha[0] = 1;
		beta[0] = 3*(yi[1] - yi[0])/hi[0];
		alpha[n] = 0;
		beta[n] = 3*(yi[n] - yi[n-1])/hi[n-1];
	}

	for(int i=1;i<n;i++)
	{
		alpha[i] = hi[i-1]/(hi[i-1]+hi[i]);
		beta[i] = 3*((1-alpha[i])*(yi[i]-yi[i-1])/hi[i-1] + alpha[i]*(yi[i+1]-yi[i])/hi[i]);
	}

	ai[0] = -alpha[0]/2;
	bi[0] = beta[0]/2;
	for(int i=1;i<n+1;i++)
	{
		ai[i] = - alpha[i]/(2+(1-alpha[i])*ai[i-1]);
		bi[i] = (beta[i]-(1-alpha[i])*bi[i-1])/(2+(1-alpha[i])*ai[i-1]);
	}

	mi[n] = bi[n];
	for(int i=n-1;i >= 0;i--)
	{
		mi[i] = ai[i]*mi[i+1]+bi[i];
	}

	int k=0;
	for(;k<n;k++)
	{
		if(xx >= xi[k] && xx <= xi[k+1]) break;
	}

	yy = (1+2*(xx-xi[k])/(xi[k+1]-xi[k]))*pow((xx-xi[k+1])/(xi[k]-xi[k+1]),2)*yi[k] + (1+2*(xx-xi[k+1])/(xi[k]-xi[k+1]))*pow((xx-xi[k])/(xi[k+1]-xi[k]),2)*yi[k+1] + (xx-xi[k])*pow((xx-xi[k+1])/(xi[k]-xi[k+1]),2)*mi[k] + (xx-xi[k+1])*pow((xx-xi[k])/(xi[k+1]-xi[k]),2)*mi[k+1];

	cout << yy << endl;
	system("pause");
}