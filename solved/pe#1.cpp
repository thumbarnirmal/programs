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
		long long m3, m5, m15, ans;
		m3 = (n-1)/3;
		m5 = (n-1)/5;
		m15 = (n-1)/15;
		ans = 3*m3*(m3+1)/2 + 5*m5*(m5+1)/2 - 15*m15*(m15+1)/2;
		cout << ans << endl;
	}
	return 0;
}