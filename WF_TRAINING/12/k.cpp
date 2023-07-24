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
void solve() {
	rii(N,M);
	vii goods, bads;
	vi ones;
	FOR(i,0,N) {
		int t, h; rii(t,h);
		h = min(h, M);
		if (t > h) bads.pb({t,h});
		else goods.pb({t,h});
	}

	int H = M;
	for(auto [t, h] : goods) {
		H -= (t - 1);
		while(H <= 0) {
			H--;
			H += ones.back();
			H = min(H, M);
			ones.pop_back();
		}
		ones.pb(h);
	}

	sort(all(bads), [](ii a, ii b) {
		return a.S > b.S;
	});

	for(auto [t, h] : bads) {
		while(69) {
			int can_take = min(t-1, H-1);
			t -= can_take;
			H -= can_take;
			if (t == 1) {
				ones.pb(h);
				break;
			}
			else if (!ones.empty()) {
				H--;
				H += ones.back();
				H = min(H, M);
				ones.pop_back();
			}
			else {
				cout << "NO" << endl;
				return;
			}

		}
	}

	cout << "YES" << endl;
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
