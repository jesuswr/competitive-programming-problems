#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}




typedef double T;
typedef complex<T> pt;
#define x real() // DO NOT USE x & y AS VARIABLE NAMES!!!
#define y imag()
#define mkt make_tuple
const double PI = 2 * acos(0.0);


int sgn(T a) {return (a < 0) - (a > 0);}
T sq(pt p) {return p.x * p.x + p.y * p.y;}
double abs(pt p) {return sqrt(sq(p));}

// Transformations
pt translate(pt v, pt p) {return p + v;} //Move p through v
pt scale(pt c, double fact, pt p) {return c + (p - c) * fact;}
pt rot(pt p, double a) {return p * polar(1.0, a);}
pt perp(pt p) {return { -p.y, p.x};}

// Arbitrary linear Transformation f given f(p) and f(q)
pt linearTransfo(pt p, pt q, pt r, pt fp, pt fq) {
    return fp + (r - p) * (fq - fp) / (q - p);
}

// Products
T dot(pt v, pt w) {return (conj(v) * w).x;}
T cross(pt v, pt w) {return (conj(v) * w).y;}

// Orientation
bool isPerp(pt v, pt w) {return dot(v, w) == 0;}
double angle(pt v, pt w) { // Range [0, pi]
    double cosTh = dot(v, w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTh)));
}
// < 0 c is left of ab, > 0 c is right, = 0 colinear
T orient(pt a, pt b, pt c) {return cross(b - a, c - a);}


struct line {
    pt v; T c;
    // Direction v, Offset c
    line(pt v, T c) : v(v), c(c) {}
    // Eq ax + by = c
    line(T a, T b, T c) : v(b, -a), c(c) {}
    // Points p and q
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}
    // < 0 right, = 0 inline, > 0 left
    T side(pt p) {return cross(v, p) - c;}
    double dist(pt p) {return abs(side(p)) / abs(v);}
    double sqDist(pt p) {return side(p) * side(p) / (double)sq(v);}
    line perpThrough(pt p) {return {p, p + perp(v)};}
    bool cmpProj(pt p, pt q) {return dot(v, p) < dot(v, q);}
    line translate(pt t) {return {v, c + cross(v, t)};}
    line shiftLeft(double d) {return {v, c + d * abs(v)};}
    pt proj(pt p) {return p - perp(v) * side(p) / sq(v);}
    pt refl(pt p) {return p - perp(v) * 2.0 * side(p) / sq(v);}
};

bool inter(line l1, line l2, pt &out) {
    T d = cross(l1.v, l2.v);
    if (d == 0) return false;
    out = (l2.v * l1.c - l1.v * l2.c) / d;
    return true;
}



int main() {
    int t; ri(t);
    printf("INTERSECTING LINES OUTPUT\n");
    while (t--) {
        int x1, x2, x3, x4, y1, y2, y3, y4; rii(x1, y1); rii(x2, y2); rii(x3, y3); rii(x4, y4);
        line l1({x1, y1}, {x2, y2}), l2({x3, y3}, {x4, y4});
        pt ans;
        if (inter(l1, l2, ans)) printf("POINT %.2lF %.2lF\n", ans.x, ans.y);
        else if (l1.dist({x3, y3}) <= 1e-6) printf("LINE\n");
        else printf("NONE\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
