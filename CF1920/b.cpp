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
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 1e9;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K, X;
int A[MAXN];

void solve() {
	ri(N); rii(K,X);
	FOR(i,0,N) ri(A[i]);
	sort(A, A+N);

	if (X >= N) {
		int ans = 0;
		FOR(i,0,N-K) ans -= A[i];
		cout << ans << endl;
		return;
	}
	else {
		reverse(A, A+N);
		int bst = -INF;
		int all = 0;
		FOR(i,0,N) all += A[i];
		int rem = 0;
		FOR(i,0,X) rem += A[i];
		bst = all - 2 * rem;

		FOR(i,0,K) {
			rem -= A[i];
			all -= A[i];
			if (i + X < N) rem += A[i+X];
			bst = max(bst, all - 2*rem);
		}
		cout << bst << endl;
		return;
	}
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
