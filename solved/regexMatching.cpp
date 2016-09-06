#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char a[100000], b[100000];
		cin >> a;
		cin >> b;
		int lena = strlen(a), lenb = strlen(b);
		if(a[0] == '^')
		{
			int breakflag = 0;
			for(int i = 1;i < lena;++i)
			{
				if(a[i] == b[i-1])
					continue;
				else
				{
					breakflag = 1;
					break;
				}
			}
			if(breakflag == 1)
			{
				cout << 0 << endl;
				continue;
			}
			cout << 1 << endl;
			continue;
		}
		if(a[lena-1] == '$')
		{
			int breakflag = 0;
			for(int i = lena-2,j = lenb-1;i >= 0;--i,--j)
			{
				if(a[i] == b[j])
					continue;
				else
				{
					breakflag = 1;
					break;
				}
			}
			if(breakflag == 1)
			{
				cout << 0 << endl;
				continue;
			}
			cout << 1 << endl;
			continue;
		}
		int breakflag = 0, matched = 0;
		for(int j = 0;j <= lenb-lena+1;++j)
		{
			if(a[0] == b[j])
			{
				int i = 0, k = j;
				breakflag = 0;
				while(a[i] != '\0')
				{
					if(a[i] != b[k])
					{
						breakflag = 1;
						break;
					}
					i++;
					k++;
				}
				if(breakflag == 0)
				{
					matched = 1;
					cout << 1 << endl;
					break;
				}
			}
		}
		if(matched == 1)
			continue;
		cout << 0 << endl;
	}
	return 0;
}