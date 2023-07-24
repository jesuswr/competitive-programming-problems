#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
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

typedef long long T;
typedef complex<T> pt;
#define x real() // DO NOT USE x & y AS VARIABLE NAMES!!!
#define y imag()
#define mkt make_tuple
const double PI = 2*acos(0.0);


int sgn(T a) {return (a < 0) - (a > 0);}
T sq(pt p) {return p.x*p.x + p.y*p.y;}
T dot(pt v, pt w) {return (conj(v)*w).x;}
T cross(pt v, pt w) {return (conj(v)*w).y;}
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
    bool cmpProj(pt p, pt q) {return dot(v,p) < dot(v,q);}
};

double segPointSq(pt a, pt b, pt p){
    if(a != b){
        line l(a, b);
        if(l.cmpProj(a, p) && l.cmpProj(p, b))
            return l.sqDist(p);
    }
    return min( sq(p-a), sq(p-b) );
}

pt C[2];
int N[2];
vector<pt> Poly[2];

pt readpt() {
	int a, b; cin >> a >> b;
	return pt(a,b);
}

bool go(pt cp, vector<pt> p, pt cq, vector<pt> q) {
	for(pt pt_circle : p) {
		// pt center = pt_circle + (cp - cq);
		pt center = pt_circle + (cq - cp);
		ll rad_sq = sq(pt_circle - center);
		// cout << center.x << " " << center.y << endl;
		for(int i = 0; i < sz(q); ++i) {
			pt l = q[i], r = q[(i+1) % sz(q)];
			if ( segPointSq(l, r, center) <= rad_sq && max(sq(center - l), sq(center - r)) >= rad_sq )
				return true;
		}
	}
	return false;
}

int main(){
	FOR(i,0,2) {
		C[i] = readpt();
		cin >> N[i];
		Poly[i].resize(N[i]);
		FOR(j,0,N[i]) Poly[i][j] = readpt();
	}	


	// go(C[1], Poly[1], C[0], Poly[0]);
	if (go(C[0], Poly[0], C[1], Poly[1]) || go(C[1], Poly[1], C[0], Poly[0]))
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;

	return 0;
}
