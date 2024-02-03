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
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int main(){
	int n; ri(n);
	vector< vi > a(n);
	FOR(i,0,n) {
		int k; ri(k);
		FOR(_,0,k) {
			int x; ri(x);
			a[i].pb(x);
		}
	}

	int mx = 1;
	map<int, int> dst;
	for(int i = n-1; i >= 0; --i) {
		int lgst = 1;
		for(int x : a[i]) lgst = max(lgst, 1 + dst[x]);
		for(int x : a[i]) dst[x] = lgst;
		mx = max(mx, lgst);
	}
	cout << mx << endl;

	return 0;
}
