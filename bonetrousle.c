#include <stdio.h>
#include <math.h>

long long unsigned payup(long long unsigned n, long long unsigned k, int b);

int main(){
	long long unsigned k,n,i;
	int b, t;
	scanf("%d",&t);
	while(t--){
		scanf("%llu%llu%d",&n,&k,&b);
		printf(payup(n,k,b)==1 ? "Yes\n" : "No\n");
	}
	return 0;
}
long long unsigned payup(long long unsigned n, long long unsigned k, int b){
	for(;k!=0 && b!=0;k--){
		if(k==n && b==1)
			{
				printf("%llu ",k);
				return 1;
			}
		else if(k<n)
		{
			int a, b;
			a = payup(n-k,k-1,b-1);
			b = payup(n,k-1,b);
			if(a)
			{
				printf("%llu ", k);
				return a;
			}
			if(b)
			{
				return b;
			}
		}
	}
	return 0;
} 