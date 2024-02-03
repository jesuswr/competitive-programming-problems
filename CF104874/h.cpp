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
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, Q;
int A[MAXN];
int MX = -1;
int DP[10 * MAXN];

void pre() {
	FOR(i,0,N) MX = max(MX, A[i]);
	FOR(i,1,N) A[i] += A[i-1];
}

int qry(int l, int r) {
	return A[r] - (l > 0 ? A[l-1] : 0);
}

int get_next(int l, int mx) {
	int lo = l, hi = N-1; 
	while(lo < hi) {
		int mi = lo + (hi - lo + 1) / 2;
		if (qry(l, mi) <= mx)
			lo = mi;
		else
			hi = mi - 1;
	}
	return lo;
}

int main(){
	ri(N);
	FOR(i,0,N) ri(A[i]);
	pre();

	ri(Q);
	FOR(_,0,Q) {
		int t; ri(t);
		if (t < MX) printf("Impossible\n");
		else if (DP[t] != 0) printf("%d\n", DP[t]);
		else {
			int ans = 0;
			int i = 0;
			while(i < N) {
				int next_i = get_next(i, t);
				i = next_i + 1;
				ans++;
			}
			DP[t] = ans;
			printf("%d\n", ans);
		}
	}

	return 0;
}
