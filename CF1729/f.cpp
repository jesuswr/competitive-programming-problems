#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct Hash {
	int P = 1777771, MOD[2], PI[2];
	vector<int> h[2], pi[2];
	Hash(string& s) {
		MOD[0] = 999727999; MOD[1] = 1070777777;
		PI[0] = 325255434; PI[1] = 10018302; // inversa de P en MOD0 y MOD1
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
	ll get(int s, int e) { // [s,e)
		ll h0 = (h[0][e] - h[0][s] + MOD[0]) % MOD[0];
		h0 = (1LL * h0 * pi[0][s]) % MOD[0];
		ll h1 = (h[1][e] - h[1][s] + MOD[1]) % MOD[1];
		h1 = (1LL * h1 * pi[1][s]) % MOD[1];
		return (h0 << 32) | h1;
	}
};

string S;
int N, W, M;

pair<int, int> ANS[9][9];
vi PREF;
vector< vector<pair<ll, int>> > A;

void solve() {
	FOR(i, 0, 9) FOR(j, 0, 9) ANS[i][j] = { -1, -1};
	A.clear();
	A.resize(9);

	cin >> S;
	rii(W, M);
	N = sz(S);
	Hash h(S);

	PREF.resize(N);
	FOR(i, 0, N) {
		PREF[i] = S[i] - '0';
		if (i > 0) PREF[i] += PREF[i - 1];
	}
	FOR(i, 0, N - W + 1) {
		int sm = (PREF[i + W - 1] - (i == 0 ? 0 : PREF[i - 1])) % 9;
		A[sm].pb({h.get(i, i + W), i});
	}

	FOR(i, 0, N - W + 1) {
		int sm = (PREF[i + W - 1] - (i == 0 ? 0 : PREF[i - 1])) % 9;
		ll hsh = h.get(i, i + W);
		// printf("%d %d\n", i, sm);
		FOR(v, 0, 9) {
			FOR(k, 0, 9) {
				if (ANS[v][k].first != -1) continue;
				int need = (sm * v) % 9;
				need = (k - need + 9) % 9;
				for (auto [hsh2, l] : A[need]) {
					if (l != i) {
						ANS[v][k] = {i + 1, l + 1};
						break;
					}
				}
			}
		}
	}


	while (M--) {
		int l, r, k;
		rii(l, r), ri(k);
		--l; --r;
		int sm = (PREF[r] - (l == 0 ? 0 : PREF[l - 1])) % 9;
		printf("%d %d\n", ANS[sm][k].F, ANS[sm][k].S);
	}

}

int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}