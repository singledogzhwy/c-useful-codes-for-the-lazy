#include <iostream>
#include <cmath>
using namespace std;

#define NUM 5 //给出的点数量

int main()
{
    cout<<"按X值从小到大顺序输入节点Xi,Yi\n";
    double x[NUM],y[NUM],h[NUM],A[NUM],B[NUM],a[NUM],b[NUM],m[NUM+1];
    for(int i=0;i<NUM;i++)
    {
        cin>>x[i];
        cin>>y[i];
    }
    for(int i=0;i<NUM;i++)
    {
        h[i]=x[i+1]-x[i];
    }
    cout<<"第几种边界条件？\n";
    int kind;
    cin>>kind;
    switch(kind)
    {
    case 1:
        cout<<"输入微商值m0,mn\n";
        cin>>m[0];cin>>m[NUM-1];
        A[0]=0;A[NUM-1]=1;
        B[0]=2*m[0];B[NUM-1]=2*m[NUM-1];
        for(int i=1;i<NUM-1;i++)
        {
            A[i]=h[i-1]/(h[i-1]+h[i]);
            B[i]=3*(((1-A[i])/h[i-1])*(y[i]-y[i-1]) + A[i]/h[i]*(y[i+1]-y[i]));
        }
        for(int i=1;i<NUM-1;i++)                //之后的代码与case1相同
        {
            A[i]=h[i-1]/(h[i-1]+h[i]);
            B[i]=3*(((1-A[i])/h[i-1])*(y[i]-y[i-1]) + A[i]/h[i]*(y[i+1]-y[i]));
        }
        a[0]=-(A[0]/2);b[0]=B[0]/2;
        for(int i=1;i<NUM;i++)
        {
            a[i]=-(A[i]/(2+(1-A[i])*a[i-1]));
            b[i]=(B[i]-((1-A[i])*b[i-1]))/(2+(1-A[i])*a[i-1]);
        }
        m[NUM]=0;
        for(int i=NUM-2;i>0;i--)
        {
            m[i]=a[i]*m[i+1] + b[i];
        }
        
        cout<<"所求点的x值\n";
		double xx;double ans;
        cin>>xx;
        for(int i=0;i<=NUM-1;i++)
        {
            if(xx<x[i+1] && xx>=x[i])
			{ 
				ans=(1 + 2*((xx-x[i]) / h[i]))   * pow(((x[i+1]-xx) / h[i]),2) *y[i] + 
					(1 - 2*((xx-x[i+1]) / h[i])) * pow(((xx-x[i])  / h[i]),2)  *y[i+1] + 
					(xx-x[i])  * pow((x[i+1]-xx) / h[i],2)* m[i] + 
					(xx-x[i+1])* pow((xx-x[i])   /h[i],2) * m[i+1];
			}
		}
		cout<<ans;
		system("pause");
		return 0;
    case 2:
        A[0]=1;A[NUM-1]=0;
        B[0]=3/h[0] *(y[1]-y[0]);
		B[NUM-1]=3/h[NUM-2] *(y[NUM-1]-y[NUM-2]);
		for(int i=1;i<NUM-1;i++)                //之后的代码与case1相同
        {
            A[i]=h[i-1]/(h[i-1]+h[i]);
            B[i]=3*(((1-A[i])/h[i-1])*(y[i]-y[i-1]) + A[i]/h[i]*(y[i+1]-y[i]));
        }
        a[0]=-(A[0]/2);b[0]=B[0]/2;
        for(int i=1;i<NUM;i++)
        {
            a[i]=-(A[i]/(2+(1-A[i])*a[i-1]));
            b[i]=(B[i]-((1-A[i])*b[i-1]))/(2+(1-A[i])*a[i-1]);
        }
        m[NUM]=0;
        for(int i=NUM;i>=0;i--)
        {
            m[i]=a[i]*m[i+1] + b[i];
        }
        
        cout<<"所求点的x值\n";
        cin>>xx;
        for(int i=0;i<=NUM-1;i++)
        {
            if(xx<x[i+1] && xx>=x[i])
			{ 
				ans=(1 + 2*((xx-x[i]) / h[i]))   * pow(((x[i+1]-xx) / h[i]),2) *y[i] + 
					(1 - 2*((xx-x[i+1]) / h[i])) * pow(((xx-x[i])  / h[i]),2)  *y[i+1] + 
					(xx-x[i])  * pow((x[i+1]-xx) / h[i],2)* m[i] + 
					(xx-x[i+1])* pow((xx-x[i])   /h[i],2) * m[i+1];
			}
		}
		cout<<ans;
		system("pause");
		return 0;
        default:cout<<"error";return 0;
    }
    
    return 0;
}
