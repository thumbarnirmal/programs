#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int a, b, k;
	cin >> a >> b >> k;
	int sieve[1000001] = {0}, count[1000001];

	sieve[0] = sieve[1] = 1;
	for(int i = 2;i*i <= 1000000;++i)
	{
		if(sieve[i] == 1)
			continue;
		for(int j = i+i;j <= 1000000;j += i)
			sieve[j] = 1;
	}
	
	count[0] = 0;
	for(int i = 1;i <= 1000000;++i)
	{
		if(sieve[i] == 0)
			count[i] = count[i-1] + 1;
		else
			count[i] = count[i-1];
	}

	if(count[b]-count[a-1] < k)
	{
		cout << -1 << endl;
		return 0;
	}

	int start = a, end = a+k-1;
	while(end < b)
	{
		while(count[end]-count[start-1] < k && end < b)
		{
			end++;
		}
		if(end < b)
		{
			start++;
			end++;
		}
	}

	if(count[end]-count[start-1] < k)
		while(count[end]-count[start-1] < k)
			start--;
	cout << end-start+1 << endl;

	return 0;
}