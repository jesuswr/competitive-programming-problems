#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int A[MAXN], NXT_MN[MAXN], NXT_MX[MAXN];
struct STN {
	int mni, mn;
	int mxi, mx;
	void merge(STN& L, STN& R) {
		mn = min(L.mn, R.mn);
		if (mn == L.mn)
			mni = L.mni;
		else
			mni = R.mni;

		mx = max(L.mx, R.mx);
		if (mx == L.mx)
			mxi = L.mxi;
		else
			mxi = R.mxi;
	}
	void operator=(int a) {
		mni = a;
		mn = A[a];
		mxi = a;
		mx = A[a];
	}
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id] = l;
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STB(L, l, m); STB(R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
	if (x == l && y == r) return ST[id];
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (x >= m) return STQ(x, y, R, m, r);
	if (y <= m) return STQ(x, y, L, l, m);
	STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
	return res.merge(ln, rn), res;
}

void pre() {
	stack<int> nxt_mn, nxt_mx;
	A[N] = 1e9;
	nxt_mn.push(N); nxt_mx.push(N);
	for (int i = N - 1; i >= 0; --i) {
		while (nxt_mn.top() != N && A[i] < A[nxt_mn.top()]) nxt_mn.pop();
		while (nxt_mx.top() != N && A[i] > A[nxt_mx.top()]) nxt_mx.pop();
		NXT_MN[i] = nxt_mn.top();
		NXT_MX[i] = nxt_mx.top();
		nxt_mn.push(i);
		nxt_mx.push(i);
	}
	STB();
}

int f(int u, int l) {
	if (u + 1 == N) return 0;
	if (l == 0) { // up
		int border = NXT_MN[u];
		if (border == u + 1) return INF;
		return f(STQ(u + 1, border).mxi , 1) + 1;
	}
	else { // ~up
		int border = NXT_MX[u];
		if (border == u + 1) return INF;
		return f(STQ(u + 1, border).mni , 0) + 1;
	}
}

void solve() {
	ri(N);
	FOR(i, 0, N) ri(A[i]);
	pre();
	printf("%d\n", min(f(0, 0), f(0, 1)));
}

int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}