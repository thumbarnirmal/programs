#include <iostream>
#include <cstdlib>
using namespace std;

long long sieve[1000001] = {0}, primes[20002], sphenic[20002];
int scanned[20002][20002][20002] = {0}, sphenicCount = 0;

long long findSphenic(int a, int b, int c)
{
	return primes[a]*primes[b]*primes[c];
}

//Incomplete-------------------------------------------------
int buildSphenic(int a, int b, int c)
{
	if(scanned[a][b][c] == 0)
	{
		sphenic[sphenicCount++] = findSphenic(a,b,c);
		scanned[a][b][c] = 1;
	}
	if(a+1 = b && b+1 = c)
	{

	}
}
//Incomplete-------------------------------------------------

int main()
{
	sieve[0] = sieve[1] = 1;
	for(int i = 2;i*i <= 1000000;++i)
	{
		if(sieve[i] == 1)
			continue;
		for(int j = i+i;j <= 1000000;j += i)
			sieve[j] = 1;
	}
	int j = 0;
	for(int i = 0;i <= 1000000;++i)
	{
		if(sieve[i] == 0)
			primes[j++] = i;
		if(j == 20002)
			break;
	}

	buildSphenic(0,1,2);
	cout << findSphenic(0,1,2) << endl;

	return 0;
}