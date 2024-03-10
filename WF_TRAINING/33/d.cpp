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
const int MAXN = 3e5+15;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct sheet {
	int d, tf, ts;
	bool operator<(sheet other) {
		return ts < other.ts;
	} 
};

int N,Q;
vector<sheet> A;


int main(){
	rii(N,Q);
	FOR(_,0,N) {
		int d, tf, ts; rii(d,tf), ri(ts);
		A.pb({d,tf,ts});
	}
	sort(all(A));

	vector<int> prf(N), suf(N);
	FOR(i,0,N) prf[i] = max(A[i].ts , (i > 0 ? prf[i-1] : 0));
	for(int i = N-1; i >= 0; --i) suf[i] = max(A[i].tf , (i + 1 < N ? suf[i+1] : 0));

	bitset<MAXN> dp;
	dp[0] = 1;
	int pref_len = 0, suf_len = 0;
	FOR(i,0,N) suf_len += A[i].d;

	vector< pair< int, int > >  ans;
	FOR(i,0,N+1) {
		int p = (i > 0 ? prf[i-1] : 0);
		int s = (i < N ? suf[i] : 0);

		int len = suf_len;
		if (pref_len) {
			int aux = (pref_len - 1) / 2;
			int ind = dp._Find_next(aux);
			len += ind;
		}

		ans.pb({len, max(p,s)});

		if (i < N) {
			suf_len -= A[i].d;
			pref_len += A[i].d;
			dp = dp | (dp << A[i].d);
		}
	}
	reverse(all(ans));

	while(Q--) {
		int l; ri(l);
		auto it = upper_bound(all(ans), make_pair(l,INF));
		if (it == ans.begin()) cout << - 1 << endl;
		else {
			--it;
			int ans = it->S;
			cout << ans << endl;
		}
	}

	return 0;
}
