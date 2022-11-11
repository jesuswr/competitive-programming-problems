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
int A[MAXN], B[MAXN];

int f() {
	int cnt = 0;
	FOR(i, 0, N) cnt += A[i] != B[i];
	return cnt;
}
int g() {
	int cnt[2] = {0, 0};
	FOR(i, 0, N) {
		cnt[ A[i] ] += 1;
		cnt[ B[i] ] -= 1;
	}
	return (abs(cnt[0]) + abs(cnt[1])) / 2 + 1;
}

void solve() {
	ri(N);
	FOR(i, 0, N) ri(A[i]);
	FOR(i, 0, N) ri(B[i]);

	printf("%d\n", min(f(), g()));
}

int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}