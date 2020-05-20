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
const int MAXINT = 4e5 + 100; // CAMBIAR ESTE

// GJNM
int n, l;
vector<int> G[MAXINT];

int timer;
int tin[MAXINT], tout[MAXINT], anc[MAXINT][ int(log2(MAXINT))+1 ];

void dfs(int v, int p){
    tin[v] = ++timer;
    anc[v][0] = p;

    for(int i = 1; i <= l; ++i) anc[v][i] = anc[anc[v][i-1]][i-1];
    for(int w : G[v]) if(w!=p) dfs(w, v);

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){ return tin[u]<=tin[v] && tout[u]>=tout[v]; }

int lca(int u, int v){
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = l; i >= 0; --i){
        if (!is_ancestor(anc[u][i], v)){
            u = anc[u][i];
        }
    }
    return anc[u][0];
}


int dist[MAXINT];
void dfs2(int x, int p = -1){
	for(auto y : G[x] ){
		if ( y == p )
			continue;

		dist[y] = dist[x] + 1;
		dfs2(y,x);
	}
}

int main(){
    int root = 1, v, w;

    ri(n); // Ejemplo mas abajo
    FOR(i,0,n-1) rii(v,w), G[v].pb(w), G[w].pb(v);

    double aux = log2(n);
    l = log2(n);
    if ( aux > l )
    	l++;

    dfs(root, root);

    //int q = 10;
    //while(q--){
    //    rii(v,w);
    //    cout << "Nodos " << v << " y " << w << endl;
    //    cout << "=> " << lca(v,w) << endl;
    //}
    dist[root] = 0;
    dfs2(root);

    int q;
    ri(q);
    FOR(_,0,q){
    	int x,y,a,b,k;
    	rii(x,y); // extra edge
    	riii(a,b,k); // de a a b con k

    	int l = dist[a] + dist[b] - 2*(dist[lca(a,b)]);
    	if ( l <= k && (l&1) == (k&1) ){
    		printf("YES\n");
    		continue;
    	}

    	l = dist[a] + dist[x] - 2*(dist[lca(a,x)]) + 1 + dist[b] + dist[y] - 2*(dist[lca(y,b)]);
    	if ( l <= k && (l&1) == (k&1) ){
    		printf("YES\n");
    		continue;
    	}

    	l = dist[a] + dist[x] - 2*(dist[lca(a,y)]) + 1 + dist[b] + dist[y] - 2*(dist[lca(x,b)]);
    	if ( l <= k && (l&1) == (k&1) ){
    		printf("YES\n");
    		continue;
    	}

    	printf("NO\n");
    }
    
}