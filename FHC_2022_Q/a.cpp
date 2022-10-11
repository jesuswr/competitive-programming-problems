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

string solve() {
	int n, k; rii(n, k);
	vi cnt(100);
	FOR(i, 0, n) {
		int aux; ri(aux);
		cnt[aux - 1]++;
	}
	if (n > 2 * k) {
		return "NO";
	}
	FOR(i, 0, 100) if (cnt[i] > 2) {
		return "NO";
	}
	return "YES";
}

int main() {
	int t; ri(t);
	FOR(i, 1, t + 1) cout << "Case #" << i << ": " << solve() << endl;

	return 0;
}