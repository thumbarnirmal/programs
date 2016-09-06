#include <iostream>
#include <cstdlib>
using namespace std;

int binarysearch(unsigned int *a, int low, int high,unsigned int key)
{
	int mid = (low+high)/2;
	if(a[mid] == key)
		return mid;
	else if(low > high)
		return -1;
	else if(a[mid] > key)
		return binarysearch(a, low, mid-1, key);
	else
		return binarysearch(a, mid+1, high, key);
}

int linearsearch(unsigned int *a, int low, int high,unsigned int key)
{
	for(int i = low;i <= high;++i)
	{
		if(a[i] == key)
			return 1;
	}
	return 0;
}

int main()
{
	unsigned int f[5006], test, num;
	string number;
	f[0] = 0;
	f[1] = 1;
	for(int i = 2;i < 5006;++i)
	{
		f[i] = f[i-1] +  f[i-2];
	}
	cin >> test;
	for(int t = 1;t <= test;++t)
	{
		cin >> number;
		num = 0;
		for(int i = 0;number[i] >= '0' && number[i] <= '9';++i)
		{
			num = num * 10 + number[i] - '0';
		}
		if(linearsearch(f, 0, 5005, num) == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}