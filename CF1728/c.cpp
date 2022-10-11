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

int get_cnt(int x) {
	int c = 0;
	while (x) {
		++c;
		x /= 10;
	}
	return c;
}

void solve() {
	int n; ri(n);

	multiset<int> a, b;

	FOR(i, 0, n) {
		int x; ri(x);
		a.insert(x);
	}
	FOR(i, 0, n) {
		int x; ri(x);
		b.insert(x);
	}

	int moves = 0;
	while (!a.empty()) {
		int xa = *a.rbegin(), xb = *b.rbegin();

		if (xa < xb) {
			swap(xa, xb);
			swap(a, b);
		}

		if (xa == xb) {
			a.erase(a.find(xa));
			b.erase(b.find(xb));
		}
		else { // xa > xb
			a.erase(a.find(xa));
			a.insert(get_cnt(xa));
			moves++;
		}
	}
	printf("%d\n", moves);

}


int main() {
	int t; ri(t);
	while (t--) solve();

	return 0;
}