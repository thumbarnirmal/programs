#include <iostream>
#include <cstdio>
//#include <cmath>
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

using namespace std;

int main(){
	int t = 100, n = 100000;
	cout << t << endl;
	for(int i = 1;i <= t;++i){
		cout << n << endl;
		for(int j = 1;j < n;++j){
			cout << rand()%1000000001 << " ";
		}
		cout << rand()%1000000001 << endl;
	}
	return 0;
}