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
	int r, c; rii(r, c);
	vector<string> a(r);
	FOR(i, 0, r) cin >> a[i];
	bool has_trees = false;
	FOR(i, 0, r) FOR(j, 0, c) has_trees |= a[i][j] == '^';

	bool ans = ! ((r == 1 || c == 1) && has_trees);
	if (ans) {
		printf("Possible\n");
		FOR(i, 0, r) FOR(j, 0, c) {
			if (has_trees) printf("^");
			else printf(".");
			if (j + 1 == c) printf("\n");
		}
	}
	else {
		printf("Impossible\n");
	}
}


int main() {
	int t; ri(t);
	FOR(i, 1, t + 1) cout << "Case #" << i << ": ", solve();

	return 0;
}