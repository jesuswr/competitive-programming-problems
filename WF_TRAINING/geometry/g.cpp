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

typedef long double T;
typedef complex<T> pt;
#define x real()
#define y imag()

T sq(pt p) {return p.x*p.x + p.y*p.y;}
long double abs(pt p) {return sqrt(sq(p));}

T cross(pt v, pt w) {return (conj(v)*w).y;}
T orient(pt a, pt b, pt c) {return cross(b-a, c-a);}
 
bool cmp(pt a, pt b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
 
T mDist (pt a, pt b) {
	return max(llabs(a.x - b.x), llabs(a.y - b.y));
}
 
vector <pt> convexHull (vector <pt> &P) {
	sort(all(P), cmp);
	vector <pt> UH;
	vector <pt> LH;
 
	for (auto p : P) {
		while (sz(UH) >= 2 && orient(UH[sz(UH)-2], UH.back(), p) >= 0) UH.pop_back();
		UH.pb(p);
	}
 
	reverse(all(P));
 
	for (auto p : P) {
		while (sz(LH) >= 2 && orient(LH[sz(LH)-2], LH.back(), p) >= 0) LH.pop_back();
		LH.pb(p);
	}
 
 
	for (auto p : LH) if (p != UH.back() and p != UH[0]) UH.pb(p);
	return UH;
}

map<ii, int> mp;
int main(){
	int n; ri(n);
	vector<pt> p(n);
	FOR(i,0,n) {
		int a,b; rii(a,b);
		p[i] = pt(a,b);
		mp[{a,b}] = i+1;
	}


	auto ch = convexHull(p);
	cout << sz(ch) << endl;
	reverse(all(ch));
	for(pt a : ch) cout << mp[ {a.x, a.y} ] << " ";
	cout << endl;

	long double per = 0, are = 0;
	n = sz(ch);
	for(int i = 0; i < sz(ch); ++i) {
		per += abs(ch[i] - ch[(i+1)%n]);
		are += cross(ch[i], ch[(i+1)%n]);
	}
	are = abs(are) / 2.0;
	printf("%.16Lf\n%.16Lf\n", per, are);
	return 0;
}
