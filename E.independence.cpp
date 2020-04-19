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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 700; // CAMBIAR ESTE

// GJNM
int v,e;
int N;
vi g[maxN];
bool adj[maxN][maxN];

int color[maxN];
vector<pii> bvw;
bool ans;

void dfs(int v, int c, pii &cont){
	if ( c == 0 )
		cont.f++;
	else
		cont.s++;

	color[v] = c;
	for(int w : g[v]){
		if ( color[w] == -1 )
			dfs(w, 1-c, cont);
		else
			if ( color[v] == color[w] )
				ans = false;
	}
}


bool vis[maxN][2*maxN+1];
int dp[maxN][2*maxN+1];

int f(int i, int dif){
	if ( i == N )
		return abs(dif);
	if ( vis[i][dif+maxN] )
		return dp[i][dif+maxN];
	vis[i][dif+maxN] = true;
	int &ret = dp[i][dif+maxN];
	
	ret = min( f(i+1, dif+bvw[i].s-bvw[i].f), f(i+1, dif+bvw[i].f-bvw[i].s) );
	return ret;
}

int main(){
	rii(v,e);
	FOR(i,0,e){
		int v1, v2;
		rii(v1, v2);
		v1--;
		v2--;
		adj[v1][v2] = adj[v2][v1] = true;
	}

	FOR(i,0,v)
		FOR(j,0,v)
			if (!adj[i][j] && i!=j){
				g[i].pb(j);
				g[j].pb(i);
			}

	FOR(i,0,v)
		color[i] = -1;
	ans = true;

	FOR(i,0,v)
		if ( color[i] == -1 ){
			pii aux = {0,0};
			dfs(i, 0, aux);
			if ( !ans ){
				printf("-1\n");
				return 0;
			}
			bvw.pb(aux);
		}
	
	N = bvw.size();

	int ans = f(0,0);

	int v1 = ans;
	int v2 = 0;
	while( v1+v2 < v){
		v1++;
		v2++;
	}

	printf("%d\n",v1*(v1-1)/2 + v2*(v2-1)/2 );

	return 0;
	
}