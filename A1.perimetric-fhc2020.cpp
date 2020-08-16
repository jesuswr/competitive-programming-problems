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
#define rlll(a,b,c) rl(a),rll(b,c)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e7 + 10; // CAMBIAR ESTE
const ll MOD = 1000000007;

// GJNM
ll n, k, w;
ll Al, Bl, Cl, Ah, Bh, Ch, Dl, Dh;
ll l[maxN], h[maxN];
ll ans[maxN];


void solve(int t) {
	rlll(n, k, w);
	FOR(i, 0, k) {
		rl(l[i]);
	}
	rll(Al, Bl), rll(Cl, Dl);
	FOR(i, 0, k) {
		rl(h[i]);
	}
	rll(Ah, Bh), rll(Ch, Dh);
	FOR(i, k, n) {
		l[i] = ((Al * l[i - 2] + Bl * l[i - 1] + Cl) % Dl) + 1;
		h[i] = ((Ah * h[i - 2] + Bh * h[i - 1] + Ch) % Dh) + 1;
	}
	l[n] = LLINF;
	FOR(i, 0, n) {
		ans[i] = 0;
	}

	int i_open = 0, i_close = 0;
	ll mx;
	ll last_close;
	while ( i_open < n ) {
		if ( l[i_open] <= l[i_close] + w) {
			if ( i_open == i_close ) {
				ans[i_open] = 2ll * w + 2ll * h[i_open];
				ans[i_open] = (ans[i_open] + MOD) % MOD;

				last_close = l[i_open];
				i_open++;
			}
			else {
				mx = 0;
				int aux_i_open = i_open - 1;
				while (aux_i_open >= i_close && aux_i_open + 30 >= i_open) {
					if ( l[aux_i_open] + w < l[i_open] )
						break;
					mx = max(mx, h[aux_i_open]);
					aux_i_open--;
				}

				ans[i_open] = 2ll * max(0ll, h[i_open] - mx) + 2ll * (l[i_open] - last_close);
				ans[i_open] = (ans[i_open] + MOD) % MOD;

				last_close = l[i_open];
				i_open++;
			}
		}
		else {
			i_close++;
		}
	}
	FOR(i, 1, n) {
		ans[i] = (ans[i] + ans[i - 1]) % MOD;
	}
	ll prnt = ans[0];
	FOR(i, 1, n) {
		prnt = (prnt * ans[i]) % MOD;
	}
	printf("Case #%d: %lld\n", t, prnt);
}


int main() {
	int t;
	ri(t);
	int aux_t = 1;
	while (t--) {
		solve(aux_t++);
	}

	return 0;
}