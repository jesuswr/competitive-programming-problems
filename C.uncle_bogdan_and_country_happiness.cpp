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
int P[maxN], H[maxN], GOOD[maxN], BAD[maxN], C[maxN];
vi G[maxN];
bool ans;


void clean(int sz){
	FOR(i,0,sz){
		P[i] = H[i] = GOOD[i] = BAD[i] = C[i] = 0;
		G[i].clear();
	}
}

int calc_C(int x, int father = -1) {
	int sons = 0;
	for (auto y : G[x]) {
		if ( y == father )
			continue;
		sons += calc_C(y, x);
	}
	C[x] = sons + P[x];
	GOOD[x] = C[x] + H[x];
	BAD[x] = C[x] - H[x];
	if ( (GOOD[x] & 1) || (BAD[x] & 1) || (BAD[x] < 0) || (GOOD[x] < 0) ){
		//printf("%d -> 1\n", x);
		ans = false;
	}
	GOOD[x] = GOOD[x] >> 1;
	BAD[x] = BAD[x] >> 1;

	int aux_bad = max(0, BAD[x] - P[x]);
	int bad_sons = 0;
	int good_sons = 0;
	for (auto y : G[x]) {
		if ( y == father )
			continue;
		bad_sons += BAD[y];
		good_sons += GOOD[y];
	}

	if ( good_sons + bad_sons != C[x] - P[x] ){
		//printf("%d -> 2\n", x);
		ans = false;
	}

	if ( bad_sons < aux_bad ){
		//printf("%d -> 3\n", x);
		ans = false;
	}

	return C[x];
}

int main() {
	int t;
	ri(t);
	while (t--) {
		int n, m;
		rii(n, m);
		FOR(i, 0, n)
		ri(P[i]);
		FOR(i, 0, n)
		ri(H[i]);
		FOR(i, 1, n) {
			int a, b;
			rii(a, b);
			a--, b--;
			G[a].pb(b), G[b].pb(a);
		}
		ans = true;
		calc_C(0);
		if ( ans )
			printf("YES\n");
		else
			printf("NO\n");

		clean(n);
	}

	return 0;
}