
#include<iostream>
#include<stdlib.h>

using namespace std;
const int N = 1000;

int mycompare(const void*a, const void*b)
{
	return *(int*)b - *(int*)a;
}
int tili(int a[N], int len, int count)
{
	if (len == 1)
		return count;
	qsort(a, len, sizeof(int), mycompare);// �Ӵ�С
	a[len - 2] = a[len - 2] + a[len - 1];
	count += a[len - 2];//�����ı�
	tili(a, len - 1, count);
}


int main()
{
	int f;
	cin >> f;
	for (int q = 0; q < f; q++)
	{
		int count = 0;
		int a(N) = {0};
		int n , i;
		cin >> n;
		for (i = 0; i < n; i++)
			cin>>a[i];
		cout << tili(a, n, count) << endl;
	}
}