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
int B[MAXN];

int lcmm(int a, int b) {
	int gcd = __gcd(a, b);
	return (a * b) / gcd;
}

void solve() {
	ri(N);
	FOR(i, 0, N) ri(A[i]);
	B[0] = A[0];
	A[N] = 1;
	FOR(i, 0, N) {
		B[i + 1] = lcmm(A[i], A[i + 1]);
	}
	FOR(i, 0, N) if (__gcd(B[i], B[i + 1]) != A[i]) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
}


int main() {
	int t; ri(t);
	while (t--) solve();

	return 0;
}