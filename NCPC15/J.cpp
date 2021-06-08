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
#include <assert.h>
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;
#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18 + 1;
const int MOD = 998244353;
const int MAXN = 1e5 + 1;

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
			FOR(i, 1, (int)s.size() + 1) {
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

int AUX;
const int MX = 101;
int n, a[MAXN];
ld dp[MX];
bool used[MX];

ld solve(int t) {
	if ( used[t] ) return dp[t];
	used[t] = true;

	dp[t] = 0;
	ld prob = 1 / (ld)n;
	FOR(i, 0, n) if (a[i] + 1 <= t) {
		dp[t] += prob * (1 + solve(t - (a[i] + 1)));
	}
	dp[t] = max(dp[t], (ld)t * ((ld)AUX / n));
	cout << t << " : " << dp[t] << endl;
	return dp[t];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t >> n;

	map<ll, set<ll>> cnt;
	string q[n], ans[n];
	map<string, int> aux;
	vector<int> posInter[n];
	FOR(i, 0, n) {
		string s;
		q[i] = ans[i] = "";

		cin >> s;
		while ( s[SZ(s) - 1] != '?' ) {
			q[i] += s; q[i] += " "; posInter[i].pb( SZ(q[i]) - 2 );
			cin >> s;
		}
		q[i] += s; posInter[i].pb( SZ(q[i]) - 2 );
		cin >> ans[i];
		aux[ans[i]]++;
		AUX = max(AUX, aux[ans[i]]);

		Hash qh(q[i]), ansh(ans[i]);
		for (int p : posInter[i]) {
			ll pref = qh.get(0, p + 1), valAns = ansh.get(0, SZ(ans[i]));
			cnt[pref].insert(valAns);
		}
	}

	// Llenar arreglo a[]
	FOR(i, 0, n) {
		Hash qh(q[i]);
		for (int p : posInter[i]) {
			a[i]++;
			ll pref = qh.get(0, p + 1);
			//cout << "Hasta cierta palabra "<< SZ(cnt[pref]) << endl;
			if ( SZ(cnt[pref]) == 1 ) break;
		}
		cout << "Pregunta " << i << " | " << a[i] << endl;
	}

	cout << solve(t) << '\n';
	return 0;
}

/*
4 4
How much is 6 times 9? 42
How much is 9 times 6? 42
Is there intelligent life on Earth? Probably
What is the air speed velocity of an unladen swallow? African?

4 3
What do we send? Code
What do we want? Accepted
When do we want it? Now!

*/
