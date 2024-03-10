#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef ll T;
typedef complex<T> pt;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) das=scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int sgn(T a) {return (a > 0) - (a < 0);}
T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}

T dot(pt v, pt w) {return (conj(v)*w).x;}
T cross(pt v, pt w) {return (conj(v)*w).y;}
// > 0 c is left of ab, < 0 c is right, = 0 colinear
T orient(pt a, pt b, pt c) {
    return cross(b-a,c-a);}
 
bool cmp(pt a, pt b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
 
T mDist (pt a, pt b) {
	return max(llabs(a.x - b.x), llabs(a.y - b.y));
}
 
vector <pt> convexHull (vector <pt> P) {
	sort(all(P), cmp);
	vector <pt> UH;
	vector <pt> LH;
 
	for (auto p : P) {
		while (sz(UH) >= 2 && orient(UH[sz(UH)-2], UH.back(), p) >= 0) UH.pop_back();
		UH.pb(p);
	}
 
	reverse(all(P));
 
	for (auto p : P) {
		while (sz(LH) >= 2 && orient(LH[sz(LH)-2], LH.back(), p) >= 0) LH.pop_back();
		LH.pb(p);
	}
 
 
	for (auto p : LH) if (p != UH.back() and p != UH[0]) UH.pb(p);
	return UH;
}

int half(pt p) { return p.y != 0 ? sgn(p.y) : -sgn(p.x); }
void polarSort(vector<pt> &v) {
    sort(all(v), [](pt v, pt w) {
        return mkt(half(v), 0, sq(v)) <
               mkt(half(w), cross(v, w), sq(w));
    });
}

ii f(pt p) {
    return {p.x, p.y};
}

int n;
vector <pt> S;



int main() {
    ri(n);
    FOR(i,0,n) {
        ll xx, yy; lrii(xx, yy);
        S.pb({xx, yy});
    }

    vector<pt> CH = convexHull(S);

    set<ii> inCH;
    for(pt p : CH) inCH.insert(f(p));

    int ans = 1;

    for(auto p : S) if (inCH.find(f(p)) == inCH.end()) {
        vector<pt> points;
        for(auto q : S) if (p != q) points.pb(q - p);
        polarSort(points);

        FOR(i,0,sz(points)) {
            pt prv = points[i] + p, nxt = points[ (i+1) % sz(points) ] + p;
            ans += (inCH.find(f(prv)) != inCH.end() && inCH.find(f(nxt)) != inCH.end());
        }
    }
    cout << ans << endl;

    return 0;
}
