#include <iostream>
#include <cstdlib>
using namespace std;
#define MOD 1000000007

void matmult(long long a[][2], long long b[][2], long long c[][2])
{
	long long temp[2][2];
	temp[0][0] = ((a[0][0]*b[0][0])%MOD + (a[0][1]*b[1][0])%MOD)%MOD;
	temp[0][1] = ((a[0][0]*b[0][1])%MOD + (a[0][1]*b[1][1])%MOD)%MOD;
	temp[1][0] = ((a[1][0]*b[0][0])%MOD + (a[1][1]*b[1][0])%MOD)%MOD;
	temp[1][1] = ((a[1][0]*b[0][1])%MOD + (a[1][1]*b[1][1])%MOD)%MOD;
	c[0][0] = temp[0][0];
	c[0][1] = temp[0][1];
	c[1][0] = temp[1][0];
	c[1][1] = temp[1][1];
	return;
}

void matpow(long long C[][2], long long n, long long result[][2])
{
	result[0][0] = 1;
	result[0][1] = 0;
	result[1][0] = 0;
	result[1][1] = 1;
	while(n > 0)
	{
		if(n&1)
			matmult(result, C, result);
		matmult(C, C, C);
		n /= 2;
	}
	return;
}

long long fibonacci(long long n, long long a, long long b)
{
	if(n > 2)
	{
		long long C[2][2] = {{a,b},{1,0}}, result[2][2];
		matpow(C, n-1, result);
		return ((result[0][0]*a)%MOD + result[0][1])%MOD;
	}
	else
		return a*a + b;
}

int main()
{
	long long a, b, n;
	cin >> a >> b >> n;
	if(n == 0)
		cout << 1;
	else if(n == 1)
		cout << a;
	else
		cout << fibonacci(n, a, b);

	return 0;
}