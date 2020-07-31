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
const int maxN = 2e5; // CAMBIAR ESTE
const int MOD = 1000000007;

// GJNM
int v;
vi G[maxN];
int C[maxN];
ll DP[maxN][2];

void dfs(int x, int f = -1) {
	ll &w = DP[x][0] = C[x] == 0;
	ll &b = DP[x][1] = C[x] == 1;

	for (auto y : G[x]) {
		if ( y == f )
			continue;
		dfs(y, x);
		b = b*DP[y][0] + b*DP[y][1] + w*DP[y][1];
		b = b % MOD;
		w = w*DP[y][1] + w*DP[y][0];
		w = w % MOD;
	}
}

int main() {
	ri(v);
	FOR(i, 1, v) {
		int aux;
		ri(aux);
		G[i].pb(aux), G[aux].pb(i);
	}
	FOR(i, 0, v) {
		ri(C[i]);
	}

	dfs(0);

	printf("%lld\n", DP[0][1]);

	return 0;
}