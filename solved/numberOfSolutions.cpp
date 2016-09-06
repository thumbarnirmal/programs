#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long b, p, count = 0;
		cin >> b >> p;
		for(long long i = 1;i < p;++i)
		{
			if((i*i)%p == 1)
				count++;
		}
		long long times = (int)(b/p);
		count = count * times;
		for(long long i = p*times+1;i <= b;++i)
		{
			if((i*i)%p == 1)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}