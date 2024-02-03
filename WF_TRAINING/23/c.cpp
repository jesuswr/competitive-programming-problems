#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef double T;
typedef complex<T> pt;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first
#define x real()
#define y imag()


const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
const double EPS = 1e-7;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

T cross(pt v, pt w) {return (conj(v)*w).y;}

int n;
vector<pt> P;

pair<pt, T> getCenter() {
	pt center = {0.0, 0.0};
	T area = 0;
	FOR(i,0,n) {
		int j = (i+1)%n;
		T a = cross(P[i], P[j]);
		area += a;

		center += (P[i] + P[j]) * a;
	}

	return {center / (3.0 * area), abs(area) / 2.0};
}

int baseL, baseR;

int main() {
	ri(n);

	baseL = INF, baseR = -INF;
	FOR(i,0,n) {
		int xx, yy; rii(xx, yy);
		P.pb({1.0*xx, 1.0*yy});
		if (yy == 0) baseL = min(baseL, xx), baseR = max(baseR, xx);
	}

	pt p = P[0];
	auto [C, area] = getCenter();
    cout << C.x << endl;
	if (C.x < baseL && p.x < baseL) { printf("unstable\n"); return 0; }
	if (C.x > baseR && p.x > baseR) { printf("unstable\n"); return 0; }
	
	ll L, R;
	if (C.x < baseL) { L = floor(((baseL - C.x) * area) / (p.x - baseL) + EPS); }
	else if (C.x > baseR) { L = floor(((baseR - C.x) * area) / (p.x - baseR) + EPS); }
	else L = 0;

	if (p.x < baseL) { R = ceil(((baseL - C.x) * area) / (p.x - baseL) - EPS); }
	else if (p.x > baseR) { R = ceil(((baseR - C.x) * area) / (p.x - baseR) - EPS); }
	else R = INFLL;


	printf("%lld .. ", max(L, 0ll));
	if (R >= INFLL) printf("inf\n");
	else printf("%lld\n", R);



	return 0;
}

