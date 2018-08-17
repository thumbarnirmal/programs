#include <iostream>
#include <cstdio>
//#include <cmath>
#include <algorithm>
//#include <vector>
//#include <queue>
#include <string>
#include <map>
//#include <unordered_map>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ff first
#define ss second
#define ll long long
#define pr pair
#define MOD 1000000007

using namespace std;

map<ll, ll> mp;

int main(){
	int t, len;
	ll D, atk, mcharge, swap;
	map<ll, ll>::iterator it;
	string seq;
	cin >> t;
	for(int x = 1;x <= t;++x){
		cin >> D;
		cin >> seq;
		len = seq.length();
		atk = 0;
		mcharge = 1;
		swap = 0;
		mp[1] = 0;
		for(int i = 0;i < len;++i){
			if(seq[i] == 'C'){
				mcharge *= 2;
				mp[mcharge] = 0;
			}else{
				mp[mcharge]++;
				atk += mcharge;
			}
		}
		it = --mp.end();
		mcharge = it->ff;
		while(atk > D && mcharge != 1){
			it = --mp.end();
			mcharge = it->ff;
			if(atk-((mcharge>>1)*it->ss) > D){
				mp[mcharge>>1] += it->ss;
				swap += it->ss;
				atk -= (mcharge>>1)*it->ss;
				mp.erase(it);
			}else{
				while(atk > D){
					mp[mcharge>>1] += 1;
					swap++;
					atk -= mcharge>>1;
					it->ss--;
				}
			}
		}
		cout << "Case #" << x << ": ";
		if(atk > D)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << swap << endl;
		mp.clear();
	}
	return 0;
}