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

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 3e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int A[MAXN], B[MAXN];

ll go(int k) {
	vi a, b;
	FOR(i,0,N) {
		if (A[i] <= k) a.pb(i);
		if (B[i] >= N - k + 1) b.pb(i);
	}

	ll ans = 0;
	FOR(i,0,k) ans += abs(a[i] - b[i]);
	return ans;
}
int main() {
	ri(N);
	FOR(i,0,N) ri(A[i]);
	FOR(i,0,N) ri(B[i]);
	cout << min(go((N+1)/2), go(N/2)) << endl;
}
