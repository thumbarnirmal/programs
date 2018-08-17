//
// Created by Nirmal on 11-06-2017.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define fr first
#define sc second
#define ll long long
#define pr pair
#define MOD 1000000007

using namespace std;

#ifndef MYFUNCS_H
#define MYFUNCS_H

#ifndef FFT					//incomplete------------------------------------------------------------
#define FFT

void fft(vector<complex<double> > &a, bool invert){
	int n = a.size();
	for(int i=1, j=0; i<n; ++i){
		int bit = n>>1;
		for(; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if(i<j)
			swap(a[i], a[j]);
	}

	for(int len=2; len<=n; len<<=1){
		double ang = 2*PI/len * (invert?-1:1);
		complex<double> wlen(cos(ang), sin(ang));
		for(int i=0; i<n; i+=len){
			complex<double> w(1);
			for(int j=0; j<len/2; ++j){
				complex<double> u = a[i+j], v = a[i+j+len/2]*w;
				a[i+j] = u+v;
				a[i+j+len/2] = u-v;
				w *= wlen;
			}
		}
	}

	if(invert)
		for(int i=0; i<n; ++i)
			a[i] /= n;
}

void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res){
	vector<complex<double> > fa(a.begin(), a.end()), fb(b.begin(), b.end());
	size_t n = 1;
	while(n < max(a.size(), b.size()))
		n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);

	fft(fa, false), fft(fb, false);
	for(size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft(fa, true);

	res.resize(n);
	for(size_t i=0; i<n; ++i)
		res[i] = fa[i].real() + 0.5;
}

#endif

#ifndef LOOP_FINDING
#define LOOP_FINDING

vector<int> graph[140001];
vector<bool> visited, loop, recStack;

void find_loop(int u){
	visited[u] = true;
	recStack[u] = true;
	for(auto& v : graph[u]){
		if(!visited[v]){
			find_loop(v);
		}else if(recStack[v]){
			loop[u] = true;
		}
		if(loop[v])
			loop[u] = true;
	}
	recStack[u] = false;
	return;
}

#endif

#ifndef PATH_FINDING
#define PATH_FINDING

bool adjnode_not_in_path(int node, vector<int> path){
	for(int i = 0;i < path.size();++i)
		if(path[i] == node)
			return false;
	return true;
}

void findpaths(int source, int target){
	vector<int> path;
	path.push_back(source);
	queue<vector<int> > q;
	q.push(path);
	while(!q.empty()){
		path = q.front();
		q.pop();
		int path_last_node = path[path.size()-1];
		if(path_last_node == target)
			upaths.push(path);
		for(int i = 0;i < graph[path_last_node].size();++i){
			if(adjnode_not_in_path(graph[path_last_node][i], path)){
				vector<int> new_path(path.begin(), path.end());
				new_path.push_back(graph[path_last_node][i]);
				q.push(new_path);
			}
		}
	}
	return;
}

#endif

#ifndef DISJOINT_SET
#define DISJOINT_SET

int parent[100001], rank[100001];

void create_set(int x){
	parent[x] = x;
	rank[x] = 0;
	return;
}

int find_set(int x){
	if(x != parent[x])
		parent[x] = find_set(parent[x]);
	return parent[x];
}

void merge_set(int x, int y){
	int px = find_set(x);
	int py = find_set(y);
	if(rank[px] > rank[py])
		parent[py] = px;
	else
		parent[px] = py;
	if(rank[px] == rank[py])
		rank[py]++;
	return;
}

#ifndef KRUSKAL_MST
#define KRUSKAL_MST

void kruskal_mst(){
	for(int i = 1;i <= n;++i){
		create_set(i);
	}
	sort(edge.begin(), edge.end());
	int e = 0, i = 0;
	while(e < n-1){
		int x = find_set(edge[i].sc.fr);
		int y = find_set(edge[i].sc.sc);
		if(x != y){
			merge_set(x, y);
			e++;
		}
		i++;
	}
	return;
}

#endif
#endif

#ifndef LEFT_GREATER
#define LEFT_GREATER

void left_greater(int arr[], int l_g[],int n){
	l_g[0] = l_g[1] = 0;
	stack<int> st;
	st.push(1);
	for(int i = 2;i <= n;++i)
	{
		while(!st.empty() && arr[st.top()] < arr[i])
			st.pop();
		if(st.empty())
			l_g[i] = 0;
		else
			l_g[i] = st.top();
		st.push(i);
	}
	return;
}

#endif

#ifndef SWAP
#define SWAP

void swp(int &t1, int &t2){
	int temp = t1;
	t1 = t2;
	t2 = temp;
	return;
}

#endif

