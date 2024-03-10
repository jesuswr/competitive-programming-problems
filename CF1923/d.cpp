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


int N;
int A[MAXN];
ll PSUM[MAXN];
int EQ[MAXN];

vi go() {
	PSUM[0] = A[0];
	FOR(i,1,N) PSUM[i] = A[i] + PSUM[i-1];
	FOR(i,1,N) EQ[i] = EQ[i-1] + (A[i] == A[i-1]);

	vi ans(N,-1);
	FOR(i,0,N-1) {
		if (A[i+1] > A[i]) {
			ans[i] = 1;
			continue;
		}

		int lo = 2, hi = N - i - 1;
		while(lo < hi) {
			int mi = lo + (hi - lo) / 2;

			ll sm = PSUM[i + mi] - PSUM[i];
			int all_eq = EQ[i + mi] - EQ[i+1];
			
			if (sm > A[i] && all_eq != mi - 1) hi = mi;
			else lo = mi + 1;
		}

		ll sm = PSUM[i + hi] - PSUM[i];
		int all_eq = EQ[i + hi] - EQ[i+1];
		
		if (sm > A[i] && all_eq != hi - 1) {
			ans[i] = hi;
		}
	}
	return ans;
}


void solve() {
	ri(N);
	FOR(i,0,N) ri(A[i]);
	vi ans = go();
	reverse(A,A+N);
	vi ans2 = go();
	reverse(all(ans2));

	FOR(i,0,N) {
		if (ans[i] != -1 && ans2[i] != -1) cout << min(ans[i], ans2[i]) << ' ';
		else cout << max(ans[i], ans2[i]) << ' ';
	}
	cout << endl;
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
