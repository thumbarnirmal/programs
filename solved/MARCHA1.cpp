#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int test, n, m;
	cin >> test;
	for(int t = 1;t <= test;++t)
	{
		cin >> n >> m;
		int notes[n], index, foundflag = 0;

		for(int i = 0;i < n;++i)
			cin >> notes[i];
		long long last = (1<<n) - 1, temp, sum;

		for(long long i = 0;i <= last;++i)
		{
			temp = i;
			sum = 0;
			index = 0;
			while(index < n)
			{
				if(temp&1)
					sum += notes[index];
				temp >>= 1;
				index++;
				if(sum > m)
					break;
			}
			if(sum == m)
			{
				cout << "Yes" << endl;
				foundflag = 1;
				break;
			}
		}

		if(foundflag == 0)
			cout << "No" << endl;
	}
	return 0;
}