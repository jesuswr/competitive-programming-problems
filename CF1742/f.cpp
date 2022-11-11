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

void solve() {
	int q; ri(q);
	vector<bool> s(26), t(26);
	ll cnts = 1, cntt = 1;
	while (q--) {
		int tt, k; string x;
		rii(tt, k); cin >> x;
		if (tt == 2) {
			cntt += 1ll * sz(x) * k;
			for (char c : x) {
				int ind = c - 'a';
				t[ind] = 1;
			}
		}
		else {
			cnts += 1ll * sz(x) * k;
			for (char c : x) {
				int ind = c - 'a';
				s[ind] = 1;
			}
		}

		bool g = 0;
		FOR(i, 1, 26) if (t[i]) g = 1;
		if (g) printf("YES\n");
		else {
			g = 1;
			FOR(i,1,26) if (s[i]) g = 0;
			if (cnts >= cntt) g = 0;
			if (g) printf("YES\n");
			else printf("NO\n");
		}
	}
}


int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}