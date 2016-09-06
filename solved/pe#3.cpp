#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long n;
		cin >> n;
		long long p;
		while(n%2 == 0)
		{
			n /= 2;
			p = 2;
		}
		for(long long i = 3;i*i <= n;i += 2)
		{
			while(n%i == 0)
			{
				n /= i;
				p = i;
			}
		}
		if(n > 2)
			p = n;
		cout << p << endl;
	}
	return 0;
}