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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
struct arit_prog {
	ll l, a, d;
};
int N;
struct STN {
	ll val = 0;
	void merge(STN& L, STN& R) {}
	void operator=(ll a) {}
};
STN ST[4 * MAXN];
queue<arit_prog> lzy[4 * MAXN];
// Actualiza el nodo y guarda en lzy
void upd(int id, int l, int r, arit_prog x) {
	lzy[id].push(x);
}

void add(int id, int l, int r) {
	while (!lzy[id].empty()) {
		auto aux = lzy[id].front(); lzy[id].pop();
		ST[id].val += aux.a + (l - aux.l) * aux.d;
	}
}

// Propaga el update en lzy
void shift(int id, int l, int r) {
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	while (!lzy[id].empty()) {
		upd(L, l, m, lzy[id].front());
		upd(R, m, r, lzy[id].front());
		lzy[id].pop();
	}
}
STN STQ(int pos, int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		add(id, l, r);
		return ST[id];
	}
	shift(id, l, r);
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (pos >= m) return STQ(pos, R, m, r);
	else return STQ(pos, L, l, m);
}
void STU(int x, int y, arit_prog v, int id = 1, int l = 0, int r = N) {
	if (x >= r || y <= l) return;
	if (x <= l && y >= r) {
		upd(id, l, r, v);
		return;
	}
	shift(id, l, r);
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STU(x, y, v, L, l, m);
	STU(x, y, v, R, m, r);
}

int main() {
	int m;
	rii(N, m);
	FOR(_, 0, m) {
		int type; ri(type);
		if (type == 1) {
			int l, r, a, d; rii(l, r); rii(a, d); l--;
			arit_prog aux = {l, a, d};
			STU(l, r, aux);
		}
		else {
			int pos; ri(pos); pos--;
			printf("%lld\n", STQ(pos).val);
		}
	}

	return 0;
}