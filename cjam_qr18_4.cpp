#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
//#include <vector>
//#include <queue>
#include <string>
//#include <map>
//#include <unordered_map>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ff first
#define ss second
#define ll long long
#define pr pair
#define MOD 1000000007
#define PI 3.14159265

using namespace std;

int main(){
	int t;
	cin >> t;
	double A, theta, c, s;
	for(int x = 1;x <= t;++x){
		cin >> A;
		theta = acos(A/1.414213);
		theta = theta - PI/4;
		c = cos(theta);
		s = sin(theta);
		cout << 0.5*c << " " << 0.5*s << " " << 0 << endl;
		cout << -0.5*s << " " << 0.5*c << " " << 0 << endl;
		cout << 0 << " " << 0 << " " << 0.5 << endl;
	}
	return 0;
}