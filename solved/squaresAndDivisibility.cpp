#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;

int sd(long long i, long long j)
{
	if((i*i-1)%j == 0 && (j*j-1)%i == 0)
		return 1;
	return 0;
}

int main()
{
	long long t;
	cin >> t;

	while(t--)
	{
		long long n, count = 0, temp;
		cin >> n;
		for(long long k = 2;k <= n;++k)
		{
			long long i = 1, j = k;
			while(sd(i,j) && j<=n)
			{
				count++;
				temp = i;
				i = j;
				j = (j*j-1)/temp;
			}
		}
		cout << count << endl;
	}
	return 0;
}