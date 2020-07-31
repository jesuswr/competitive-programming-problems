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
const int maxN = 1e6 + 10; // CAMBIAR ESTE
const ll MOD1 = 1e9 + 9;
const ll MOD2 = 1e9 + 7;
const ll MOD3 = 3221225473ll;
const ll MOD4 = 1645333507ll;

// GJNM
string ans, s;
ll PE[maxN], PE2[maxN], PE3[maxN], PE4[maxN];

int f() {
	int mn = min(ans.size(), s.size());
	int n = ans.size(), m = s.size();
	ll suf = 0, pref = 0;
	ll suf2 = 0, pref2 = 0;
	ll suf3 = 0, pref3 = 0;
	ll suf4 = 0, pref4 = 0;
	int ret = -1;
	FOR(i, 0, mn) {
		suf = (suf * 383ll + (ans[n - 1 - i]-'0')) % MOD1;
		pref = (pref + (s[i]-'0') * PE[i]) % MOD1;

		suf2 = (suf2 * 383ll + (ans[n - 1 - i]-'0')) % MOD2;
		pref2 = (pref2 + (s[i]-'0') * PE2[i]) % MOD2;

		suf3 = (suf3 * 383ll + (ans[n - 1 - i]-'0')) % MOD3;
		pref3 = (pref3 + (s[i]-'0') * PE3[i]) % MOD3;

		suf4 = (suf4 * 383ll + (ans[n - 1 - i]-'0')) % MOD4;
		pref4 = (pref4 + (s[i]-'0') * PE4[i]) % MOD4;

		if ( suf == pref && suf2 == pref2 && suf3 == pref3 && suf4 == pref4 )
			ret = i;
	}
	return ret;
}



int main() {
	std::ios_base::sync_with_stdio(0); cin.tie(0);

	PE[0] = PE2[0] = PE3[0] = PE4[0] = 1;
	FOR(i, 1, maxN) {
		PE[i] = (383ll * PE[i - 1]) % MOD1;
		PE2[i] = (383ll * PE2[i - 1]) % MOD2;
		PE3[i] = (383ll * PE3[i - 1]) % MOD3;
		PE4[i] = (383ll * PE4[i - 1]) % MOD4;

	}

	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> s;
		ll mx_sz = f();
		FOR(j,mx_sz+1,s.size())
			ans.pb(s[j]);
	}
	cout << ans << endl;



	return 0;
}