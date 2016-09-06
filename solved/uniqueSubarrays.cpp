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
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n];
		long long sum = 0, temp;
		for(int i = 0;i < n;++i)
			cin >> arr[i];
		map<int, int> m;
		int start = 0, end = 0;
		m[arr[end]] = 1;
		while(end != n-1)
		{
			end++;
			if(m.find(arr[end]) == m.end())
			{
				m[arr[end]] = 1;
				continue;
			}
			else
			{
				end--;
				temp = end-start+1;
				sum += ((temp*(temp+1)/2)*(temp+2))/3;
				while(arr[start] != arr[end+1])
				{
					m.erase(arr[start]);
					start++;
				}
				m.erase(arr[start]);
				start++;
				temp = end-start+1;
				sum -= ((temp*(temp+1)/2)*(temp+2))/3;
				end++;
				m[arr[end]] = 1;
			}
		}
		temp = end-start+1;
		sum += ((temp*(temp+1)/2)*(temp+2))/3;
		cout << sum << endl;
	}
	return 0;
}