#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

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
#define x real() // DO NOT USE x & y AS VARIABLE NAMES!!!
#define y imag()


const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 100+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
typedef long double T;
typedef complex<T> pt;

T cross(pt v, pt w) {return (conj(v)*w).y;}
pt scale(pt c, ld fact, pt p) {return c + (p - c)*fact;}
ld areaPoly(vector<pt> &p){
    ld area = 0.0;
    int n = p.size();
    FOR(i,0,n)
        area += cross(p[i], p[(i+1)%n]);
    return abs(area) / 2.0;
}
T sq(pt p) {return p.x*p.x + p.y*p.y;}
long double abs(pt p) {return sqrt(sq(p));}

pt read() {
	ld a, b; cin >> a >> b;
	return pt(a, b);
}

const int MX = 1e5 + 1e4;

int main(){
	pt c = read();
	ld r; cin >> r;
	int n; cin >> n;
	vector<pt> ps;
	FOR(i,0,n) ps.pb(read());

	ld sm = 0;
	vector<pair<pt, pt>> p;
	FOR(i,0,n) {
		int nxt = (i + 1) % n;
		pt dir = (ps[nxt] - ps[i]) / (ld)MX;
		pt q = ps[i];
		pt lst, fst;
		FOR(i,0,MX) {
			ld dst = r * r / abs(q - c);
			pt q_dir = (q - c) / abs(q - c);
			pt _p = c + dst * q_dir;
			if (i > 0) sm += cross(lst, _p);
			else fst = _p;
			lst = _p;
			q = q + dir;
		}
		p.pb({fst, lst});
	}
	n = sz(p);
	FOR(i,0,n) {
		sm += cross(p[i].S, p[(i+1)%n].F);
	}
	printf("%.10Lf\n", abs(sm) / 2);
	return 0;
}
