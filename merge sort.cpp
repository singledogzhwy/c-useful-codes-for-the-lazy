#include<iostream>
#include<time.h>
using namespace std;

void hebing(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1,m = mid,n = last,k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
      
    while (i <= m && j > n)  
        temp[k++] = a[i++];  
      
    while (j <= n && i > m)  
        temp[k++] = a[j++];  
      
    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  
}  
void mergesort(int a[], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort(a, first, mid, temp);      
        mergesort(a, mid + 1, last, temp);  
        hebing(a, first, mid, last, temp); 
    }  
}  
  
int main()  
{  	
	clock_t tstart,end;
	tstart = clock();

	int i,k,n,mark;
	int array[100000];

	for(i=0;i<100000;i++)
	{
		printf("please input array[%d] value(input 0 for end): ",i);
		scanf("%d",&k);
		if(k==0)
		{
			mark=i;
			break;
		}
		array[i]=k;
	}
	cout<<endl;

	int *p = new int[mark + 1];  
    if (p == NULL)  
		cout<<"error"<<endl; 
    
	mergesort(array, 0, mark, p);
	
	for(i=1;i<=mark;i++)
	{
		cout<<*(p + i)<<" ";
	}

	end = clock();
	printf("Run time: %d ",end - tstart);
	system("pause");
    delete[] p;  
    return true;  
}  