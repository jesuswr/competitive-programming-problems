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
const int maxN = 1000; // CAMBIAR ESTE

// GJNM
vector<ll> w[maxN];

int main() { // j
	int n;
	ri(n);
	FOR(i, 0, (n * (n - 1)) >> 1 ) {
		int f, t;
		rii(f, t);
		f--, t--;
		ll aux;
		rl(aux);
		w[f].pb(aux);
		w[t].pb(aux);
	}
	ll ans = 0;
	FOR(i, 0, n) {
		sort(w[i].begin(), w[i].end());
		int pos = 1;
		while ( pos < w[i].size() ) {
			ans += w[i][pos];
			pos += 2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}