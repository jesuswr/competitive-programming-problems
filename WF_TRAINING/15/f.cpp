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

int Q;

struct STN{
	int pos;
};
STN ST[4*MAXN];
ii lzy[4*MAXN];
// Update node and lazy
void upd(int id, int l, int r, ii x){
	lzy[id].F = (1ll * lzy[id].F * x.F) % MOD;
	lzy[id].S = (1ll * lzy[id].S * x.F + x.S) % MOD;
	ST[id].pos = (1ll * ST[id].pos * x.F + x.S) % MOD;
}
// Propagate the update from lazy
void shift(int id, int l, int r){
    int m = (l+r)>>1, L = id<<1, R = L|1;
    upd(L, l, m, lzy[id]);
    upd(R, m, r, lzy[id]);
    lzy[id] = {1,0};
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = Q){
    if(x == l && y == r) return ST[id];
    shift(id, l, r);
    int m = (l+r)>>1, L = id<<1, R = L|1;
    if(x >= m) return STQ(x, y, R, m, r);
    if(y <= m) return STQ(x, y, L, l, m);
}
void STU(int x, int y, ii v, int id = 1, int l = 0, int r = Q){
    if(x >= r || y <= l) return;
    if(x <= l && y >= r) {
        upd(id, l, r, v);
        return;
    }
    shift(id, l, r);
    int m = (l+r)>>1, L = id<<1, R = L|1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
}

ll BIT[MAXN], LOGN = log2(MAXN)+1;
void updBIT(int p, ll val){ 
    p++;	
    for(; p < MAXN; p += p&-p) BIT[p] += val;
}

ll sumBIT(int p){
    p++;
    ll ret = 0;
    for(; p; p -= p&-p) 
    	ret += BIT[p];
    return ret;
}

ll binpow(ll b, ll e) {
	ll r = 1;
	while(e) {
		if (e & 1) r = (r * b) % MOD;
		b = (b * b) % MOD;
		e = e >> 1;
	}
	return r;
}


int main(){
	ri(Q);
	int G = 1;
	vi ops; ops.reserve(Q); ops.pb(1e9);
	vi prv; prv.reserve(Q); prv.pb({-1});
	vector<ll> pref; pref.reserve(Q); pref.pb(1e9);
	FOR(_,0,Q) {
		int t; ri(t);
		if (t == 1) {
			int k; ri(k);
			
			ops.pb(k);
			prv.pb( k == 0 ? G : prv.back() );
			pref.pb(pref.back() + k);

			// cout << "\t" << k << endl;
			ii upd = k == 0 ? make_pair(2,0) : make_pair(1,k);
			STU(0,G,upd);
			if (k == 0) {
				updBIT(0,1);
				updBIT(G+1,-1);
				STU(G, G+1, {1,1});
			}
			++G;
		}
		else if (t == 2) {
			int g,x; rii(g,x);
			int p1 = STQ(g, g+1).pos;
			int dff = binpow(2, sumBIT(g)) * (x-1) % MOD;
			printf("%d\n", (p1 + dff) % MOD);
		}
		else {
			int x; ri(x);
			int curr = G - 1;
			while(1) {
				if (ops[curr] == 0) {
					if (x & 1) {
						printf("%d\n", curr);
						break;
					}
					x >>= 1;
					curr--;
				}
				else {
					ll aux = pref[curr] - (prv[curr] == -1 ? 0 : pref[prv[curr]]);
					if (x >= aux) {
						x -= aux;
						curr = prv[curr];
						continue;
					}

					int lo = prv[curr] + 1, hi = curr;
					while(lo < hi) {
						int mi = lo + (hi - lo + 1) / 2;
						ll sm = pref[curr] - (mi == 0 ? 0 : pref[mi-1]);
						if (sm <= x)
							hi = mi - 1;
						else
							lo = mi;
					}

					ll sm = pref[curr] - (lo == 0 ? 0 : pref[lo-1]);
					if (x < sm) {
						printf("%d\n", lo);
						break;
					}
					x -= sm;
					curr = lo - 1;
				}
			}
		}
	}

	return 0;
}