#ifndef EXTENDED_EUCLIDEAN_INVERSE
#define EXTENDED_EUCLIDEAN_INVERSE

ll inverse(ll b, ll n){
	ll r1 = n, r2 = b, t1 = 0, t2 = 1, q, t, r;
	while(r2 > 0){
		q = r1/r2;
		r = r1%r2;
		r1 = r2;
		r2 = r;
		t = t1 - q*t2;
		t1 = t2;
		t2 = t;
	}
	if(t1 < 0)
		t1 += n;
	return t1;
}

#endif

#ifndef PERMUTATION_COMBINATION
#define PERMUTATION_COMBINATION

ll permutation(ll n, ll r){
	if(r == 0)
		return 1;
	return n*permutation(n-1, r-1);
}

ll combination(ll n, ll r){
	return permutation(n, r)/permutation(r, r);
}

#endif

#ifndef TOTIENT_FUNCTION
#define TOTIENT_FUNCTION

int phi(int n){
	int result = n;
	for(int i = 2;i*i <= n;++i){
		if(n%i == 0){
			while(n%i == 0)
				n /= i;
			result = result - result/i;
		}
	}
	if(n > 1)
		result = result - result/n;
	return result;
}

#endif

#ifndef TREES
#define TREES

typedef struct node{
	int val;
	node *l;
	node *r;
}node;

node * newnode(int val){
	node *temp = (node *)malloc(sizeof(node));
	temp->val = val;
	temp->l = temp->r = NULL;
	return temp;
}

node * bst_insert(node *temp, int elem){
	if(temp == NULL)
		return newnode(elem);
	if(elem <= temp->val)
		temp->l = bst_insert(temp->l, elem);
	else
		temp->r = bst_insert(temp->r, elem);
	return temp;
}

void inorder(node *temp){
	if(temp == NULL)
		return;
	inorder(temp->l);
	cout << temp->val << " ";
	inorder(temp->r);
	return;
}

node * dfs_find(node * ptr, int a){
	if(ptr->val == a)
		return ptr;
	node *temp = NULL;
	if(ptr->l != NULL)
		temp = dfs_find(ptr->l, a);
	if(temp != NULL)
		return temp;
	if(ptr->r != NULL)
		temp = dfs_find(ptr->r, a);
	if(temp != NULL)
		return temp;
	return temp;
}

#endif

#ifndef KNUTH_MORRIS_PRATT_STRING_MATCHING
#define KNUTH_MORRIS_PRATT_STRING_MATCHING

int F[7];

void build_failure_function(string s){
	F[0] = F[1] = 0;
	int j;
	for(int i = 2;i <= s.size();++i){
		j = F[i-1];
		for(;;){
			if(s[j] == s[i-1]){
				F[i] = j+1;
				break;
			}
			if(j == 0){
				F[i] = 0;
				break;
			}
			j = F[j];
		}
	}
}

void Knuth_Morris_Pratt(string text, string pattern){
	build_failure_function(pattern);
	int i = 0;
	int j = 0;
	for(;;){
		if(j == text.size())
			break;
		if(text[j] == pattern[i]){
			i++;
			j++;
			if(i == pattern.size())
				cout << "Match found";
		}else if(i > 0)
			i = F[i];
		else
			j++;
	}
}

#endif

#ifndef PRIME_FACTORS_WITH_POWER
#define PRIME_FACTORS_WITH_POWER

int sieve[1000001] = {0};

void create_sieve_spf(){
	sieve[0] = sieve[1] = -1;
	for(int i = 2;i <= 1000000;i += 2)
		sieve[i] = 2;
	for(int i = 3;i <= 1000000;i += 2){
		if(sieve[i] == 0){
			sieve[i] = i;
			for(int j = i;(ll)j*i <= 1000000;j += 2){
				if(sieve[i*j] == 0)
					sieve[i*j] = i;
			}
		}
	}
}

void prime_factors_with_power(int n){
	create_sieve_spf();
	int curr = sieve[n];
	int cnt = 1;
	while(n>1){
		n /= sieve[n];
		if(curr == sieve[n]){
			cnt++;
			continue;
		}
		cout << curr << "	" << cnt << endl;
		curr = sieve[n];
		cnt = 1;
	}
}

#endif

#ifndef PRIME_FACTORS
#define PRIME_FACTORS

void prime_factors(int n){
	while(!(n&1)){
		cout << 2 << " ";
		n /= 2;
	}
	for(int i = 3;i*i <= n;i += 2){
		while(n%i == 0){
			cout << i << " ";
			n /= i;
		}
	}
	if(n>2)
		cout << n;
	cout << endl;
	return;
}

#endif

#ifndef SIEVE
#define SIEVE

int sieve[1000001] = {0};

