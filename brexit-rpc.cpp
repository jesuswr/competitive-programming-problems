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
int n;
int tme[maxN];
vi g[maxN];
priority_queue< pair<int, int> > pq;
bool vis[maxN];
int t;
int ans;

void dfs(int x){
	if ( vis[x] )
		return;
	//printf("entre con %d\n", x);
	vis[x] = true;

	for(int y : g[x]){
		dfs(y);
	}
	//printf("saque a %d con %d\n",x , tme[x]+ t);
	ans = max(ans, tme[x] + t++);
	return;
}


int main(){
	ri(n);
	FOR(i,0,n){
		int aux;
		rii(tme[i], aux);
		FOR(j,0,aux){
			int v;
			ri(v);
			v--;
			g[i].pb(v);
		}
		pq.push({tme[i], i});
	}
	while( !pq.empty() ){
		pii aux = pq.top();
		pq.pop();
		
		dfs( aux.S );
	}
	printf("%d\n", ans);
	return 0;
}