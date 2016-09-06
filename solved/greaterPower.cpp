#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long a, b, m, n;
		cin >> a >> b >> m >> n ;
		if(a == 1 && m == 1)
		{
			cout << -1 << endl;
			continue;
		}
		if(b == 0 && n == 0)
		{
			cout << -1 << endl;
			continue;
		}
		if(b*log(a) - n*log(m) > 0)
			cout << 1 << endl;
		else if(b*log(a) - n*log(m) < 0)
			cout << 0 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}