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

list<pr<double, double> > vpos;
list<double> vtime;
list<pr<double, double> >::iterator it1;

int main(){
	int i, t, N;
	double D, time2meet, p, K, S;
	pr <double, double> horse, horse2;
	cin >> t;
	for(int x = 1;x <= t;++x){
		cin >> D >> N;
		for(int i = 0;i < N;++i){
			cin >> K >> S;
			vpos.push_back(make_pair(K, S));
		}
		sort(vpos.begin(), vpos.end());
		i = 0;
		while(i != vpos.size()-1){
			if(vpos[i].ss <= vpos[i+1].ss){
				vpos.erase(vpos.begin()+i+1);
				continue;
			}
			i++;
		}
		for(i = 0;i < vpos.size()-1;++i){

		}
		cout << "Case #" << x << ": " <<  << endl;
	}
	return 0;
}