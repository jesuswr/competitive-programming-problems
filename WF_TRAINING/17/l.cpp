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


int N, Q;
vi G[MAXN];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int T; // Timer
int IN[MAXN], OUT[MAXN], NXT[MAXN], SZ[MAXN], F[MAXN], H[MAXN];
void dfsSz(int v = 0, int p = -1) {
    SZ[v] = 1;
    if (p != -1) H[v] = H[p] + 1;
    for (auto &u : G[v]) if (u != p) {
            dfsSz(u, v);
            SZ[v] += SZ[u];
            if (SZ[u] > SZ[G[v][0]] || G[v][0] == p) swap(u, G[v][0]);
        }
}
void dfsHLD(int v = 0, int p = -1) {
    IN[v] = T++;
    F[v] = p;
    for (auto u : G[v]) if (u != p) {
            NXT[u] = (u == G[v][0] ? NXT[v] : u);
            dfsHLD(u, v);
        }
    OUT[v] = T;
}


int get_dst(int _a, int _b) {
	int a = _a, b = _b;
	while(NXT[a] != NXT[b]) {
		if (H[NXT[a]] < H[NXT[b]]) swap(a,b);
		a = F[NXT[a]];
	}
	if (H[a] > H[b]) swap(a,b);
	return H[_a] + H[_b] - 2 * H[a];
}

struct STN{
	ll mn = 0, mx = 0;
    void merge(STN& L, STN& R) {
		mn = min(L.mn, R.mn);
		mx = max(L.mx, R.mx);
	}
};
STN ST[4*MAXN];
ll lzy[4*MAXN];
void upd(int id, int l, int r, ll x){
    lzy[id] += x;
	ST[id].mn += x;
	ST[id].mx += x;
}
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
void STU(int x, int y, ll v, int id = 1, int l = 0, int r = N){
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


void update(int a, int b, ll x) {
	while(NXT[a] != NXT[b]) {
		if (H[NXT[a]] < H[NXT[b]]) swap(a,b);
		STU(IN[NXT[a]], IN[a]+1, x);
		a = F[NXT[a]];
	}
	if (H[a] > H[b]) swap(a,b);
	STU(IN[a], IN[b]+1, x);
}

bool bad(int a, int b) {
	ll mn = INFLL, mx = 0;
	while(NXT[a] != NXT[b]) {
		if (H[NXT[a]] < H[NXT[b]]) swap(a,b);
		auto q = STQ(IN[NXT[a]], IN[a]+1);
		mn = min(mn, q.mn);
		mx = max(mx, q.mx);

		a = F[NXT[a]];
	}
	if (H[a] > H[b]) swap(a,b);
	auto q = STQ(IN[a], IN[b]+1);
	mn = min(mn, q.mn);
	mx = max(mx, q.mx);
	return mn != mx;
}

int main(){
	rii(N,Q);
	FOR(_,1,N) {
		int a,b; rii(a,b); --a;--b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfsSz();
	dfsHLD();

	vector<tuple<int,int,int,ll>> Qs, aux;
	FOR(i,0,Q) {
		int a,b; rii(a,b);--a;--b;
		int dst = get_dst(a,b);
		ll x = rng();
		Qs.pb({dst, a, b, x});
		update(a, b, x);
	}
	sort(all(Qs)); 


	for(auto [_, a, b, x] : Qs) {
		if (bad(a,b)) {
			cout << "No" << endl;
			return 0;
		}
		update(a,b,-x);
	}
	cout << "Yes" << endl;


	return 0;
}
