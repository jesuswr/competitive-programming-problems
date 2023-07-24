#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef double T;
typedef complex<T> pt;
#define x real() // DO NOT USE x & y AS VARIABLE NAMES!!!
#define y imag()
#define mkt make_tuple
const double PI = 2*acos(0.0);


int sgn(T a) {return (a < 0) - (a > 0);}
T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}

// Transformations
pt translate(pt v, pt p) {return p+v;} //Move p through v
pt scale(pt c, double fact, pt p) {return c + (p - c)*fact;}
pt rot(pt p, double a) {return p * polar(1.0, a);}
pt perp(pt p) {return {-p.y, p.x};}

// Arbitrary linear Transformation f given f(p) and f(q)
pt linearTransfo(pt p, pt q, pt r, pt fp, pt fq){
    return fp + (r-p) * (fq-fp) / (q-p);
}

// Products
T dot(pt v, pt w) {return (conj(v)*w).x;}
T cross(pt v, pt w) {return (conj(v)*w).y;}

// Orientation
bool isPerp(pt v, pt w) {return dot(v, w) == 0;}
double angle(pt v, pt w){ // Range [0, pi]
    double cosTh = dot(v,w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTh)));
}
// > 0 c is left of ab, < 0 c is right, = 0 colinear
T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}
bool inAngle(pt a, pt b, pt c, pt p){ // P is in angle BAC
    assert(orient(a,b,c) != 0);
    if(orient(a,b,c) < 0) swap(b, c);
    return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}
double orientAngle(pt a, pt b, pt c){
    return (orient(a,b,c) >= 0) ?
            angle(b-a,c-a) : 2*PI - angle(b-a,c-a);
}
bool isConvex(vector<pt> p){
    bool hasPos = 0, hasNeg = 0;
    int n = p.size();
    FOR(i,0,n){
        int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
        if(o > 0) hasPos = 1;
        if(o < 0) hasNeg = 1;
    }
    return !(hasPos && hasNeg);
}

/**
 * Author: Marcos Lerones
 * Description: 2D lines useful functions
 */
struct line {
    pt v; T c;
    // Direction v, Offset c
    line(pt v, T c) : v(v), c(c) {}
    // Eq ax + by = c
    line(T a, T b, T c) : v(b, -a), c(c) {}
    // Points p and q
    line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
    // < 0 right, = 0 inline, > 0 left
    T side(pt p) {return cross(v, p) - c;}
    double dist(pt p) {return abs(side(p)) / abs(v);}
    double sqDist(pt p) {return side(p)*side(p) / (double)sq(v);}
    line perpThrough(pt p) {return {p, p + perp(v)};}
    bool cmpProj(pt p, pt q) {return dot(v,p) < dot(v,q);}
    line translate(pt t) {return {v, c + cross(v, t)};}
    line shiftLeft(double d) {return {v, c + d*abs(v)};}
    pt proj(pt p) {return p - perp(v) * side(p) / sq(v);}
    pt refl(pt p) {return p - perp(v) * (T)2 * side(p) / sq(v);}
};

bool inter(line l1, line l2, pt &out){
    T d = cross(l1.v, l2.v);
    if(d == 0) return false;
    out = (l2.v*l1.c - l1.v*l2.c) / d;
    return true;
}

// Interior: bisector pointing between 2 directions
line bisector(line l1, line l2, bool interior){
    assert(cross(l1.v, l2.v) != 0);
    double sign = interior ? 1 : -1;
    return {l2.v/abs(l2.v) + l1.v/abs(l1.v) * sign,
            l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign};
}
bool inDisk(pt a, pt b, pt p){
    return dot(a-p, b-p) <= 0;
}
bool onSegment(pt a, pt b, pt p){
    return orient(a,b,p) == 0 && inDisk(a,b,p);
}
bool properInter(pt a, pt b, pt c, pt d, pt &out){
    double oa = orient(c, d, a),
           ob = orient(c, d, b),
           oc = orient(a, b, c),
           od = orient(a, b, d);
    if(oa*ob < 0 && oc*od < 0){
        out = (a*ob - b*oa) / (ob - oa);
        return true;
    }
    return false;
}
struct cmpX{
    bool operator()(pt a, pt b) const {
        return mkt(a.x, a.y) < mkt(b.x, b.y);
    }
};
set <pt,cmpX> inters(pt a, pt b, pt c, pt d){
    pt out;
    if(properInter(a, b, c, d, out)) return {out};
    set<pt,cmpX> s;
    if(onSegment(c, d, a)) s.insert(a);
    if(onSegment(c, d, b)) s.insert(b);
    if(onSegment(a, b, c)) s.insert(c);
    if(onSegment(a, b, d)) s.insert(d);
    return s;
}
double segPoint(pt a, pt b, pt p){
    if(a != b){
        line l(a, b);
        if(l.cmpProj(a, p) && l.cmpProj(p, b))
            return l.dist(p);
    }
    return min( abs(p-a), abs(p-b) );
}
double segSeg(pt a, pt b, pt c, pt d){
    pt aux;
    if(properInter(a, b, c, d, aux)) return 0;
    return min({segPoint(a, b, c), segPoint(a, b, d),
                segPoint(c, d, a), segPoint(c, d, b)});
}

pt read() {
	int a,b; rii(a,b);
	return pt(a,b);
}

double f(pt s1, pt s2, pt e1, pt e2, double t, pt vs, pt ve) {
	s1 = s1 + vs * t;
	s2 = s2 + vs * t;
	e1 = e1 + ve * t;
	e2 = e2 + ve * t;
	return segSeg(s1, s2, e1, e2);
}

int main(){

	pt a1, a2, b1, b2;
	a1 = read();
	a2 = read();
	b1 = read();
	b2 = read();
	pt va, vb;
	va = read();
	vb = read();
 
	double lo = 0, hi = 1e12;
	FOR(_,0,200) {
		double a = lo + (hi - lo) / 3, b = lo + 2 * (hi - lo) / 3;
		double dst = f(a1, a2, b1, b2, a, va, vb), dst2 = f(a1, a2, b1, b2, b, va, vb);
		if (dst > dst2) lo = a;
		else hi = b;
	}

	if ( f(a1, a2, b1, b2, lo, va, vb) <= 1e-8) cout << lo << endl;
	else cout << -1 << endl;


	return 0;
}
