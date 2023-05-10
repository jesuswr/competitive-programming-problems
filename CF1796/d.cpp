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

ll N, K, X, A[MAXN];
struct STN{
	ll tot, lft, rgt, bst;
    void merge(STN& L, STN& R) {
		tot = L.tot + R.tot;
		lft = max(L.lft, L.tot + R.lft);
		rgt = max(R.rgt, R.tot + L.rgt);
		bst = max({L.bst, R.bst, L.rgt + R.lft});
	}
    void operator=(ll a) {
		tot = a;
		lft = rgt = bst = max(a, 0ll);
	}
};
STN ST[4*MAXN];
void STB(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        ST[id] = A[l];
        return;
    }
    int m = (l+r)>>1, L = id<<1, R = L|1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N){
    if(x == l && y == r) return ST[id];
    int m = (l+r)>>1, L = id<<1, R = L|1;
    if(x >= m) return STQ(x, y, R, m, r);
    if(y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, ll x, int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        ST[id] = x;
        return;
    }
    int m = (l+r)>>1, L = id<<1, R = L|1;
    if(p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}


void solve() {
	lrii(N, K); lri(X);
	FOR(i,0,N) {
		lri(A[i]);
		A[i] -= X;
	}
	STB();
	ll mx = 0;
	FOR(i,0,N-K+1) {
		FOR(j,i,i+K) STU(j, A[j] + 2*X);

		mx = max(mx, STQ(0, N).bst);

		FOR(j,i,i+K) STU(j, A[j]);
	}

	FOR(l,0,K+1) {
		int r = K - l;
		FOR(i,0,l) STU(i, A[i] + 2*X);
		FOR(i,N-r,N) STU(i, A[i] + 2*X);

		mx = max(mx, STQ(0, N).bst);

		FOR(i,0,l) STU(i, A[i]);
		FOR(i,N-r,N) STU(i, A[i]);
	}

	cout << mx << endl;
}



int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
