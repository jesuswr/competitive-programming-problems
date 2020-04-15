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
const int maxN = 3e5; // CAMBIAR ESTE

// GJNM
int v, k;
vi g[maxN];
bool visited[maxN];
priority_queue<pair<ll,ll> > pq;

bool mark[maxN];
bool leaf[maxN];
ll ans;
ll height[maxN];
ll below[maxN];
ll father[maxN];
ll sons[maxN];
ll gain[maxN];

void dfs2(int x, ll carry){
	visited[x] = true;
	bool leaff = true;
	for(int y : g[x]){
		if ( visited[y] )
			continue;
		father[y] = x;
		dfs2(y,carry+1);
		leaff = false;
	}
	height[x] = carry;
	if ( leaff )
		leaf[x] = true;
	
}

int dfs(int x){
	visited[x] = true;
	int cnt = 0;
	int cnt2 = 0;
	for(int y : g[x] ){
		if ( visited[y] )
			continue;
		cnt++;
		cnt2++;
		cnt += dfs(y);
	}
	below[x] = cnt;
	sons[x] = cnt2;
	return cnt;
}

void dfs3(int x, ll carry){

	visited[x] = true;
	if ( mark[x] ){
		ans += carry;
		for(int y : g[x]){
			if ( visited[y] )
				continue;
			dfs3(y,carry);
		}
		return;
	}

	for(int y : g[x]){
		if ( visited[y] )
			continue;
		dfs3(y,carry+1);
	}
}


int main(){
	rii(v,k);
	FOR(i,0,v-1){
		int aux1, aux2;
		rii(aux1,aux2);
		g[aux1].pb(aux2);
		g[aux2].pb(aux1);
	}
	dfs2(1,0);
	FOR(i,1,v+1)
		visited[i] = false;
	dfs(1);

	FOR(i,1,v+1){
		gain[i] = (below[i]+1)*height[i];
	}

	FOR(i,1,v+1){
		if ( leaf[i] ){
			pq.push( { gain[i] , i }  );
		}
	}
	FOR(i,0,k){
		auto p = pq.top();
		mark[p.s] = true;
		//printf("%lld\n", p.s);
		pq.pop();
		sons[father[p.s]]--;
		if ( sons[father[p.s]] == 0 ){
			ll new_gain = gain[father[p.s]];
			for(int y : g[father[p.s]] ){
				if ( father[y] == father[p.s] )
					new_gain -= gain[y];
			}
			pq.push({new_gain,father[p.s]});
		}
	}
	
	FOR(i,1,v+1)
		visited[i] = false;

	dfs3(1,0);
	printf("%lld\n", ans);

	return 0;
	
}