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
const int MAXN = 3e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int A[MAXN];
int CNT;

tuple<int, int, int, int> go(int l, int r) {
	if (l == r - 1) return {A[l], A[l], A[l], A[l]};

	int m = (l + r) / 2;
	auto [ll, lr, lmx, lmn] = go(l, m);
	auto [rl, rr, rmx, rmn] = go(m, r);
	if (lr > rl) {
		if (rmx > lmn){
			// printf("F1\n");
			CNT = INF;
		}
		++CNT;
		// printf("%d %d : %d %d %d %d\n", l, r, rl, lr, max(lmx, rmx), min(lmn, rmn));
		return {rl, lr, max(lmx, rmx), min(lmn, rmn)};
	}
	else {
		if (lmx > rmn){
			// printf("F\n");
			CNT = INF;
		}
		// printf("%d %d : %d %d %d %d\n", l, r, ll, rr, max(lmx, rmx), min(lmn, rmn));
		return {ll, rr, max(lmx, rmx), min(lmn, rmn)};
	}
}

void solve() {
	ri(N);
	FOR(i, 0, N) ri(A[i]);
	CNT = 0;
	go(0, N);
	if (CNT >= INF) {
		printf("-1\n");
		return;
	}
	printf("%d\n", CNT);
}



int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}