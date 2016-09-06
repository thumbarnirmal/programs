#include <iostream>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;

#ifndef CHOOSEPIVOT
#define CHOOSEPIVOT

int choosepivot(int *a, int low, int high)
{
	return rand() % (high - low + 1) + low;
}

#endif

#ifndef PARTITION
#define PARTITION

int partition(int *a, int low, int high)
{
	int p = a[low], i = low + 1, temp;
	for(int j = low+1;j <= high;++j)
	{
		if(a[j] < p)
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			++i;
		}
	}
	temp = a[low];
	a[low] = a[i-1];
	a[i-1] = temp;
	return i-1;
}

#endif

#ifndef QUICKSORT
#define QUICKSORT

void quicksort(int *a, int low, int high)
{
	if(low >= high)
		return;
	int p = choosepivot(a, low, high);
	int temp = a[p];
	a[p] = a[low];
	a[low] = temp;
	p = partition(a, low, high);
	quicksort(a, low, p-1);
	quicksort(a, p+1, high);
}

#endif

int main()
{
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	for(int i = 0;i < n;++i)
		for(int j = 0;j < m;++j)
			cin >> arr[i][j];
	int temp[n], ans[m];
	for(int j = 0;j < m;++j)
	{
		for(int i = 0;i < n;++i)
			temp[i] = arr[i][j];
		quicksort(temp, 0, n-1);
		if(n&1)
		{
			ans[j] = temp[n/2];
		}
		else
		{
			ans[j] = ((temp[n/2] + temp[n/2-1])/2) + 0.5;
		}
	}
	for(int i = 0;i < m;++i)
		cout << ans[i] << " ";
	return 0;
}