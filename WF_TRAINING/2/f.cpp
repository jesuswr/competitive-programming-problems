#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef ll T;
typedef complex<T> pt;

#define FOR(i,n,m) for(int i = n; i < m; i++)
#define ROF(i,n,m) for(int i = n; i > m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first
#define x real()
#define y imag()
#define mkt make_tuple

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll BIT[MAXN];
void updBIT(int p, ll val) {
	p++;
	for(; p < MAXN; p += p&-p) BIT[p] += val;
}
ll sumBIT(int p) {
	p++;
	ll ret = 0;
	for(; p; p -= p&-p) ret += BIT[p];
	return ret;
}

T sq(pt v) { return v.x*v.x + v.y*v.y; }
T cross(pt v, pt w) {return (conj(v)*w).y;}
int sgn(T a) { return (a < 0) - (a > 0); } 

bool polarCmpACW(pair<pt, int> v, pair<pt, int> w) {
	return  mkt(0, sq(v.F), v.S) < mkt(cross(v.F, w.F), sq(w.F), w.S);
}
bool polarCmpCW(pair<pt, int> v, pair<pt, int> w) {
	return  mkt(0, sq(v.F), v.S) < mkt(-cross(v.F, w.F), sq(w.F), w.S);
}

void polarSortACW(vector<pair<pt, int>> &v) {
	sort(all(v), polarCmpACW);
}
void polarSortCW(vector<pair<pt, int>> &v) {
	sort(all(v), polarCmpCW);
}


pt start, last;
vector<pair<pt, int>> L;
vector<pair<pt, int>> R;

int place[MAXN];



int main() {
	int n;
	ll xx, yy;
	lrii(xx, yy); start = { xx, yy };
	lrii(xx, yy); last = { xx, yy };

	last -= start;

	ri(n);
	FOR(i,0,n) {
		lrii(xx, yy); 
		
		pt p = { xx, yy };
		p -= start;

		if (cross(last, p) == 0) {
			if (last.x == 0 and sgn(last.y) == sgn(p.y)) L.pb({p, i});
			else if (last.x != 0 and sgn(last.x) == sgn(p.x)) L.pb({p, i});
			else R.pb({p, i});
		}
		else if (cross(last, p) > 0) L.pb({p, i});
		else R.pb({p, i});
	}

	start -= start;

	polarSortACW(L);
	polarSortCW(R);

	FOR(i,0,sz(L)) {
		auto [p, id] = L[i];
		place[id] = i;
		L[i] = {p - last, id};
	}
	FOR(i,0,sz(R)) {
		auto [p, id] = R[i];
		place[id] = i;
		R[i] = {p - last, id};
	}

	last = -last;

	polarSortCW(L);
	polarSortACW(R);

	ll ans = 0;

	for (auto [p, id] : L) {
		ans += sumBIT(id);
        cout << p << " " << sumBIT(id) << endl;
		updBIT(id, 1);
	}

	ms(BIT, 0);

	for (auto [p, id] : R) {
		ans += sumBIT(id);
		updBIT(id, 1);
	}

	printf("%lld\n", ans);

	return 0;
}


