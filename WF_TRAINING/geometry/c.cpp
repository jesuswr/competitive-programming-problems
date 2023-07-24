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

int main(){
	pt a, b, c, d;
	a = read_pt();b = read_pt();c = read_pt();d = read_pt();

    auto st = inters(a,b,c,d);
    if (sz(st) == 0) printf("Empty\n");
    else {
        for(pt p : st) 
            printf("%lF %lF\n", p.x, p.y);
    }
	


	return 0;
}
