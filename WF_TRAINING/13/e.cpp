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

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M;

int q(const vi &a) {
	printf("? %d", sz(a));
	for(int x : a) printf(" %d", x);
	cout << endl;
	int r; ri(r);
	return r;
}


int main(){
	ri(N);

	vi all;
	FOR(i,1,N+1) all.pb(i);
	M = q(all);

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	FOR(_,0,29) {
		vi a, b;
		FOR(i,1,N+1) {
			if (rng() & 1) a.pb(i);
			else b.pb(i);
		}

		int ma = q(a), mb = q(b);
		int x = M - ma - mb;
		if (x & 1) {
			cout << "! NO" << endl;
		}
	}
	cout << "! YES" << endl;
	return 0;
}
