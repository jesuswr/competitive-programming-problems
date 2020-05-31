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
const int maxN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
vi G[maxN];
ll C[maxN], H[maxN], GO[maxN];
ll ans = 0;

void adjust_min(int v, int father = -1){
	for(auto u : G[v]){
		if ( u == father )
			continue;
		C[u] = min(C[u], C[v]);
		adjust_min(u,v);
	}
}

pii solve(int v, int father = -1){
	int one_zero = 0, zero_one = 0;
	if ( H[v] == 1 && GO[v] == 0 )
		one_zero++;
	if ( H[v] == 0 && GO[v] == 1 )
		zero_one++;

	for(auto u : G[v]){
		if ( u == father )
			continue;
		pii aux = solve(u,v);
		one_zero += aux.F;
		zero_one += aux.S;
	}
	ll mn = min(one_zero, zero_one);
	ans += C[v]*(2*mn);

	zero_one -= mn;
	one_zero -= mn;

	return {one_zero, zero_one};
}

int main(){
	int n;
	ri(n);
	FOR(i,0,n)
		rll(C[i],H[i]), rl(GO[i]);
	
	FOR(i,0,n-1){
		int a,b;
		rii(a,b);
		a--, b--;
		G[a].pb(b);
		G[b].pb(a);
	}

	adjust_min(0);
	pii ans2 = solve(0);
	if ( ans2.F != 0 || ans2.S != 0 )
		printf("-1\n");
	else
		printf("%lld\n", ans);
	return 0;
}