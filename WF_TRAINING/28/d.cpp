#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second 
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e6+5;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
void fastIO() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
}

int sgn(int x) {return (x > 0) - (x < 0);}

	

int n;
int A[MAXN];

vi ids[MAXN], prf[MAXN];

int CNT;
int M[MAXN];

int N[MAXN];
struct STN{
	int val;
	void merge(STN& L, STN& R) { val = min(L.val, R.val); }
	void operator=(int a) { val = a; }
};

vector<STN> ST[MAXN];
void STB(int k, int id, int l, int r) {
//	printf("%d %d %d\n", k, l, r);
	if (r - l < 2) {
		ST[k][id] = prf[k][l];
		return;
	}
	int m = (l+r)>>1, L = id<<1, R = L|1;
	STB(k, L, l, m); STB(k, R, m, r);
	ST[k][id].merge(ST[k][L], ST[k][R]);
}
STN STQ(int k, int x, int y, int id, int l, int r) {
	if (x == l && y == r) return ST[k][id];
	int m = (l+r)>>1, L = id<<1, R = L|1;
	if(x >= m) return STQ(k, x, y, R, m, r);
	if(y <= m) return STQ(k, x, y, L, l, m);
	STN res, ln = STQ(k, x, m, L, l, m), rn = STQ(k, m, y, R, m, r);
	return res.merge(ln, rn), res;
}

int fst[MAXN], lst[MAXN];
int NXT;

int main() {


	fastIO();

	cin >> n;
	FOR(i,0,n) {
		string s;
		cin >> s;

		int t = 0;
		FOR(i,1,sz(s)) t *= 10, t += s[i] - '0';

		if (!M[t]) M[t] = ++CNT;
		if (s[0] == 's') A[NXT++] = (M[t]);
		else A[NXT++] = (-M[t]);
	}

	FOR(i,0,n) A[i+n] = (A[i]);
	FOR(i,0,2*n) {
		int v = abs(A[i])-1;
		ids[v].pb(i);
		if (prf[v].empty()) prf[v].pb(sgn(A[i]));
		else prf[v].pb(prf[v].back() + sgn(A[i]));
	}


	set <int> cur;

	FOR(i,0,CNT) { 
		N[i] = sz(ids[i]); 
		ST[i] = vector<STN>(4*N[i]); 
		STB(i, 1, 0, N[i]); 
	}

	FOR(i,0,CNT) { while (ids[i][lst[i]] < n) lst[i]++; }
	FOR(i,0,CNT) { 
		if (prf[i][lst[i]-1] != 0) continue;
		int val = STQ(i, fst[i], lst[i], 1, 0, N[i]).val;
		if (val < 0) continue;
		cur.insert(i);
	}

	int best = 0, score = sz(cur);
	FOR(i,1,n) {
		int v = abs(A[i-1])-1;
		fst[v]++;
		int u = abs(A[i+n-1])-1;
		lst[u]++;

		if (prf[v][lst[v]-1] - (fst[v] > 0 ? prf[v][fst[v]-1] : 0) != 0) cur.erase(v);
		else {
			int val = STQ(v, fst[v], lst[v], 1, 0, N[v]).val;
			val -= (fst[v] > 0 ? prf[v][fst[v]-1] : 0);
			if (val < 0) cur.erase(v);
			else cur.insert(v);
		}

		if (prf[u][lst[u]-1] - (fst[u] > 0 ? prf[u][fst[u]-1] : 0) != 0) cur.erase(u);
		else {
			int val = STQ(u, fst[u], lst[u], 1, 0, N[u]).val;
			val -= (fst[u] > 0 ? prf[u][fst[u]-1] : 0);
			if (val < 0) cur.erase(u);
			else cur.insert(u);
		}

		if (score < sz(cur)) { best = i, score = sz(cur); }
	}


	cout << best+1 << " " << score << endl;

	



	return 0;
}
