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
const int MAXN = 3e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K;
int A[MAXN], X[MAXN];
ll CNT[MAXN];

void solve() {
	rii(N,K);
	FOR(i,0,N) ri(A[i]);
	FOR(i,0,N) ri(X[i]);

	FOR(i,0,N) CNT[i+1] = 0;
	FOR(i,0,N) CNT[ abs(X[i]) ] += A[i];

	ll available = 0;
	FOR(i,1,N+1) {
		available += K;
		if (available < CNT[i]) {
			cout << "NO" << endl;
			return;
		}
		available -= CNT[i];
	}
	cout << "YES" << endl;
}

int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
