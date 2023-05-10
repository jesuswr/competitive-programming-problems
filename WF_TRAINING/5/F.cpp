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
const ll INFLL = 2e18;
const int MOD = 1e9+7;
const int MAXN = 100+5;
const long double PI = 3.14159265358979323846;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct circle {
	long double x, y, r, er;
	circle(){};
	circle(long double _x, long double _y, long double _r, long double _er) {
		x = _x; y = _y; r = _r; er = _er;
	}
	void read() {
		cin >> x >> y >> r >> er;
	}
	long double area() {
		return PI * r * r;
	}
};

long double dist(const circle &a, const circle &b) {
	return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
}

long double get_t(const circle &a, const circle &b) {
	long double l = 0, h = INFLL;
	long double d = dist(a, b);
	FOR(_,0,100) {
		long double m = (l + h) / 2;
		if (d <= a.r + m * a.er + b.r + m * b.er) h = m;
		else l = m;
	}
	return l;
}

circle circle_merge(vector<circle> &a) {
	int n = sz(a);
	long double x_sm = 0, y_sm = 0, a_sm = 0, er_mx = 0;
	for(circle &c : a) {
		x_sm += c.x;
		y_sm += c.y;
		a_sm += c.area();
		er_mx = max(er_mx, c.er);
	}
	long double new_r = sqrt(a_sm / PI);
	return circle(x_sm/n, y_sm/n, new_r, er_mx);
}

int N;
long double T[MAXN][MAXN];

circle go(vector<circle> &a) {
	int n = sz(a);
	if (n == 1) return a[0];
	int c1 = 0, c2 = 1;
	long double t = INFLL;

	FOR(i,0,n) FOR(j,i+1,n) {
		long double _t = get_t(a[i], a[j]);
		if (_t < t) {
			t = _t;
			c1 = i;
			c2 = j;
		}
	}

	FOR(i,0,n) a[i].r += a[i].er * t;

	vector<bool> used(n);
	used[c1] = used[c2] = 1;
	vector<circle> to_merge;
	to_merge.pb(a[c1]);
	to_merge.pb(a[c2]);

	while(to_merge.size() > 1) {
		circle res = circle_merge(to_merge);
		to_merge.clear();
		to_merge.pb(res);
		FOR(i,0,n) if (!used[i] && dist(res, a[i]) <= res.r + a[i].r) {
			to_merge.pb(a[i]);
			used[i] = 1;
		}
	}

	vector<circle> new_a;
	FOR(i,0,n) if (!used[i]) new_a.pb(a[i]);
	new_a.pb(to_merge[0]);
	return go(new_a);
}


int main(){
	ri(N);
	vector<circle> a;
	FOR(i,0,N) {
		circle c;
		c.read();
		a.pb(c);
	}
	circle c = go(a);
	printf("%.8Lf %.8Lf\n%.8Lf\n", c.x, c.y, c.r);
	return 0;
}
