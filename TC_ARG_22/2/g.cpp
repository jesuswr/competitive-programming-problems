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

int n,t;
int a[101];

int main(){
	rii(n,t);
	FOR(i,0,n) ri(a[i]);

	int cyc = min(t, 10000);

	vi lnds;
	FOR(_,0,cyc) {
		FOR(i,0,n) {
			auto it = upper_bound(all(lnds), a[i]);
			int ind = it - lnds.begin();
			if (ind == sz(lnds)) lnds.pb(69);
			lnds[ind] = a[i];
		}
	}

	map<int, int> cnt;
	int mx = 1;
	FOR(i,0,n) {
		cnt[a[i]]++;
		mx = max(mx, cnt[a[i]]);
	}


	cout << sz(lnds) + mx * (t - cyc) << endl;
	return 0;
}