void create_sieve(){
	sieve[0] = sieve[1] = 1;
	for(int i = 2;i*i <= 1000000;++i){
		if(sieve[i] == 1)
			continue;
		for(int j = i+i;j <= 1000000;j += i)
			sieve[j] = 1;
	}
}

int lp[1000001] = {0};
int pr[1000001];

void modified_sieve(){
	lp[0] = lp[1] = -1;
	int ind = 0;
	for(int i=2;i<=1000000;++i){
		if(lp[i] == 0){
			lp[i] = i;
			pr[ind++] = i;
		}
		for(int j=0; j<ind && pr[j]<=lp[i] && i*pr[j]<=1000000; ++j)
			lp[i*pr[j]] = pr[j];
	}
}

#endif

#ifndef NUMPOW
#define NUMPOW

ll numpow(ll base, ll power){
	ll result = 1;
	while(power > 0){
		if(power&1)
			result = base*result;
		base = base*base;
		power /= 2;
	}
	return result;
}

#endif

#ifndef MATMULT
#define MATMULT

void matmult(ll a[][2], ll b[][2], ll c[][2]){
	ll temp[2][2];
	temp[0][0] = ((a[0][0]*b[0][0])%MOD + (a[0][1]*b[1][0])%MOD)%MOD;
	temp[0][1] = ((a[0][0]*b[0][1])%MOD + (a[0][1]*b[1][1])%MOD)%MOD;
	temp[1][0] = ((a[1][0]*b[0][0])%MOD + (a[1][1]*b[1][0])%MOD)%MOD;
	temp[1][1] = ((a[1][0]*b[0][1])%MOD + (a[1][1]*b[1][1])%MOD)%MOD;
	c[0][0] = temp[0][0];
	c[0][1] = temp[0][1];
	c[1][0] = temp[1][0];
	c[1][1] = temp[1][1];
	return;
}

#endif

#ifndef MATPOW
#define MATPOW

void matpow(ll C[][2], ll n, ll result[][2]){
	result[0][0] = 1;
	result[0][1] = 0;
	result[1][0] = 0;
	result[1][1] = 1;
	while(n > 0){
		if(n&1)
			matmult(result, C, result);
		matmult(C, C, C);
		n /= 2;
	}
	return;
}

#ifndef FIBONACCI
#define FIBONACCI

ll fibonacci(ll n, ll a, ll b){
	if(n > 2){
		ll C[2][2] = {{a,b},{1,0}}, result[2][2];
		matpow(C, n-1, result);
		return ((result[0][0]*a)%MOD + result[0][1])%MOD;
	}else
		return a*a + b;
}

#endif

#ifndef GCD
#define GCD

int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

#endif

#ifndef CHOOSEPIVOT
#define CHOOSEPIVOT

int choosepivot(int *a, int low, int high){
	return rand() % (high - low + 1) + low;
}

#endif

#ifndef PARTITION
#define PARTITION

int partition(int *a, int low, int high){
	int p = a[low], i = low + 1, temp;
	for(int j = low+1;j <= high;++j){
		if(a[j] < p){
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			++i;
		}
	}
	temp = a[low];
	a[low] = a[i-1];
	a[i-1] = temp;
	return i-1;
}

#endif

#ifndef QUICKSORT
#define QUICKSORT

void quicksort(int *a, int low, int high){
	if(low >= high)
		return;
	int p = choosepivot(a, low, high);
	int temp = a[p];
	a[p] = a[low];
	a[low] = temp;
	p = partition(a, low, high);
	quicksort(a, low, p-1);
	quicksort(a, p+1, high);
}

#endif

#ifndef BINARYSEARCH
#define BINARYSEARCH

int binarysearch(int *a, int low, int high, int key){
	int mid = (low+high)/2;
	if(a[mid] == key)
		return mid;
	else if(low > high)
		return -1;
	else if(a[mid] > key)
		return binarysearch(a, low, mid-1, key);
	else
		return binarysearch(a, mid+1, high, key);
}

#endif

#ifndef MERGE
#define MERGE

void merge(int *a, int low, int mid, int high){
	int i = low, j = mid+1, k = 0, temp[high-low+1];
	while(i <= mid && j <= high){
		if(a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while(i <= mid)
		temp[k++] = a[i++];
	while(j <= high)
		temp[k++] = a[j++];
	for(i = low;i <= high;++i)
		a[i] = temp[i-low];
	return;
}

#endif

#ifndef MERGESORT
#define MERGESORT

void mergesort(int *a, int low, int high){
	int mid;
	if (low < high){
		mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid+1, high);
		merge(a, low, mid, high);
	}
	return;
}

#endif

#endif //MYFUNCS_H