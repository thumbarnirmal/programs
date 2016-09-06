#include <stdio.h>
#define MOD 1000000007

void matmult(int m, long long a[][m], long long b[][m], long long c[][m])
{
	long long temp[m][m], sum;

	for(int i = 0;i < m;++i)
		for(int j = 0;j < m;++j)
		{
			sum = 0;
			for(int k = 0;k < m;++k)
				sum = (sum + ((a[i][k] * b[k][j])%MOD)) % MOD;
			temp[i][j] = sum;
		}

	for(int i = 0;i < m;++i)
		for(int j = 0;j < m;++j)
			c[i][j] = temp[i][j];

	return;
}

void matpow(int m, long long C[][m], long long n, long long result[][m])
{
	for(int i = 0;i < m;++i)
		for(int j = 0;j < m;++j)
			result[i][j] = 0;

	for(int i = 0;i < m;++i)
		result[i][i] = 1;

	while(n > 0)
	{
		if(n&1)
			matmult(m, result, C, result);
		matmult(m, C, C, C);
		n /= 2;
	}
	return;
}

int main()
{
	int m;
	scanf("%d",&m);
	long long a[m][m], n, result[m][m], sum = 0;

	for(int i = 0;i < m;++i)
		for(int j = 0;j < m;++j)
			scanf("%lld",&a[i][j]);

	scanf("%lld",&n);
	matpow(m, a, n, result);

	for(int i = 0;i < m;++i)
		for(int j = 0;j < m;++j)
			sum = (sum + result[i][j])%MOD;

	printf("%lld",sum);

	return 0;
}