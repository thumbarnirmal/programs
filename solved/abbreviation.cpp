#include <iostream>
#include <cstdlib>
using namespace std;

int match(char *a, char *b)
{
	if(*a == '\0' && *b == '\0')
		return 1;
	if(*a == '\0')
		return 0;
	if(*a >= 'A' && *a <= 'Z')
	{
		if(*a == *b)
			return match(a+1, b+1);
		return 0;
	}
	if(*a - 'a' + 'A' == *b)
		return match(a+1, b) || match(a+1, b+1);
	return match(a+1, b);
}

int main()
{
	int t, result;
	char a[1003], b[1003];
	cin >> t;
	while(t--)
	{
		cin >> a;
		cin >> b;
		result = match(a, b);
		if(result == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}