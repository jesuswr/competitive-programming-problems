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

pt read_pt() {
	int a,b; rii(a,b);
	return pt(a,b);
}

int sgn(T a) {return (a < 0) - (a > 0);}
T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}

T dot(pt v, pt w) {return (conj(v)*w).x;}
T cross(pt v, pt w) {return (conj(v)*w).y;}

pt translate(pt v, pt p) {return p+v;} //Move p through v
pt scale(pt c, double fact, pt p) {return c + (p - c)*fact;}
pt rot(pt p, double a) {return p * polar(1.0, a);}
pt perp(pt p) {return {-p.y, p.x};}

T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

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
    pt refl(pt p) {return p - perp(v) * (T) 2 * side(p) / sq(v);}
};

bool inter(line l1, line l2, pt &out){
    T d = cross(l1.v, l2.v);
    if(d == 0) return false;
    out = (l2.v*l1.c - l1.v*l2.c) / d;
    return true;
}

double segPoint(pt a, pt b, pt p){
    if(a != b){
        line l(a, b);
        if(l.cmpProj(a, p) && l.cmpProj(p, b))
            return l.dist(p);
    }
    return min( abs(p-a), abs(p-b) );
}
double halfrayPoint(pt a, pt b, pt p){
    if(a != b){
        line l(a, b);
        if(l.cmpProj(a, p))
            return l.dist(p);
    }
    return abs(p-a);
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
double segSeg(pt a, pt b, pt c, pt d){
    pt aux;
    if(properInter(a, b, c, d, aux)) return 0;
    return min({segPoint(a, b, c), segPoint(a, b, d),
                segPoint(c, d, a), segPoint(c, d, b)});
}
double segHalfray(pt a, pt b, pt c, pt d){
    line cd(c, d);
	pt proj_a = cd.proj(a), proj_b = cd.proj(b);
	if (cd.cmpProj(d, proj_a)) d = proj_a;
	if (cd.cmpProj(d, proj_b)) d = proj_b;
	return segSeg(a, b, c, d);
}
double segLine(pt a, pt b, pt c, pt d){
    line cd(c, d);
	pt proj_a = cd.proj(a), proj_b = cd.proj(b);
	if (cd.cmpProj(d, proj_a)) d = proj_a;
	if (cd.cmpProj(d, proj_b)) d = proj_b;
	if (!cd.cmpProj(c, proj_a)) c = proj_a;
	if (!cd.cmpProj(c, proj_b)) c = proj_b;
	return segSeg(a, b, c, d);
}
double halfrayHalfRay(pt a, pt b, pt c, pt d){
    line ab(a,b), cd(c,d);
	pt i;
	if (inter(ab, cd, i)) {
		if (ab.cmpProj(a,i) && cd.cmpProj(c,i)) return 0;
	}
	return min(halfrayPoint(a,b,c), halfrayPoint(c,d,a));
}
double halfrayLine(pt a, pt b, pt c, pt d){
    line ab(a,b), cd(c,d);
	pt i;
	if (inter(ab, cd, i)) {
		if (ab.cmpProj(a,i)) return 0;
	}
	return cd.dist(a);
}
double lineLine(pt a, pt b, pt c, pt d){
    line ab(a,b), cd(c,d);
	pt i;
	if (inter(ab, cd, i)) {
		return 0;
	}
	return cd.dist(a);
}


int main(){
	pt a, b, c, d;
	a = read_pt();b = read_pt();c = read_pt();d = read_pt();

	line cd(c, d), ab(a, b);

	// The distance from the point A to the point C.
	printf("%.7lF\n", abs(c - a));
	// The distance from the point A to the segment CD.
	printf("%.7lF\n", segPoint(c, d, a));
	// The distance from the point A to the half-infinite ray CD.
	printf("%.7lF\n", halfrayPoint(c, d, a));
	// The distance from the point A to the line CD.
	printf("%.7lF\n", cd.dist(a));
	// The distance from the segment AB to the point C.
	printf("%.7lF\n", segPoint(a, b, c));
	// The distance from the segment AB to the segment CD.
	printf("%.7lF\n", segSeg(a, b, c, d));
	// The distance from the segment AB to the half-infinite ray CD.
	printf("%.7lF\n", segHalfray(a, b, c, d));
	// The distance from the segment AB to the line CD.
	printf("%.7lF\n", segLine(a, b, c, d));
	// The distance from the half-infinite ray AB to the point C.
	printf("%.7lF\n", halfrayPoint(a, b, c));
	// The distance from the half-infinite ray AB to the segment CD.
	printf("%.7lF\n", segHalfray(c, d, a, b));
	// The distance from the half-infinite ray AB to the half-infinite ray CD.
	printf("%.7lF\n", halfrayHalfRay(a, b, c, d));
	// The distance from the half-infinite ray AB to the line CD.
	printf("%.7lF\n", halfrayLine(a, b, c, d));
	// The distance from the line AB to the point C.
	printf("%.7lF\n", ab.dist(c));
	// The distance from the line AB to the segment CD.
	printf("%.7lF\n", segLine(c, d, a, b));
	// The distance from the line AB to the half-infinite ray CD.
	printf("%.7lF\n", halfrayLine(c, d, a, b));
	// The distance from the line AB to the line CD.
	printf("%.7lF\n", lineLine(a, b, c, d));
	


	return 0;
}
