/*************************************
*    author: marvinthang             *
*    created: 09.08.2023 10:00:46    *
*************************************/

#include <bits/stdc++.h>

using namespace std;

#define                  fi  first
#define                  se  second
#define                left  ___left
#define               right  ___right
#define                TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define             MASK(i)  (1LL << (i))
#define           BIT(x, i)  ((x) >> (i) & 1)
#define  __builtin_popcount  __builtin_popcountll
#define              ALL(v)  (v).begin(), (v).end()
#define           REP(i, n)  for (int i = 0, _n = (n); i < _n; ++i)
#define          REPD(i, n)  for (int i = (n); i-- > 0; )
#define        FOR(i, a, b)  for (int i = (a), _b = (b); i < _b; ++i) 
#define       FORD(i, b, a)  for (int i = (b), _a = (a); --i >= _a; ) 
#define       FORE(i, a, b)  for (int i = (a), _b = (b); i <= _b; ++i) 
#define      FORDE(i, b, a)  for (int i = (b), _a = (a); i >= _a; --i) 
#define        scan_op(...)  istream & operator >> (istream &in, __VA_ARGS__ &u)
#define       print_op(...)  ostream & operator << (ostream &out, const __VA_ARGS__ &u)
#ifdef LOCAL
#else
    #define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
    #define DB(...) 23
    #define db(...) 23
    #define debug(...) 23
#endif

template <class U, class V> scan_op(pair <U, V>)  { return in >> u.first >> u.second; }
template <class T> scan_op(vector <T>)  { for (size_t i = 0; i < u.size(); ++i) in >> u[i]; return in; }
template <class U, class V> print_op(pair <U, V>)  { return out << '(' << u.first << ", " << u.second << ')'; }
template <size_t i, class T> ostream & print_tuple_utils(ostream &out, const T &tup) { if constexpr(i == tuple_size<T>::value) return out << ")";  else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); }
template <class ...U> print_op(tuple<U...>) { return print_tuple_utils<0, tuple<U...>>(out, u); }
template <class Con, class = decltype(begin(declval<Con>()))> typename enable_if <!is_same<Con, string>::value, ostream&>::type operator << (ostream &out, const Con &con) { out << '{'; for (__typeof(con.begin()) it = con.begin(); it != con.end(); ++it) out << (it == con.begin() ? "" : ", ") << *it; return out << '}'; }
template <class A, class B> bool minimize(A &a, B b)  { if (a > b) { a = b; return true; } return false; }
template <class A, class B> bool maximize(A &a, B b)  { if (a < b) { a = b; return true; } return false; }

// end of template

const long long INF = 1e18;
const int MAX = 2.5e5 + 5;

int N;
vector <pair <int, int>> adj[2][MAX];

void init(void) {
	cin >> N;
	REP(i, 2) {
		REP(love, N - 1) {
			int u, v, w; cin >> u >> v >> w;
			adj[i][u].emplace_back(w, v);
			adj[i][v].emplace_back(w, u);
		}
	}
}

bool used[2][MAX];
int treeSize[MAX];

void dfsSize(int t, int u, int par) {
	treeSize[u] = 1;
	for (auto [w, v]: adj[t][u]) if (!used[t][v] && v != par) {
		dfsSize(t, v, u);
		treeSize[u] += treeSize[v];
	}
}

int findCentroid(int t, int u, int par, int n) {
	for (auto [w, v]: adj[t][u]) if (!used[t][v] && v != par && treeSize[v] > n / 2) return findCentroid(t, v, u, n);
	return u;
}

vector <pair <int, long long>> anc[MAX];

void buildCentroidTree(int cen) {
	dfsSize(0, cen, 0);
	cen = findCentroid(0, cen, 0, treeSize[cen]);

	function <void(int, int, long long)> dfs = [&] (int u, int par, long long dist) {
		anc[u].emplace_back(cen, dist);
		for (auto [w, v]: adj[0][u]) if (!used[0][v] && v != par) dfs(v, u, dist + w);
	};
	dfs(cen, 0, 0);
	used[0][cen] = true;
	for (auto [w, v]: adj[0][cen]) if (!used[0][v]) buildCentroidTree(v);
}

long long res[MAX];
pair <long long, long long> best[MAX];
int exist[MAX], lab;

void solve(int cen) {
	dfsSize(1, cen, 0);
	cen = findCentroid(1, cen, 0, treeSize[cen]);
	++lab;
	vector <pair <int, long long>> f;
	function <void(int, int, long long)> dfs = [&] (int u, int par, long long dist) {
		f.emplace_back(u, dist);
		for (auto [anc, d0]: anc[u]) {
			if (exist[anc] != lab) {
				exist[anc] = lab;
				best[anc] = make_pair(INF, INF);
			}
			if (best[anc].fi > dist + d0) best[anc].se = best[anc].fi, best[anc].fi = dist + d0;
			else minimize(best[anc].se, dist + d0);
		}
		for (auto [w, v]: adj[1][u]) if (!used[1][v] && v != par) dfs(v, u, dist + w);
	};
	dfs(cen, 0, 0);
	for (auto [u, d1]: f) for (auto [anc, d0]: anc[u]) {
		minimize(res[u], d0 + d1 + (best[anc].fi == d0 + d1 ? best[anc].se : best[anc].fi));
	}
	used[1][cen] = true;
	for (auto [w, v]: adj[1][cen]) if (!used[1][v]) solve(v);
}

void process(void) {
	buildCentroidTree(1);
	memset(res, 0x3f, sizeof(res));
	solve(1);
	FORE(i, 1, N) cout << res[i] << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); // cout.tie(nullptr);
	init();
	process();
	cerr << "Time elapsed: " << TIME << " s.\n";
	return (0^0);
}