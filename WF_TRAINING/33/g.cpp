#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef double T;
typedef complex<T> pt;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a),ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) ri(a),ri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first
#define x real()
#define y imag()
#define mkt make_tuple

const double PI = 2*acos(0.0);
const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

int sgn(T a) {return (a > 0) - (a < 0);}
T sq(pt p) { return p.x*p.x + p.y*p.y; }
double abs(pt p) { return sqrt(sq(p)); }

pt perp(pt p) {return  { -p.y, p.x}; }

T dot(pt v, pt w) {return (conj(v)*w).x;}
T cross(pt v, pt w) {return (conj(v)*w).y;}

double angle(pt v, pt w) { 
    double cosTh = dot(v, w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTh)));
}

struct line {
    pt v; T c;
    line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
    T side(pt p) {return cross(v, p) - c;}
    double sqDist(pt p) {return side(p)*side(p) / (double) sq(v);}
    bool cmpProj(pt p, pt q) {return dot(v, p) < dot(v, q);}
    pt proj(pt p) {return p - perp(v) * side(p) / sq(v); }

};

int circleLine(pt o, double r, line l, pair<pt,pt> &out) {
    double h2 = r*r - l.sqDist(o);
    if (h2 >= 0) {
        pt p = l.proj(o);
        pt h = l.v*sqrt(h2)/abs(l.v);
        out = {p - h, p + h};
    }
    return 1 + sgn(h2);
}

bool checkInside(pt A, pt B, pt m, line L) {
    return (L.cmpProj(A, B) == L.cmpProj(A, m)) && (L.cmpProj(B, m) == L.cmpProj(B, A));
}

bool checkDirect(pt A, pt B, int R) {
    if (sq(A) <= R*R || sq(B) <= R*R) return true;

    line L(A, B);

    pair<pt,pt> out;
    int inters = circleLine( {0.0, 0.0}, R, L, out);

    return inters > 0 && (checkInside(A, B, out.F, L) || checkInside(A, B, out.S, L));
}

double polarDist(pt A, pt B) {
    double r = A.x, r2 = r*r, s = B.x, s2 = s*s;
    double tha = A.y, thb = B.y;
    return sqrt(r2 + s2 - 2*r*s*cos(thb - tha));
}

double getDist(pt A, pt B, pt mid) {
    return polarDist(A, mid) + polarDist(mid, B);
}

double TS(pt polarA, pt polarB, double R) {
    double lo = 0.0, hi = polarB.y;
    int cnt = 80;

    while (cnt--) {
        double m1 = lo + (hi - lo) / 3;
        double m2 = lo + (2 * (hi - lo) / 3);

        pt p1 = {R, m1}, p2 = {R, m2};
        if (getDist(polarA, polarB, p1) < getDist(polarA, polarB, p2)) hi = m2;
        else lo = m1;
    }

    pt opt = {R, lo};

    return getDist(polarA, polarB, opt);
}

int main() {
    int T; ri(T);
    while (T--) {
        pt A, B, C;
        int R;

        int xx, yy;
        rii(xx, yy); A = {1.0*xx, 1.0*yy};
        rii(xx, yy); B = {1.0*xx, 1.0*yy};
        rii(xx, yy); C = {1.0*xx, 1.0*yy};
        ri(R);

        A -= C; B -= C;

        if (checkDirect(A, B, R)) {
            printf("%.11lf\n", abs(A - B));
            continue;
        }

        pt polarA = { abs(A), 0.0 };
        pt polarB = { abs(B), angle(A, B) };

        double result = TS(polarA, polarB, R);

        printf("%.11lf\n", result);




    }

    return 0;
}