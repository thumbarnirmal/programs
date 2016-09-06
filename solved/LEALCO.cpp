#include <iostream>
#include <cstdlib>
using namespace std;

int arrest(int *r, int n, int k, int m)
{
	for(int i = 0;i <= n-k;++i)
	{
		int max = -1, count = 0;
		for(int j = i;j < i+k;++j)
		{
			if(r[j] > max)
			{
				max = r[j];
				count = 1;
			}
			else if(r[j] == max)
			{
				count++;
			}
		}
		if(count >= m)
			return 1;
	}
	return 0;
}

int main()
{
	int test, n, k, m;
	cin >> test;
	for(int t = 1;t <= test;++t)
	{
		cin >> n >> k >> m;
		int r[n], j;
		for(int i = 0;i < n;++i)
			cin >> r[i];
		
		if(arrest(r, n, k, m) == 0)
		{
			cout << 0 << endl;
			continue;
		}

		long long last = (1<<n) - 1, temp;
		int min = 20, count;

		for(long long i = 0;i <= last;++i)
		{
			temp = i;
			j = 0;
			count = 0;
			while(j < n)
			{
				if(temp&1)
				{
					r[j]++;
					count++;
				}
				temp >>= 1;
				j++;
			}
			if(arrest(r, n, k, m) == 0)
			{
				min = count<min ? count : min;
			}
			temp = i;
			j = 0;
			while(j < n)
			{
				if(temp&1)
					r[j]--;
				temp >>= 1;
				j++;
			}
		}

		if(min == 20)
			cout << -1 << endl;
		else
			cout << min << endl;
	}
	return 0;
}