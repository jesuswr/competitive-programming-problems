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
const int maxN = 3e5 + 10; // CAMBIAR ESTE

// GJNM
int n, p;
pii V[maxN];
int cnt[maxN];
vi R[maxN];

ll BIT[maxN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
	p++;	// esto es porque el bit esta indexado desde 1
	for (; p < maxN; p += p & -p) // se puede cambiar maxN por n+1 si hace falta mas velocidad
		BIT[p] += val;
}
ll sumBIT(int p) {
	p++;
	ll ret = 0;
	for (; p; p -= p & -p)
		ret += BIT[p];
	return ret;
}

int main() {
	rii(n, p);
	FOR(i, 1, n+1) {
		rii(V[i].F, V[i].S);
		cnt[V[i].F]++, cnt[V[i].S]++;
		R[V[i].F].pb(i), R[V[i].S].pb(i);
	}
	FOR(i, 1, n+1) {
		updBIT(cnt[i], 1);
	}

	ll ans = 0;

	FOR(i, 1, n+1) {
		map<int, ll> mp;
		for (auto x : R[i]) {
			mp[i ^ V[x].S ^ V[x].F]++;
		}
		for (auto p : mp) {
			updBIT(cnt[p.F], -1);
			updBIT(cnt[p.F] - p.S, 1);
		}
		updBIT(cnt[i], -1);
		ans += sumBIT(n);
		if ( p - cnt[i] >= 1 )
			ans -= sumBIT(p - cnt[i] - 1);

		for (auto p : mp) {
			updBIT(cnt[p.F], 1);
			updBIT(cnt[p.F] - p.S, -1);
		}
		updBIT(cnt[i], 1);
	}
	printf("%lld\n", ans>>1);


	return 0;
}