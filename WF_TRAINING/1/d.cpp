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
const ll INFLL = 1e12;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N,M;
ll P[MAXN];
ll X[MAXN];

ll go(vi inds, ll L, ll R) {
	// for (int x : inds) cout << x << " ";
	// cout << endl;
	ll bst = 0;
	int l = 0, r = -1;
	ll curr = 0;
	while(l < sz(inds)) {
		if (l > r) {
			r = l;
			curr = P[inds[l]];
		}
		while(r + 1 < sz(inds)) {
			++r;
			ll dl = 100 * inds[l] - L;
			ll dr = R - 100 * inds[r];
			ll dst = 100 * (inds[r] - inds[l]);
			if (dr + dl > dst) {
				curr += P[inds[r]];
			}
			else {
				--r;
				break;
			}
		}
		bst = max(bst, curr);
		curr -= P[inds[l]];
		++l;
	}

	// cout << bst << endl << endl;
	return bst;
}


int main(){
	rii(N,M);
	FOR(i,0,N) {
		lri(P[i]);
	}
	FOR(i,0,M) lri(X[i+1]);
	X[0] = -INFLL;
	X[M+1] = INFLL;
	M += 2;
	sort(X, X+M);

	ll ans = 0;
	int i = 0, j = 1;
	vi act;
	while(i < N) {
		if (100 * i < X[j]) {
			act.pb(i);
			++i;
		}
		else if (100 * i >= X[j]) {
			if (X[j] == 100 * i) ++i;
			ans = max(ans, go(act, X[j-1], X[j]));
			act.clear();
			++j;
		}
	}
	ans = max(ans, go(act, X[j-1], X[j]));
	act.clear();

	cout << ans << endl;
	
	return 0;
}
