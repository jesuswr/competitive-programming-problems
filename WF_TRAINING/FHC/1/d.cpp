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
const int MAXN = 1e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, A[MAXN];
struct STN{
    ii mx, alt;
    void merge(STN& L, STN& R) {
        mx = max(L.mx, R.mx);
        alt = max(L.alt, R.alt);
    }
    void operator=(int i) {
        mx = {A[i], -i};
        alt = { (MOD-A[i])%MOD, -i};
    }
};

STN ST[4*MAXN];
ll lzy[4*MAXN];
void STB(int id = 1, int l = 0, int r = N){
    lzy[id] = 0;
    if(r - l < 2){
        ST[id] = l;
        return;
    }
    int m = (l+r)>>1, L = id<<1, R = L|1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

// Update node and lazy
void upd(int id, int l, int r, ll x){
    lzy[id] += x;
    if (x & 1) {
        swap(ST[id].mx, ST[id].alt);
    }
}

// Propagate the update from lazy
void shift(int id, int l, int r){
    int m = (l+r)>>1, L = id<<1, R = L|1;
    upd(L, l, m, lzy[id]);
    upd(R, m, r, lzy[id]);
    lzy[id] = 0;
}

STN STQ(int x, int y, int id = 1, int l = 0, int r = N){
    if(x == l && y == r) return ST[id];
    shift(id, l, r);
    int m = (l+r)>>1, L = id<<1, R = L|1;
    if(x >= m) return STQ(x, y, R, m, r);
    if(y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}

void STU(int x, int y, int v, int id = 1, int l = 0, int r = N){
    if(x >= r || y <= l) return;
    if(x <= l && y >= r) {
        upd(id, l, r, v);
        return;
    }
    shift(id, l, r);
    int m = (l+r)>>1, L = id<<1, R = L|1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

void solve() {
    ri(N);
    FOR(i,0,N) ri(A[i]);
    STB();
    int q; ri(q);
    ll ans = 0;
    while(q--) {
        int l,r; rii(l,r);
        --l, --r;
        STU(l,r+1,1);
        auto s = STQ(0,N);
        s.mx.S = 1 - s.mx.S;
        ans += s.mx.S ;
    }
    printf("%lld\n", ans);
}


int main(){
	int t; ri(t);
	FOR(i,1,t+1) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
