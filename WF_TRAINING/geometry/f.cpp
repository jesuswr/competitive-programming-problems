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

/**
 * Author: Marcos Lerones
 * Description: 2D points useful functions
 */
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

void read(pt &p) {
	int a,b; cin >> a >> b;
	p = pt(a,b);
}

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

double segPoint(pt a, pt b, pt p){
    if(a != b){
        line l(a, b);
        if(l.cmpProj(a, p) && l.cmpProj(p, b))
            return l.dist(p);
    }
    return min( abs(p-a), abs(p-b) );
}

pt go(pt a, pt b, pt c, double r) {
	pt dir = (b - a) / abs(b - a);
	double lo = 0, hi = abs(b-a);
	FOR(i,0,400) {
		double mi = (lo + hi) / 2;
		pt pm = a + dir * mi;
		if (abs(a - pm) <= r) 
			lo = mi;
		else
			hi = mi;
	}
	return a + dir * lo;
}

void print(const pt &a) {
	cout << a.x << " " << a.y << endl;
}


pair<pt, pt> intersectTwoCircles(double x1, double y1, double r1, double x2, double y2, double r2) {
    double centerdx = x1 - x2;
    double centerdy = y1 - y2;
    double R = std::sqrt(centerdx * centerdx + centerdy * centerdy);
    if (!(std::abs(r1 - r2) <= R && R <= r1 + r2)) { // no intersection
        throw 69;
    }
    // intersection(s) should exist

    double R2 = R * R;
    double R4 = R2 * R2;
    double a = (r1 * r1 - r2 * r2) / (2 * R2);
    double r2r2 = (r1 * r1 - r2 * r2);
    double c = std::sqrt(2 * (r1 * r1 + r2 * r2) / R2 - (r2r2 * r2r2) / R4 - 1);

    double fx = (x1 + x2) / 2 + a * (x2 - x1);
    double gx = c * (y2 - y1) / 2;
    double ix1 = fx + gx;
    double ix2 = fx - gx;

    double fy = (y1 + y2) / 2 + a * (y2 - y1);
    double gy = c * (x1 - x2) / 2;
    double iy1 = fy + gy;
    double iy2 = fy - gy;

    // note if gy == 0 and gx == 0 then the circles are tangent and there is only one solution
    // but that one solution will just be duplicated as the code is currently written
    return {{ix1, iy1}, {ix2, iy2}};
}

int main(){
	pt p, q, c; double r;
	read(p);
	read(q);
	read(c);
	cin >> r;

	if (segPoint(p, q, c) >= r) {
		printf("%.9lF\n", abs(p-q));
		return 0;
	}

	try {
		pt aux_p = p + (c - p) / (T)2;
		auto [p1, p2] = intersectTwoCircles(c.x, c.y, r, aux_p.x, aux_p.y, abs(aux_p - p));

		pt aux_q = q + (c - q) / (T)2;
		auto [q1, q2] = intersectTwoCircles(c.x, c.y, r, aux_q.x, aux_q.y, abs(aux_q - q));

		// print(p1);
		// print(p2);
		// print(q1);
		// print(q2);

		printf("%.9lF\n", min({
			abs(p - p1) + abs(q - q1) + r * angle(p1-c,q1-c),
			abs(p - p1) + abs(q - q2) + r * angle(p1-c,q2-c),
			abs(p - p2) + abs(q - q1) + r * angle(p2-c,q1-c),
			abs(p - p2) + abs(q - q2) + r * angle(p2-c,q2-c)
		}));


	} catch (int error) {
		printf("%.9lF\n", abs(p-q));
	}




	return 0;
}
