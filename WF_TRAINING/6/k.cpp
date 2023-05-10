#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i, n, m) for (int i = n; i < (int)m; i++)
#define ROF(i, n, m) for (int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) dasdas = scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) dasdas = scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 69;

void fastIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M, Q;
map<int, map<int, ll>> DST;

struct MAT
{
	array<array<ll, 10>, 10> m;
	MAT operator*(const MAT &b)
	{
		MAT r;
		FOR(i, 0, 10) FOR(j, 0, 10) r.m[i][j] = INFLL;
		FOR(i, 0, 10) FOR(k, 0, 10) if (m[i][k] < INFLL) FOR(j, 0, 10) r.m[i][j] = min(r.m[i][j], m[i][k] + b.m[k][j]);
		return r;
	}
	void print()
	{
		FOR(i, 0, 10)
			FOR(j, 0, 10) if (m[i][j] < INFLL) cout << i << " " << j << "\t:\t" << m[i][j] << endl;
	}
};

struct STN
{
	MAT M;
	void merge(STN &L, STN &R)
	{
		M = L.M * R.M;
	}
	void operator=(int a)
	{
		a = 10 * a;
		MAT A, B;
		FOR(i, a, a + 10) FOR(j, a + 10, a + 20)
		{
			A.m[i - a][j - a - 10] = DST[i][j];
		}
		FOR(i, a, a + 10) FOR(j, a, a + 10)
		{
			B.m[i - a][j - a] = DST[min(i, j)][max(i, j)];
		}
		M = B * A;
		// cout << a << endl;
		// A.print();
		// cout << "----------------------------0-" << endl;
		// B.print();
		// cout << "+++++++++++++++++++++++++++" << endl;
		// M.print();
		// cout << "*****************************" << endl;
	}
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N)
{
	if (r - l < 2)
	{
		ST[id] = l;
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STB(L, l, m);
	STB(R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
STN ANS, aux;
STN STQ(int x, int y, int id = 1, int l = 0, int r = N)
{
	if (x == l && y == r)
		return ST[id];
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (x >= m)
		return STQ(x, y, R, m, r);
	if (y <= m)
		return STQ(x, y, L, l, m);
	STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
	return res.merge(ln, rn), res;
}

int main()
{
	rii(N, M), ri(Q);
	N += 10 - (N % 10);
	FOR(i, 0, N + 30) FOR(j, 1, 30) DST[i][i + j] = INFLL;
	FOR(i, 0, N + 30) DST[i][i] = 0;
	FOR(i, 0, M)
	{
		int u, v;
		rii(u, v);
		int c;
		ri(c);
		--u, --v;
		if (u > v)
			swap(u, v);
		DST[u][v] = DST[v][u] = c;
	}
	for (int i = 1; i <= N; i++)
		for (int j = max(1, i - 12); j <= min(i + 12, N); j++)
			for (int k = max(1, i - 12); k <= min(i + 12, N); k++)
				DST[min(j - 1, k - 1)][max(j - 1, k - 1)] = min(DST[min(j - 1, k - 1)][max(j - 1, k - 1)], DST[min(i - 1, j - 1)][max(i - 1, j - 1)] + DST[min(i - 1, k - 1)][max(i - 1, k - 1)]);
	for (int i = N; i > 0; --i)
		for (int j = min(i + 12, N); j >= max(i - 12, 1); --j)
			for (int k = max(i - 12, 1); k <= min(i + 12, N); k++)
				DST[min(j - 1, k - 1)][max(j - 1, k - 1)] = min(DST[min(j - 1, k - 1)][max(j - 1, k - 1)], DST[min(i - 1, j - 1)][max(i - 1, j - 1)] + DST[min(i - 1, k - 1)][max(i - 1, k - 1)]);

	N /= 10;
	STB();

	map<ii, MAT> mem;
	while (Q--)
	{
		int a, b;
		rii(a, b);
		--a, --b;
		if (a > b)
			swap(a, b);
		if (b - a < 10)
		{
			ll ans = DST[a][b];
			if (ans >= INFLL)
				ans = -1;
			cout << ans << endl;
			continue;
		}
		if (mem.find({a/10, b/10}) != mem.end()) {
			ll x = mem[{a/10, b/10}].m[a%10][b%10];
			if (x >= INFLL)
				x = -1;
			cout << x << endl;
			continue;
		}
		auto st = STQ(a / 10, b / 10);
		ll x = st.M.m[a % 10][b % 10];
		if (x >= INFLL)
			x = -1;
		cout << x << endl;
		mem[{a/10, b/10}] = st.M;
	}

	return 0;
}
