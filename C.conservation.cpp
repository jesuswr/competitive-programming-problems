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
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
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
const int maxN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int LAB[maxN];
vi G[maxN];
int DEG[maxN];
int DEG2[maxN];
int V, E;
queue<int> TOPO[5];

int solve2(int start) {
	while ( !TOPO[1].empty() )
		TOPO[1].pop();
	while ( !TOPO[2].empty() )
		TOPO[2].pop();

	FOR(i, 0, V) {
		if ( DEG[i] == 0 ) {
			TOPO[LAB[i]].push(i);
		}
	}
	int ans = 0;
	while ( !TOPO[1].empty() || !TOPO[2].empty() ) {
		//printf("hola\n");
		if ( TOPO[start].empty() ) {
			start = ( start == 1 ? 2 : 1 );
			ans++;
		}
		while (!TOPO[start].empty()) {
			int x; x = TOPO[start].front(); TOPO[start].pop();

			for (auto y : G[x]) {
				DEG[y]--;
				if ( DEG[y] == 0 ){
					TOPO[LAB[y]].push(y);
				}
			}
		}
	}
	return ans;
}

void solve() {
	rii(V, E);
	FOR(i, 0, V) {
		G[i].clear();
		DEG[i] = 0; DEG2[i] = 0;
		ri(LAB[i]);
	}

	FOR(i, 0, E) {
		int a, b;
		rii(a, b);
		a--, b--;
		G[a].pb(b);
		DEG[b]++; DEG2[b]++;
	}
	int ans = solve2(1);
	FOR(i,0,V)
		DEG[i] = DEG2[i];
	ans = min(ans, solve2(2));
	printf("%d\n", ans);

}



int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}
	return 0;
}