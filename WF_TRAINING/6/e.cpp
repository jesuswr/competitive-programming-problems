#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
const int MAXB = 3;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
ll DP[MAXN][1 << MAXB];
pair<ll,int> A[MAXN];
ll f(int p, int msk) {
	if (DP[p][msk] != -1) return DP[p][msk];
	if (p == N) return DP[p][msk] = 0;
	if (msk & 1) return DP[p][msk] = f(p+1, msk >> 1);
	ll ans = INFLL;
	for(int b = 1; b <= MAXB; ++b) {
		if (msk & (1 << b)) continue;
		if (A[p].S == A[p+b].S) continue;
		int new_msk = msk | (1 << b);
		new_msk = new_msk >> 1;
		ans = min(ans, f(p + 1, new_msk) + abs(A[p].F - A[p+b].F));
	}
	return DP[p][msk] = ans;
}

int main(){
	ri(N);
	N = 2*N;
	FOR(i,0,N) {
		lri(A[i].F);
		A[i].S = i / 2;
	}
	sort(A, A+N);
	FOR(i,0,N) FOR(j,0,1<<MAXB) DP[i][j] = -1;
	cout << f(0,0) << endl;
	return 0;
}
