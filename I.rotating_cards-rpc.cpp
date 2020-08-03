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
const int maxN = 4e5 + 10; // CAMBIAR ESTE

// GJNM
int index_of[maxN];

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
	int t;
	ri(t);
	while (t--) {
		int n; ri(n);
		FOR(i, 0, maxN)
		BIT[i] = 0;
		FOR(i, 1, n+1) {
			int aux; ri(aux);
			index_of[aux] = i;
			updBIT(i, aux);
		}

		int last = 0;
		ll ans = 0;
		FOR(i, 1, n + 1) {
			int pos = index_of[i];
			if ( pos == last )
				ans += 0;
			else if ( pos > last ) {
				ans += min(sumBIT(pos - 1) - sumBIT(last), sumBIT(n) - sumBIT(pos - 1) + sumBIT(last));
			}
			else {
				ans += min(sumBIT(last - 1) - sumBIT(pos - 1), sumBIT(n) - sumBIT(last - 1) + sumBIT(pos - 1));
			}

			last = pos;
			updBIT(last, -i);
		}
		printf("%lld\n", ans);
	}

	return 0;
}