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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
ll n, t;
vi aux[1100];

ll dp[11][1100];
bool vis[11][1100];

ll f(int curr, int curr_arr) {
	if (curr_arr == n - 1)
		return 0;
	if (vis[curr][curr_arr])
		return dp[curr][curr_arr];

	vis[curr][curr_arr] = true;
	ll &ret = dp[curr][curr_arr] = LLINF;

	FOR(i, 0, aux[curr_arr + 1].size()) {
		ll prev = aux[curr_arr][curr];
		ll act = aux[curr_arr + 1][i];

		ll extra_move = (prev - act + t) % t + 1;
		ll extra_move2 = (act - prev - 1 + t) % t;
		ret = min(ret, f(i, curr_arr + 1) + min(extra_move2, extra_move));
	}
	return ret;
}


int main() {
	rll(t, n);
	FOR(i, 0, n) {
		int n2; ri(n2);
		while(n2--){
			int aux2; ri(aux2);
			aux[i].pb(aux2);
		}
	}
	ll ans = LLINF;
	FOR(i, 0, aux[0].size()) {
		ll prev = 1;
		ll act = aux[0][i];

		ll extra_move = (prev - act + t) % t;
		ll extra_move2 = (act - prev + t) % t;
		//printf("%lld %lld : %lld\n", extra_move2, extra_move, act);
		ans = min(ans, f(i, 0) + min(extra_move2, extra_move));
	}
	printf("%lld\n", ans);

	return 0;
}