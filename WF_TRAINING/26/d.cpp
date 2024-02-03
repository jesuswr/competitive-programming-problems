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

vii clean(vii a, int aux = 1) {
	if (aux == -1) FOR(i,0,sz(a)) {
		a[i].F *= -1;
		a[i].S *= -1;
	}
	sort(all(a));
	int mn_y = 1e9 + 19;
	vii result;
	for(auto [x,y] : a) {
		if (y < mn_y) result.pb({x,y});
		mn_y = min(y, mn_y);
	}
	if (aux == -1) { 
		FOR(i,0,sz(result)) {
			result[i].F *= -1;
			result[i].S *= -1;
		}
		reverse(all(result));
	}
	// for(auto [x,y] : result) cout << y << " " << x << endl;
	// cout << endl;
	return result;
}

int G,B;
vii Gs, Bs;

ll get(int gi, int bi) {
	if (Bs[bi].F >= Gs[gi].F) return 0;
	if (Bs[bi].S >= Gs[gi].S) return 0;
	// cout << gi << " " << bi << " " << 1ll * (Gs[gi].F - Bs[bi].F) * (Gs[gi].F - Bs[bi].F) << endl;
	return 1ll * (Gs[gi].F - Bs[bi].F) * (Gs[gi].S - Bs[bi].S);
}

ll go(int gl, int gr, int bl, int br) {
	if (gl > gr || bl > br) return 0;
	int mi = (bl + br) / 2;
	int bst = -1;
	ll bst_val = -INFLL;
	for(int i = gl; i <= gr; i += 1) {
		if (Bs[mi].S >= Gs[i].S) {
			break;
		}
		if (bst_val <= get(i, mi)) {
			bst_val = get(i, mi);
			bst = i;
		}
	}
	return max({
		bst_val,
		go(gl, bst, bl, mi-1),
		go(bst, gr, mi+1, br)
	});

}

int main(){
	rii(B,G);
	FOR(i,0,B) {
		int y,x; rii(y,x);
		Bs.pb({x,y});
	}
	FOR(i,0,G) {
		int y,x; rii(y,x);
		Gs.pb({x,y});
	}
 	Bs = clean(Bs); 
	Gs = clean(Gs,-1);
	ll ans = go(0, sz(Gs)-1, 0, sz(Bs)-1);
	cout << max(ans,0ll) << endl;

	return 0;
}
