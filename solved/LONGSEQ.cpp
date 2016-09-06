#include <iostream>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	int t;
	char c;
	cin >> t;
	c = getchar();
	while(t--)
	{
		int count0 = 0, count1 = 0;
		c = getchar();
		while(c != '\n')
		{
			if(c == '1')
				count1++;
			else if(c == '0')
				count0++;
			c = getchar();
		}
		if(count0 == 1 || count1 == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}