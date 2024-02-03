#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef ll T;
typedef complex<T> pt;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
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

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n;
vector<pt> poly;

T sq(pt p) {return p.x*p.x + p.y*p.y;}
T cross(pt v, pt w) {return (conj(v)*w).y;}
T orient(pt a, pt b, pt c) {return cross(b-a, c-a);}

struct line {
	pt v; T c;
	line(pt p, pt q) : v(q-p), c(cross(v, p)) {}
	T side(pt p) {return cross(v, p) - c;}
	double sqDist(pt p) {return side(p)*side(p) / (double)sq(v);}
};

bool cmp(pt &a, pt &b) {
	return make_tuple(a.x, a.y) < make_tuple(b.x, b.y);
}

vector<pt> buildCH(vector<pt> &P) {
	vector<pt> UH, LH;

	sort(all(P), cmp);
	for (auto p : P) {
		while (sz(UH) >= 2 && orient(UH[sz(UH)-2], UH.back(), p) >= 0) UH.pop_back();
		UH.pb(p);
	}

	reverse(all(P));
	for (auto p : P) {
		while (sz(LH) >= 2 && orient(LH[sz(LH)-2], LH.back(), p) >= 0) LH.pop_back();
		LH.pb(p);
	}

	for (auto p : UH) if (p != UH[0] && p != UH.back()) UH.pb(p);
	return UH;
}

double getFurthest(vector<pt> &CH, int i) {
	line L(CH[i], CH[(i+1)%sz(CH)]);
	cout << CH[i].x << " " << CH[i].y << " " << CH[(i+1)%sz(CH)].x << " " << CH[(i+1)%sz(CH)].y << endl;
	double best = 0;
	for (auto p : CH) best = max(best,L.sqDist(p));
	cout << best << endl;
	return best;
}

double getBest(vector<pt> &CH) {
	double best = INFLL;
	FOR(i,0,sz(CH)) best = min(best, getFurthest(CH, i));
	return sqrt(best);
}




int main() {

	ri(n);
	int tc = 0;
	while(n > 0) {
		FOR(i,0,n) {
			int xx, yy;
			rii(xx,yy);
			poly.pb({xx, yy});
		}

		vector<pt> CH = buildCH(poly);
		double ans = getBest(CH);

		ll a = ceil(100*ans);
		printf("Case %d: %lld.%lld\n", ++tc, a/100, a%100);

		poly.clear();
		ri(n);
	}

	


	return 0;
}
