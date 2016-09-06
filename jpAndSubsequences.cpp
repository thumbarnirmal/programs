#include <iostream>
#include <cstdlib>
using namespace std;
#define MOD 1000000007

long long count = 0;
int k = 0, end;

void backtrack(long long arr[], int pos, int posSelected, long long sum)
{
	// cout << "pos :" << pos << endl;
	if(pos == end)
	{
		if(arr[pos] > arr[posSelected])
		{
			long long temp = sum;
			temp  = (temp+arr[pos]) % MOD;
			if(temp < k)
			{
				count++;
				sum = temp;
			}
			return;
		}
		else
			return;
	}
	if(arr[pos] > arr[posSelected])
	{
		long long temp = sum;
		temp  = (temp+arr[pos]) % MOD;
		if(temp < k)
		{
			count++;
			backtrack(arr, pos+1, pos, temp);
		}
	}
	backtrack(arr, pos+1, posSelected, sum);
	return;
}

int main()
{
	int n;
	cin >> n >> k;
	end = n;
	long long arr[n+1];
	arr[0] = 0;
	for(int i = 1;i <= n;++i)
		cin >> arr[i];
	backtrack(arr, 1, 0, 0);
	cout << count;
	return 0;
}