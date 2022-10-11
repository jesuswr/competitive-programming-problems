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
const int MAXN = 5010;
const int MAXX = 1 << 13;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int A[MAXN];

int DP[MAXN][MAXX];

int f(int u, int xr) {
	if (u == N) return 0;
	if (DP[u][xr] != -1) return DP[u][xr];
	int &ret = DP[u][xr];
	ret = INF;
	int ai = A[u] ^ xr;
	if (ai == 0) ret = f(u + 1, 0);
	else ret = min(f(u + 1, ai), f(u + 1, 0)) + 1;
	return ret;
}



void solve() {
	ri(N);
	FOR(i, 0, N) ri(A[i]);
	FOR(i, 0, N + 8) FOR(j, 0, MAXX) DP[i][j] = -1;
	printf("%d\n", f(0, 0));
}


int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}