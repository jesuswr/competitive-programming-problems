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

int N;
int A[MAXN];

bool good(int k) {
	multiset<int> e;
	FOR(i, 0, N) e.insert(A[i]);

	FOR(i, 0, k) {
		if (e.empty()) return false;
		auto it = e.upper_bound(k - i);
		if (it == e.begin()) return false;
		--it;
		e.erase(it);
		if (e.empty()) continue;
		int x = *e.begin();
		e.erase(e.begin());
		e.insert(x + k - i);
	}
	return true;
}

void solve() {
	ri(N);
	FOR(i, 0, N) ri(A[i]);
	int k;
	for (k = N; k > 0; --k) {
		if (good(k)) break;
	}
	printf("%d\n", k);
}


int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}