#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ff first
#define ss second
#define ll long long
#define pr pair
#define MOD 1000000007

using namespace std;

int main(){
	int t, a, b, n, mid;
	string str;
	cin >> t;
	for(int i = 1;i <= t;++i){
		cin >> a >> b;
		cin >> n;
		while(a < b){
			mid = (a+b)/2;
			mid = (a==mid)?mid+1:mid;
			cout << mid << endl;
			cin >> str;
			if(str == "CORRECT")
				break;
			else if(str == "TOO_BIG"){
				b = mid-1;
			}else if(str == "TOO_SMALL"){
				a = mid;
			}else if(str == "WRONG_ANSWER"){
				return 1;
			}
		}
	}
	return 0;
}