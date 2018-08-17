#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
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

long long gcd(long long a, long long b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int p;
		cin >> p;
		char fraction[30];
		cin >> fraction;
		int len = strlen(fraction);
		long long a = 0, b, temp;
		int upow = len-p-2, unum = 0;
		for(int i = 2;i < upow+2;++i)
		{
			unum = unum*10 + fraction[i] - '0';
		}
		for(int i = upow+2;i < len;++i)
		{
			a = a*10 + fraction[i] - '0';
		}
		if(p == 0)
		{
			a = unum;
			b = numpow(10,upow);
			temp = gcd(a, b);
			a /= temp;
			b /= temp;
			cout << a << "/" << b << endl;
			continue;
		}
		b = numpow(10,p) - 1;
		temp = gcd(a, b);
		a /= temp;
		b /= temp;
		a = unum*b + a;
		b = b*numpow(10,upow);
		temp = gcd(a, b);
		a /= temp;
		b /= temp;
		cout << a << "/" << b << endl;
	}
	return 0;
}