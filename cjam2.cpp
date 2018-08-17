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

vector <pr <int, char> > par;

int main(){
	int t, n, sum, temp;
	pr <int, char> bgparty, sbgparty, tbgparty;
	cin >> t;
	for(int x = 1;x <= t;x++){
		cin >> n;
		sum = 0;
		for(int i = 0;i < n;++i){
			cin >> temp;
			par.push_back(make_pair(temp, 'A'+i));
			sum += temp;
		}
		cout << "Case #" << x << ":";
		make_heap(par.begin(), par.end());
		while(!par.empty()){
			bgparty = par.front();
			pop_heap(par.begin(), par.end());
			par.pop_back();
			sbgparty = par.front();
			pop_heap(par.begin(), par.end());
			par.pop_back();
			if((2*sbgparty.first) <= (sum-2)){
				cout << " " << bgparty.second << bgparty.second;
				sum -= 2;
				bgparty.first -= 2;
				if(bgparty.first > 0){
					par.push_back(bgparty);
					push_heap(par.begin(), par.end());
				}
				par.push_back(sbgparty);
				push_heap(par.begin(), par.end());
			}else if(!par.empty() && par.front().first*2 <= (sum-2)){
				cout << " " << bgparty.second << sbgparty.second;
				sum -= 2;
				bgparty.first--;
				sbgparty.first--;
				if(bgparty.first > 0){
					par.push_back(bgparty);
					push_heap(par.begin(), par.end());
				}
				if(sbgparty.first > 0){
					par.push_back(sbgparty);
					push_heap(par.begin(), par.end());
				}
			}else if(bgparty.first == sbgparty.first && 2*bgparty.first == sum){
				cout << " " << bgparty.second << sbgparty.second;
				sum -= 2;
				bgparty.first -= 1;
				sbgparty.first -= 1;
				if(bgparty.first > 0){
					par.push_back(bgparty);
					push_heap(par.begin(), par.end());
					par.push_back(sbgparty);
					push_heap(par.begin(), par.end());
				}
			}else{
				cout << " " << bgparty.second;
				sum--;
				bgparty.first -= 1;
				if(bgparty.first > 0){
					par.push_back(bgparty);
					push_heap(par.begin(), par.end());
				}
				par.push_back(sbgparty);
				push_heap(par.begin(), par.end());
			}
		}
		cout << endl;
	}
	return 0;
}