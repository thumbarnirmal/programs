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

int arr1[100003], arr2[100003];

int main(){
	int t, n, i, last1, last2, index;
	cin >> t;
	for(int x = 1;x <= t;++x){
		cin >> n;
		index = -1;
		for(i = 0;i < n-1;i += 2){
			scanf("%d", &arr1[i>>1]);
			scanf("%d", &arr2[i>>1]);
		}
		if(n&1)
			scanf("%d", &arr1[i>>1]);
		last1 = (n&1)?n>>1:(n>>1)-1;
		last2 = (n>>1)-1;
		sort(arr1, arr1+last1+1);
		sort(arr2, arr2+last2+1);
		if(n&1){
			for(i = 0;i <= last2;++i){
				if(arr2[i]>arr1[i+1])
					index = 2*i+1;
				if(arr1[i]>arr2[i])
					index = 2*i;
				if(index != -1)
					break;
			}
		}else{
			for(i = 0;i < last1;++i){
				if(arr2[i]>arr1[i+1])
					index = 2*i+1;
				if(arr1[i]>arr2[i])
					index = 2*i;
				if(index != -1)
					break;
			}
			if(index == -1 && arr1[last1]>arr2[last1])
				index = 2*last1;
		}
		cout << "Case #" << x << ": ";
		if(index == -1)
			cout << "OK" << endl;
		else
			cout << index << endl;
	}
	return 0;
}