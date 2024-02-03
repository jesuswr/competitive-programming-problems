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
const ll MOD[2] = {1500004459, 1070777777};
const ll P = 1000000007;
const int MAXN = 6e6+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll POW[2][MAXN];
void pre() {
	POW[0][0] = POW[1][0] = 1;
	FOR(i,1,MAXN) {
		POW[0][i] = (POW[0][i-1] * P) % MOD[0];
		POW[1][i] = (POW[1][i-1] * P) % MOD[1];
	}
}

int N, A[MAXN], B[MAXN];
struct STN{
	int mx, mn;
	int sz = 1;
	ll H[2];
	ll RH[2];
    void merge(STN& L, STN& R) {
		mx = max(L.mx, R.mx);
		mn = min(L.mn, R.mn);
		FOR(p,0,2) {
			H[p] = (L.H[p] + R.H[p] * POW[p][L.sz]) % MOD[p];
			RH[p] = (R.RH[p] + L.RH[p] * POW[p][R.sz]) % MOD[p];
		}
	}
    void operator=(int i) {
		mx = A[i] - B[i];
		mn = A[i] - B[i];
		sz = 1;
		H[0] = H[1] = A[i];
		RH[0] = RH[1] = B[i];
	}
};
STN ST[4*MAXN];
void STB(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        ST[id] = l;
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
void STU(int p, int x, int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        ST[id] = x;
        return;
    }
    int m = (l+r)>>1, L = id<<1, R = L|1;
    if(p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int solve() {
	ri(N);
	FOR(i,0,N) ri(A[i]);
	FOR(i,0,N) ri(B[i]);

	FOR(i,0,N) {
		B[i+N] = A[i];
		A[i+N] = B[i];
		A[i+N+N] = A[i];
		B[i+N+N] = B[i];
	}
	int n = N;
	N = 3 * N;

	STB();

	FOR(i,0,2*n) {
		int sz = n / 2;
		auto l = STQ(i, i+sz);
		auto r = STQ(i+n-sz, i+n);
		auto tot = STQ(i,i+n);
		if (n & 1) if (A[i+sz] != B[i+sz]) continue;
		
		if (l.mx < 0 && r.mn > 0 && tot.H[0] == tot.RH[0] && tot.H[1] == tot.RH[1]) return i;
	}
	return -1;

}


int main(){
	int t; ri(t);
	FOR(i,0,t) {
		printf("Case #%d: %d\n", i+1, solve());
	}
	return 0;
}
