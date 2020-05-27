#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 5e5; // CAMBIAR ESTE

// GJNM
ll D[maxN]; // days
ll B[maxN];  ///  prefix sum days
ll A[maxN];  // prefix sum hugs

ll sum(ll x){
	return (x*(x+1))/2;
}

int main(){
	int n;
	ri(n);
	ll x;
	rl(x);
	FOR(i,0,n){
		rl(A[i]);
		A[i+n] = A[i];
		B[i] = B[i+n] = A[i];
		D[i] = D[i+n] = A[i];
	}
	FOR(i,0,2*n){
		A[i] = sum(A[i]);
		if ( i > 0 ){
			A[i] += A[i-1];
			B[i] += B[i-1];
		}
	}

	ll ans = 0;

	FOR(i,n,2*n){
		if ( D[i] >= x ){
			ans = max(ans, sum(D[i]) - sum(D[i]-x));
			continue;
		}
		
		int j = i;
		int l = 1, r = i-1;
		while( l <= r ){
			int m = (l+r)/2;
			if ( B[i] - B[m-1] <= x ){
				j = m;
				r = m-1;
			}
			else{
				l = m + 1;
			}
		}
		ll tot_days = x - (B[i] - B[j-1]);
		ll aux_ans = A[i] - A[j-1] + sum(D[j-1]) - sum(D[j-1]-tot_days);

		//printf("i = %d j = %d %lld tot_days = %lld aux_ans = %lld\n", i, j, D[j-1], tot_days,aux_ans);
		ans = max(ans, aux_ans);
	}
	printf("%lld\n", ans);


	

	return 0;
}