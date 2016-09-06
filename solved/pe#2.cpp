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
		long long a = 1, b = 2, sum = 0, temp;
		while(b <= n)
		{
			sum += b;
			temp = a;
			a = a+2*b;
			b = 2*temp+3*b;
		}
		cout << sum << endl;
	}
	return 0;
}