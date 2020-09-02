#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
struct STN {
	STN *l, *r;
	int val;
	STN(int val) : l(0), r(0), val(val) {}
	STN(STN *l, STN *r) : l(l), r(r), val(0) {
		if (l) val += l->val;
		if (r) val += r->val;
	}
};

int N, A[MAXN];

STN* STB(int l = 0, int r = N) {
	if (r - l < 2) return new STN(0);
	int m = (l + r) >> 1;
	return new STN(STB(l, m), STB(m, r));
}
int STQ(STN *lo, STN* hi, int k, int l = 0, int r = N) {
	if (r - l < 2)
		return l;

	int m = (l + r) >> 1;
	int count = (hi->l->val) - (lo->l->val);
	if (count >= k)
		return STQ(lo->l, hi->l, k, l, m);
	else
		return STQ(lo->r, hi->r, k - count, m, r);
}
STN* STU(int p, int x, STN *v, int l = 0, int r = N) {
	if (r - l < 2) return new STN(x + v->val);
	int m = (l + r) >> 1;
	if (p < m)
		return new STN(STU(p, x, v->l, l, m), v->r);
	else
		return new STN(v->l, STU(p, x, v->r, m, r));
}

STN* UPD[MAXN];
int A2[MAXN];
map<int, int> old_to_new, new_to_old;


int main() {
	int n, m; rii(n, m);
	FOR(i, 0, n) {
		ri(A[i]);
		A2[i] = A[i];
	}
	sort(A2, A2 + n);
	int curr = 0;
	int i = 0;
	while (i < n) {
		old_to_new[A2[i]] = curr;
		new_to_old[curr++] = A2[i];
		int j = i;
		while (i < n && A2[i] == A2[j])
			i++;
	}
	N = MAXN;

	// AHORA SI
	UPD[0] = STB();
	FOR(i, 0, n) {
		UPD[i + 1] = STU(old_to_new[A[i]], 1, UPD[i]);
	}

	while (m--) {
		int i, j, k;
		riii(i, j, k);
		int ans = STQ(UPD[i - 1], UPD[j], k);
		printf("%d\n", new_to_old[ans]);
	}


	return 0;
}