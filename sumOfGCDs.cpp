#include <iostream>
#include <fstream>
using namespace std;

long long numpow(long long base, long long power)
{
	long long result = 1;
	while(power > 0)
	{
		if(power&1)
			result = base*result;
		base = base*base;
		power /= 2;
	}
	return result;
}

long long sumofgcd(long long p, long long e)
{
	return numpow(p,e-1)*((p-1)*e+p);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long n, sum = 1;
		cin >> n;
		long long factors[n+2] = {0}, lastfactor = 2;
		while(n%2 == 0)
		{
			factors[2]++;
			n /= 2;
		}
		for(long long i = 3;i*i <= n;i = i+2)
		{
			lastfactor = i;
			if(n%i == 0)
			{
				factors[i]++;
				n /= i;
			}
		}
		if(n > 2)
			factors[n]++;
		if(factors[2] != 0)
		    sum = (sum * sumofgcd(2,factors[2]))%1000000007;
		for(int i = 3;i <= lastfactor;i=i+2)
		{
			if(factors[i] != 0)
			{
				sum = (sum * sumofgcd(i,factors[i]))%1000000007;
			}
		}
		sum = (sum * sumofgcd(n,factors[n]))%1000000007;
		cout << sum << endl;
	}
	return 0;
}