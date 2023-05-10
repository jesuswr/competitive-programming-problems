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
const int MAXN = 5e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
ll X[MAXN];
ll R[MAXN];

vi get_ops() {
	vector<ll> z(N);
	FOR(i,1,N) z[i] = (X[i] - X[i-1]) - z[i-1];

	vi ret = {0, N-1};
	if (N <= 10) {
		FOR(i,1,N-1) ret.pb(i);
	}
	else {
		int mn[2] = {2, 1};
		FOR(i,1,N-1) {
			if (z[i] < z[mn[i&1]]) {
				mn[i&1] = i;
			}
		}
		ret.pb(mn[0]);
		ret.pb(mn[1]);
	}
	return ret;
}

void go(int m) {
	map<ll, int> cnt;
	ll mn = R[0];
	FOR(i,0,N) {
		mn = min(mn, R[i]);
		cnt[R[i]]++;
	}

	cnt[mn]--;
	vector<ll> ans(N);
	ans[m] = mn;
	for(int i = m + 1; i < N; ++i) {
		ll need = (X[i] - X[i-1]) - ans[i-1];
		if (cnt[need] == 0) return;
		cnt[need]--;
		ans[i] = need; 
	}
	for(int i = m - 1; i >= 0; --i) {
		ll need = (X[i+1] - X[i]) - ans[i+1];
		if (cnt[need] == 0) return;
		cnt[need]--;
		ans[i] = need; 
	}
	FOR(i,0,N) printf("%lld%c", ans[i], " \n"[i+1==N]);
	exit(0);
}


int main(){
	ri(N);
	FOR(i,0,N)lri(X[i]);
	FOR(i,0,N)lri(R[i]);

	vi ops = get_ops();

	for(int x : ops) go(x);
	return 0;
}
