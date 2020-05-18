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
const int maxN = 5009; // CAMBIAR ESTE

// GJNM
int n,m;
int n1, n2, n3;
vi g[maxN];
int col[maxN]; 
vi comps[maxN]; // los que esten en la casilla i pertenecen a la comp i
vii nc; // {nro de 2, nro de otros} de cada comp
int cmp; // nro de comp
int two, other;
bool ans;

void dfs(int v, int comp, int color){
	if ( color == 2 ){
		col[v] = 2;
		two++;
	}
	else{
		col[v] = 1;
		other++;
	}
	comps[comp].pb(v);
	int next_col = ( color == 2 ? 1 : 2 ); 
	for(auto u : g[v]){
		if ( col[u] == 0 ){
			dfs(u, comp, next_col);
		}
		else{
			if ( col[u] == col[v] )
				ans = false;
		}
	}
}

bool dp[maxN][maxN], visdp[maxN][maxN];

bool f(int ind, int cnt){
	if ( ind == cmp && cnt == n2 )
		return dp[ind][cnt] = true;
	if ( ind >= cmp )
		return dp[ind][cnt] = false;

	if ( visdp[ind][cnt] )
		return dp[ind][cnt];

	visdp[ind][cnt] = true;

	return dp[ind][cnt] = f(ind+1,cnt+nc[ind].F) || f(ind+1,cnt+nc[ind].S);
}

void swp(int ind){
	for(auto x : comps[ind]){
		if ( col[x] == 2 )
			col[x] = 1;
		else
			col[x] = 2;
	}
}

void cons_sol(int ind, int cnt){
	if ( ind == cmp && cnt == n2 )
		return;

	if ( dp[ind+1][cnt+nc[ind].F] ){
		cons_sol(ind+1,cnt+nc[ind].F);
	}
	else{
		swp(ind);
		cons_sol(ind+1,cnt+nc[ind].S);
	}
}

int main(){
	rii(n,m);
	riii(n1,n2,n3);
	FOR(i,0,m){
		int a,b;
		rii(a,b);
		a--,b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	ans = true;
	FOR(i,0,n){
		if ( col[i] == 0 ){
			two = other = 0;
			dfs(i,cmp,2);
			nc.pb({two,other});
			cmp++;
		}
	}

	if ( !ans ){
		printf("NO\n");
		return 0;
	}

	ans = f(0,0);

	if ( !ans ){
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	cons_sol(0,0);
	FOR(i,0,n){
		if ( col[i] == 2 )
			printf("2");
		else{
			if ( n1-- > 0 )
				printf("1");
			else
				printf("3");
		}
	}
	printf("\n");
	return 0;
}