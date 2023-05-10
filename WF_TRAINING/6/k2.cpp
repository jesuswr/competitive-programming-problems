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
ll DST[MAXN][30];

struct QUERY {
	int l, r, bl, br, i; 
};

void assign(int i, int j, ll v) {
	if (i > j) swap(i,j);
	DST[i][j-i] = v;
}
ll get(int i, int j) {
	if (i > j) swap(i, j);
	return DST[i][j-i];
}


struct MAT
{
	ll m[10][10];
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

MAT Ms[25010];
ll ANS [25010];
int A[25010], B[25010], AB[25010], BB[25010];

MAT f(int a) {
	a = 10 * a;
	MAT A, B;
	FOR(i, a, a + 10) FOR(j, a + 10, a + 20)
	{
		A.m[i - a][j - a - 10] = get(i,j);
	}
	FOR(i, a, a + 10) FOR(j, a, a + 10)
	{
		B.m[i - a][j - a] = get(i,j);
	}
	return B * A;
}

void update(int i, const MAT &m) {
	if (Ms[i].m[0][0] == -1) Ms[i] = m;
	else Ms[i] = Ms[i] * m;
}

MAT go(int l, int r, const vector<int> &qs) {
	if (l == r) {
		MAT ret = f(l);
		for(const int &q : qs) update(q, ret);
		// cout << 10 * l << endl;
		// ret.print();
		return ret;
	}

	int m = (r + l) >> 1;
	vector<int> lft, rgt, cnt;
	for(const int &q : qs) {
		if (AB[q] <= l && BB[q] >= r) cnt.pb(q);
		else {
			if (AB[q] <= m) lft.pb(q);
			if (BB[q] > m) rgt.pb(q);
		}
	}
	MAT m1 = go(l, m, lft);
	MAT m2 = go(m+1, r, rgt);
	MAT ret = m1 * m2;
	for(const int &q : cnt) update(q, ret);
	return ret;
}


int main()
{
	rii(N, M), ri(Q);
	N += 10 - (N % 10);
	FOR(i, 0, N + 30) FOR(j, 1, 30) DST[i][j] = INFLL;
	FOR(i, 0, N + 30) DST[i][0] = 0;
	FOR(i, 0, M)
	{
		int u, v;
		rii(u, v);
		int c;
		ri(c);
		--u, --v;
		if (u > v)
			swap(u, v);
		assign(u,v,c);
	}
	for (int i = 1; i <= N; i++)
		for (int j = max(1, i - 11); j <= min(i + 11, N); j++)
			for (int k = max(1, i - 11); k <= min(i + 11, N); k++)
				assign(j-1, k-1,  min(get(j-1, k-1), get(i-1, j-1) + get(i-1, k-1)) );
	for (int i = N; i > 0; --i)
		for (int j = min(i + 11, N); j >= max(i - 11, 1); --j)
			for (int k = max(i - 11, 1); k <= min(i + 11, N); k++)
				assign(j-1, k-1,  min(get(j-1, k-1), get(i-1, j-1) + get(i-1, k-1)) );
	vector<int> qs;
	FOR(i,0,Q) {
		Ms[i].m[0][0] = -1;
		rii(A[i],B[i]); --A[i]; --B[i];
		if(A[i] > B[i]) swap(A[i], B[i]);
		int ab = A[i] / 10, bb = B[i] / 10;
		AB[i] = ab; BB[i] = bb;
		if (ab != bb) {
			qs.pb(i);
			BB[i]--;
			ANS[i] = -2;
		}
		else 
			ANS[i] = get(A[i], B[i]);
	}
	go(0, N/10-1, qs);
	FOR(i,0,Q) {
		if(ANS[i] == -2) {
			ANS[i] = Ms[i].m[A[i]%10][B[i]%10];
		}
		if (ANS[i] >= INFLL) ANS[i] = -1;
		printf("%lld\n", ANS[i]);
	}

	return 0;
}
