#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for (int i = n; i < (int)m; i++)
#define ROF(i,n,m) for (int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
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
const int MAXN = 2e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, A[MAXN];
struct STN {
	int val;
	void merge(STN& L, STN& R) { val = max(L.val, R.val); }
	void operator=(int a) { val = a; }
};
STN ST[4*MAXN];
void STB(int id = 1, int l = 0, int r = N) {
	if(r-l < 2){
		ST[id] = A[l];
		return;
	}
	int m = (l+r)>>1, L = id<<1, R = L|1;
	STB(L, l, m); STB(R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
	if (x == l && y == r) return ST[id];
	int m = (l+r)>>1, L = id<<1, R = L|1;
	if(x >= m) return STQ(x, y, R, m, r);
	if(y <= m) return STQ(x, y, L, l, m);
	STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
	return res.merge(ln, rn), res;
}

void STU(int p, int x, int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id].val += x;
		return;
	}
	int m = (l+r)>>1, L = id<<1, R = L|1;
	if(p < m) STU(p, x, L, l, m);
	else STU(p,  x, R, m, r);
	ST[id].merge(ST[L], ST[R]);

}

bool check() {
	return STQ(0, N).val == 1;
}

vector<pair<ii, ii>> segs;
int n; ll h, w;

ll getDist(ll x, ll y) {
	if (y == 0) return x;
	if (x == w) return y + w;
	if (y == h) return w-x + w + h;
	return 2*w+h + h-y;
}

pair<double, double> addDist(double x, double y, double c) {
	if (y == 0) return {x+c, y};
	if (x == w) return {x, y+c};
	if (y == h) return {x-c, y};
	return {x, y-c};
}

int main() {
	ri(n); lrii(w, h);
	FOR(i,0,n) {
		ll x, y, xx, yy;
		lrii(x, y); lrii(xx, yy);
		
		segs.pb({{getDist(x, y), 1ll*i}, {x, y}});
		segs.pb({{getDist(xx, yy), 1ll*i}, {xx, yy}});
	}

	sort(all(segs));
	N = n;
	FOR(i,0,n) A[segs[i].F.S]++;
	STB();

	int ans = -1;
	FOR(i,0,n) {
		if (check()) { ans = i; break; }

		int v = segs[i].F.S;
		int u = segs[i+n].F.S;

		STU(v, -1);
		STU(u, 1);
	}

	if (ans == -1) {
		printf("2\n0 0.5 %lld %lf\n0 %lf %lld 0.5", w, h-0.5, h-0.5, w);
	}
	else {
		printf("1\n");
		double ansx1 = segs[ans].S.F, ansy1 = segs[ans].S.S;
		double ansx2 = segs[ans+n].S.F, ansy2 = segs[ans+n].S.S;

		auto [x, y] = addDist(ansx1, ansy1, -0.5);
		auto [xx, yy] = addDist(ansx2, ansy2, -0.5);
		printf("%lf %lf %lf %lf\n", x, y, xx, yy);
	}


	return 0;
}
