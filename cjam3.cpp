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

priority_queue<pr<double, double>, vector<pr<double, double> >, greater<pr<double, double> > > pq;

int main(){
	int t, N, K, S;
	double D, temp, p;
	pr <double, double> horse, horse2;
	cin >> t;
	for(int x = 1;x <= t;++x){
		cin >> D >> N;
		for(int i = 0;i < N;++i){
			cin >> K >> S;
			pq.push(make_pair(K, S));
		}
		horse = pq.top();
		pq.pop();
		while(!pq.empty()){
			if(pq.top().ss >= horse.ss){
				horse = pq.top();
				pq.pop();
				continue;
			}
			horse2 = pq.top();
			pq.pop();
			temp = (horse.ff-horse2.ff) / (horse2.ss-horse.ss);
			p = horse2.ff + temp*horse2.ss;
			if(p < D)
				horse2.ss = (D-horse2.ff) / (temp + (D-p)/horse.ss);
			horse = horse2;
		}
		cout << "Case #" << x << ": " << D*horse.ss/(D-horse.ff) << endl;
	}
	return 0;
}