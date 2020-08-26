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
const int MAXN = 1e6 + 10; // CAMBIAR ESTE

// GJNM
int n, m;
ll ans = 1;

ll BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
	p++;	// esto es porque el bit esta indexado desde 1
	for (; p < MAXN; p += p & -p) // se puede cambiar maxN por n+1 si hace falta mas velocidad
		BIT[p] += val;
}
ll sumBIT(int p) {
	p++;
	ll ret = 0;
	for (; p; p -= p & -p)
		ret += BIT[p];
	return ret;
}

priority_queue<piii> sweep;

int main() {
	rii(n, m);
	FOR(i, 0, n) {
		int y, l, r;
		riii(y, l, r);
		if ( l <= 0 && r >= 1000000 ) {
			ans++;
		}
		sweep.push({ -l, {1e8, y}}); // start
		sweep.push({ -r, { -1e8, y}});
	}
	FOR(i, 0, m) {
		int x, l, r;
		riii(x, l, r);
		if ( l <= 0 && r >= 1000000 )
			ans++;
		sweep.push({ -x, {l, r}});
	}
	while (!sweep.empty()) {
		if ( sweep.top().S.F == 1e8 ) {
			updBIT(sweep.top().S.S, 1);
		}
		else if ( sweep.top().S.F == -1e8 ) {
			updBIT(sweep.top().S.S, -1);
		}
		else {
			ans += (sumBIT(sweep.top().S.S) - sumBIT(sweep.top().S.F - 1));
		}
		sweep.pop();
	}
	printf("%lld\n", ans);


	return 0;
}