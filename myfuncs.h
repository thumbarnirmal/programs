#define MOD 1000000007

#ifndef SIEVE
#define SIEVE

void sieve()
{
	int sieve[1000001] = {0};
	sieve[0] = sieve[1] = 1;
	for(int i = 2;i*i <= 1000000;++i)
	{
		if(sieve[i] == 1)
			continue;
		for(int j = i+i;j <= 1000000;j += i)
			sieve[j] = 1;
	}
}

#endif

#ifndef NUMPOW
#define NUMPOW

long long numpow(long long base, long long power)
{
	long long result = 1;
	while(power > 0)
	{
		if(power&1)
			result = base*result;
		base = base*base;
		power /= 2;
	}
	return result;
}

#endif

#ifndef MATMULT
#define MATMULT

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

#endif

#ifndef MATPOW
#define MATPOW

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

#ifndef FIBONACCI
#define FIBONACCI

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

#endif

#ifndef GCD
#define GCD

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

#endif

#ifndef CHOOSEPIVOT
#define CHOOSEPIVOT

int choosepivot(int *a, int low, int high)
{
	return rand() % (high - low + 1) + low;
}

#endif

#ifndef PARTITION
#define PARTITION

int partition(int *a, int low, int high)
{
	int p = a[low], i = low + 1, temp;
	for(int j = low+1;j <= high;++j)
	{
		if(a[j] < p)
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			++i;
		}
	}
	temp = a[low];
	a[low] = a[i-1];
	a[i-1] = temp;
	return i-1;
}

#endif

#ifndef QUICKSORT
#define QUICKSORT

void quicksort(int *a, int low, int high)
{
	if(low >= high)
		return;
	int p = choosepivot(a, low, high);
	int temp = a[p];
	a[p] = a[low];
	a[low] = temp;
	p = partition(a, low, high);
	quicksort(a, low, p-1);
	quicksort(a, p+1, high);
}

#endif

#ifndef BINARYSEARCH
#define BINARYSEARCH

int binarysearch(int *a, int low, int high, int key)
{
	int mid = (low+high)/2;
	if(a[mid] == key)
		return mid;
	else if(low > high)
		return -1;
	else if(a[mid] > key)
		return binarysearch(a, low, mid-1, key);
	else
		return binarysearch(a, mid+1, high, key);
}

#endif

#ifndef MERGE
#define MERGE

void merge(int *a, int low, int mid, int high)
{
	int i = low, j = mid+1, k = 0, temp[high-low+1];
	while(i <= mid && j <= high)
	{
		if(a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while(i <= mid)
		temp[k++] = a[i++];
	while(j <= high)
		temp[k++] = a[j++];
	for(i = low;i <= high;++i)
		a[i] = temp[i-low];
	return;
}

#endif

#ifndef MERGESORT
#define MERGESORT

void mergesort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid+1, high);
		merge(a, low, mid, high);
	}
	return;
}

#endif