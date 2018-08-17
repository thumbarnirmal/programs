#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ff first
#define ss second
#define ll long long
#define pr pair
#define MOD 1000000007

using namespace std;

map<string, ll> mymap;
vector<ll> v, g;

int main(){
	ll n, k, m, cost, x, temp, mini;
	cin >> n >> k >> m;
	string str;
	for(ll i = 0;i < n;++i){
		cin >> str;
		mymap[str] = i;
	}
	for(ll i = 0;i < n;++i){
		cin >> cost;
		v.push_back(cost);
	}
	for(ll i = 0;i < k;++i){
		cin >> x;
		cin >> temp;
		mini = v[temp-1];
		g.push_back(temp);
		for(ll j = 1;j < x;++j){
			cin >> temp;
			g.push_back(temp);
			mini = min(mini, v[temp-1]);
		}
		for(ll j = 0;j < x;++j){
			v[g[j]-1] = mini;
		}
		g.clear();
	}
	cost = 0;
	for(ll i = 0;i < m;++i){
		cin >> str;
		cost += v[mymap[str]];
	}
	cout << cost << endl;
	return 0;
}