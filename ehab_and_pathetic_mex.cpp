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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
vi g[maxN+10];
pii edges[maxN+10];
int degree[maxN+10];
bool vis[maxN+19];
map<pii,int> weight;

int main(){
	int v;
	ri(v);
	int mx = -1;
	int ii = -1;
	FOR(i,0,v-1){
		rii(edges[i].f,edges[i].s);

		edges[i].f--;
		edges[i].s--;

		g[edges[i].f].pb(edges[i].s);
		g[edges[i].s].pb(edges[i].f);

		degree[edges[i].f]++;
		degree[edges[i].s]++;

		if ( degree[edges[i].f] > mx ){
			mx = degree[edges[i].f];
			ii = edges[i].f;
		}
		if ( degree[edges[i].s] > mx ){
			mx = degree[edges[i].s];
			ii = edges[i].s;
		}
	}

	queue<int> bfs;
	bfs.push(ii);
	int curr = 0;
	vis[ii] = true;

	while( !bfs.empty() ){
		int x = bfs.front();
		bfs.pop();

		for(int y : g[x]){
			if ( vis[y] )
				continue;

			weight[{x,y}] = weight[{y,x}] = curr++;
			bfs.push(y);
			vis[y] = true;
		}
	}
	FOR(i,0,v-1){
		printf("%d\n",weight[edges[i]] );
	}
	return 0;
}