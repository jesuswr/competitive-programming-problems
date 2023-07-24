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
double angle(pt v, pt w){ // Range [0, pi]
    double cosTh = dot(v,w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTh)));
}
bool inAngle(pt a, pt b, pt c, pt p){ // P is in angle BAC
    assert(orient(a,b,c) != 0);
    if(orient(a,b,c) < 0) swap(b, c);
    return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}


int main(){
	pt a,b,c;
    a = read_pt();
    b = read_pt();
    c = read_pt();

    double op_a = abs(c-b), op_b = abs(c-a), op_c = abs(a-b);

    pt center( (a.x * op_a + b.x * op_b + c.x * op_c) / (op_a + op_b + op_c) , (a.y * op_a + b.y * op_b + c.y * op_c) / (op_a + op_b + op_c) );
    double s = (op_a + op_b + op_c) / 2;
    double r = sqrt((s - op_a) * (s - op_b) * (s - op_c) / s);
    printf("%lF %lF %lF\n", center.x, center.y, r);

	return 0;
}
