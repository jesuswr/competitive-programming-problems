#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 998244353;
const int MAXN = 1010;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N,M;
int A[MAXN][MAXN];
int B[MAXN][MAXN];

void pre() {
	for(int i = N-1; i >= 0; --i) {
		for(int j = M-1; j >= 0; --j) {
			A[i][j] += A[i][j+1];
			B[i][j] += B[i+1][j];
			if (A[i][j] >= MOD) A[i][j] -= MOD;
			if (B[i][j] >= MOD) B[i][j] -= MOD;
		}
	}
}

int main(){
	rii(N,M);
	FOR(i,0,N) FOR(j,0,M) ri(A[i][j]);
	FOR(i,0,N) FOR(j,0,M) ri(B[i][j]);
	pre();

	int ans = 2;
	FOR(i,0,N-1) FOR(j,0,M-1) {
		int a = (1 - A[i][j] + MOD);
		int b = (1 - B[i][j] + MOD);
		if (a >= MOD) a -= MOD;
		if (b >= MOD) b -= MOD;

		int c = B[i][j+1];
		int d = A[i+1][j];

		int ab = 1ll * a * b % MOD;
		int cd = 1ll * c * d % MOD;
		
		int abcd = 1ll * ab * cd % MOD;

		ans += abcd;
		if (ans >= MOD) ans -= MOD;
	}
	cout << ans << endl;

	return 0;
}
