#include <iostream>
#include <cstdlib>
using namespace std;

int backtrack(int arr[], int pos, int end, int strength, int powerUsed)
{
	// cout << "pos :" << pos << endl;
	// cout << "strength :" << strength << endl;
	// cout << "powerUsed :" << powerUsed << endl << endl;
	if(pos == end)
	{
		if(strength + arr[pos] >= 0)
			return end+1;
		else if(powerUsed == 0 && strength - arr[pos] >= 0)
			return end+1;
		else
			return pos;
	}
	if(strength + arr[pos] < 0 && powerUsed == 1)
		return pos;
	if(powerUsed == 1)
	{
		return backtrack(arr, pos+1, end, strength+arr[pos], 1);
	}
	else
	{
		if(arr[pos] >= 0)
			return backtrack(arr, pos+1, end, strength+arr[pos], 0);
		if(strength+arr[pos] >= 0)
		{
			int result1, result2;
			result1 = backtrack(arr, pos+1, end, strength+arr[pos], 0);
			result2 = backtrack(arr, pos+1, end, strength-arr[pos], 1);
			return (result1>result2)?result1:result2;
		}
		else if(strength-arr[pos] >= 0)
		{
			return backtrack(arr, pos+1, end, strength-arr[pos], 1);
		}
		else return pos;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n], result;
		for(int i = 0;i < n;++i)
			cin >> arr[i];
		result = backtrack(arr, 0, n-1, 0, 0);
		if(result == n)
			cout << "She did it!" << endl;
		else
			cout << result+1 << endl;
	}
	return 0;
}