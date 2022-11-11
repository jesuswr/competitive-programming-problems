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

int N, K;
vi G[MAXN];
int D[MAXN];


void pre() {
	queue<ii> q;
	q.push({0, 0});
	while (!q.empty()) {
		auto [u, hu] = q.front(); q.pop();
		D[u] = hu;
		for (int v : G[u]) {
			q.push({v, hu + 1});
		}
	}
}

int ORD[MAXN];
int P[MAXN];

bool cmp(int a, int b) {
	return D[a] > D[b];
}

bool valid(int h) {
	int k = K;
	vi carry(N);

	// printf("%d:\n", h);
	FOR(i, 0, N - 1) {
		int u = ORD[i];
		int hu = carry[u] + 1;
		// printf("%d %d\n", u+1, hu);
		if (hu == h && P[u] != 0) {
			--k;
		}
		else {
			carry[P[u]] = max(carry[P[u]], hu);
		}
	}



	return k >= 0;
}



void solve() {
	rii(N, K);
	FOR(i, 0, N) ORD[i] = i;
	FOR(i, 1, N) {
		int p; ri(p);
		P[i] = p - 1;
		G[p - 1].pb(i);
	}
	pre();
	sort(ORD, ORD + N, cmp);
	int lo = 1, hi = N;
	while (lo < hi) {
		int mi = lo + (hi - lo) / 2;
		// printf("%d %d\n", mi, valid(mi));
		if (valid(mi))
			hi = mi;
		else
			lo = mi + 1;
	}
	printf("%d\n", lo);

	FOR(i, 0, N) G[i].clear();
}


int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}