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

// Products
T dot(pt v, pt w) {return (conj(v) * w).x;}
T cross(pt v, pt w) {return (conj(v) * w).y;}

// Transformations
pt translate(pt v, pt p) {return p + v;} //Move p through v
pt scale(pt c, double fact, pt p) {return c + (p - c) * fact;}
pt rot(pt p, double a) {return p * polar(1.0, a);}
pt perp(pt p) {return { -p.y, p.x};}

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


pair<double, pt> segPoint(pt a, pt b, pt p) {
    if (a != b) {
        line l(a, b);
        if (l.cmpProj(a, p) && l.cmpProj(p, b))
            return {l.dist(p), l.proj(p)};
    }
    return (abs(p - a) <= abs(p - b)) ? (make_pair(abs(p - a), a)) : (make_pair(abs(p - b), b));
}

int main() {
    double a, b;
    while (scanf("%lF %lF", &a, &b) == 2) {
        pt p = {a, b};
        pt s, t;
        int n; ri(n);
        pair<double, pt> dst = {INFLL, p};
        FOR(i, 0, n + 1) {
            qwert = scanf("%lF %lF", &a, &b);
            t = {a, b};
            if (i > 0) {
                auto pos = segPoint(s, t, p);
                if (pos.F < dst.F)
                    dst = pos;
            }
            s = t;
        }
        printf("%.4lF\n%.4lF\n", dst.S.x, dst.S.y);
    }
    return 0;
}
