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

int N, A[MAXN], B[MAXN], M;
map<int, int> H;
map<int, vi> W;
struct STN{
	int want;
    void merge(STN& L, STN& R) {
		want = max(L.want, R.want);
	}
    void operator=(int a) {
		want = a;
	}
};
STN ST[4*MAXN];
void STB(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        ST[id] = B[l];
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




void go(int l, int r, int mn = 1e9 + 10) {
	if (l > r) return;
	auto q = STQ(l, r+1);
	bool need = 0;
	for(auto it = lower_bound(all(W[q.want]), l); it != W[q.want].end(); ++it) {
		int i = *it;
		if (i > r) break;
		A[i] = min(A[i], mn);
		if (A[i] > B[i]) {
			need = 1;
			break;
		}
	}

	if (need && H[q.want] > 0) {
		H[q.want]--;
		mn = min(q.want, mn);
	}

	int prv = l;
	for(auto it = lower_bound(all(W[q.want]), l); it != W[q.want].end(); ++it) {
		int i = *it;
		if (i > r) break;
		A[i] = min(A[i], mn);
		go(prv, i-1, mn);
		prv = i+1;
	}
	go(prv, r, mn);

}

void solve() {
	ri(N);
	FOR(i,0,N) ri(A[i]);
	FOR(i,0,N) ri(B[i]);
	ri(M);
	FOR(i,0,M) {
		int a; ri(a);
		H[a] += 1;
	}
	FOR(i,0,N) W[B[i]].push_back(i);
	STB();
	go(0, N - 1);


	bool p = 1;
	for(int i = 0; i < N; ++i) {
		p &= A[i] == B[i];
	}
	if (p) cout << "YES" << endl;
	else cout << "NO" << endl;

	H.clear();
	W.clear();
}



int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
