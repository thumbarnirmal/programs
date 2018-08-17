#include <iostream>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;

void merge(int a[][2], int low, int mid, int high, int column)
{
	int i = low, j = mid+1, k = 0, temp[high-low+1][2];
	int index = (column == 1)?0:1;
	while(i <= mid && j <= high)
	{
		if(a[i][column] < a[j][column])
		{
			temp[k++][column] = a[i++][column];
			temp[k-1][index] = a[i-1][index];
		}
		else
		{
			temp[k++][column] = a[j++][column];
			temp[k-1][index] = a[j-1][index];
		}
	}
	while(i <= mid)
	{
		temp[k++][column] = a[i++][column];
		temp[k-1][index] = a[i-1][index];
	}
	while(j <= high)
	{
		temp[k++][column] = a[j++][column];
		temp[k-1][index] = a[j-1][index];
	}
	for(i = low;i <= high;++i)
	{
		a[i][column] = temp[i-low][column];
		a[i][index] = temp[i-low][index];
	}
	return;
}

void mergesort(int a[][2], int low, int high, int column)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(a, low, mid, column);
		mergesort(a, mid+1, high, column);
		merge(a, low, mid, high, column);
	}
	return;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n][2], b[m];
		long long sum = 0;
		for(int i = 0;i < n;++i)
		{
			cin >> a[i][0];
			a[i][1] = i;
		}
		for(int i = 0;i < m;++i)
			cin >> b[i];
		mergesort(a, 0, n-1, 0);
		mergesort(a, n-m, n-1, 1);
		for(int i = 0;i < m;++i)
		{
			sum = sum + (long long)(a[i+n-m][0]*(long long)b[i]);
		}
		cout << sum << endl;
	}
	return 0;
}