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
int n;

struct Hash {
	int P = 1777771, MOD[2], PI[2];
	vector<int> h[2], pi[2];
	Hash(string& s) {
		MOD[0] = 999727999; MOD[1] = 1070777777;
		PI[0] = 325255434; PI[1] = 10018302;
		FOR(k, 0, 2)h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1);
		FOR(k, 0, 2) {
			h[k][0] = 0; pi[k][0] = 1;
			ll p = 1;
			FOR(i, 1, s.size() + 1) {
				h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
				pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
				p = (p * P) % MOD[k];
			}
		}
	}
	ll get(int s, int e) {
		ll h0 = (h[0][e] - h[0][s] + MOD[0]) % MOD[0];
		h0 = (1LL * h0 * pi[0][s]) % MOD[0];
		ll h1 = (h[1][e] - h[1][s] + MOD[1]) % MOD[1];
		h1 = (1LL * h1 * pi[1][s]) % MOD[1];
		return (h0 << 32) | h1;
	}
};

int main() {
	while (scanf("%d", &n) != EOF) {
		string small, big;
		cin >> small >> big;
 		Hash hs(small), hb(big);
		vi ans;
		FOR(i, 0, (int)big.size() - (int)small.size() + 1) {
			if (hs.get(0, n) == hb.get(i, i + n))
				ans.pb(i);
		}
		for(auto x : ans)
			printf("%d\n", x);
		printf("\n");
	}

	return 0;
}