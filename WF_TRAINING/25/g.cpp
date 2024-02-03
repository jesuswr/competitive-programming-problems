#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long T;
typedef complex<T> pt;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a),ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a),lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first
#define x real()
#define y imag()
#define mkt make_tuple

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

void fastIO() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
}



int sgn(T a) {return (a > 0) - (a < 0);}
T cross(pt v, pt w) {return (conj(v)*w).y;}

struct line {
	pt v; T c;
	line(pt p, pt q) : v(q-p), c(cross(v,p)) { }
	T side(pt p) {return cross(v, p) - c;}
};

bool half(pt p) {
	assert(p.x != 0 || p.y != 0);
	return p.y > 0 || (p.y == 0 && p.x < 0);
}


struct event {
	pt p; bool out; ll val;
};

bool angleCmp(event v, event w) {
	return mkt(half(v.p), 0, v.out) < mkt(half(v.p), cross(v.p, w.p), v.out);
}

int n;
pair<pt, pt> segs[2345];



ll check(pt p) {
	ll ans = 0;
	vector<event> v;
	FOR(i,0,n) if(p.y < segs[i].F.y) {
		ll val = segs[i].S.x - segs[i].F.x;
		v.pb({ segs[i].F-p, true, -val });
		v.pb({ segs[i].S-p, false, val });
	}

	sort(all(v), angleCmp);
	ll acum = 0;
	for (auto e : v) {
		acum += e.val;
		ans = max(ans, acum);
	}

	return ans;
}

ll check_xxx(pt p, pt q) {
	ll ans = 0;
	line L(p, q);
	FOR (i,0,n) {
		if (sgn(L.side(segs[i].F)) != sgn(L.side(segs[i].S)))
			ans += segs[i].S.x - segs[i].F.x;
	}

	return ans;
}

int main() {
	ri(n);

	ll ans = 0;
	FOR(i,0,n) {
		ll L, R, yy;
		lrii(L, R); lri(yy);
		if (L > R) swap(L, R);

		ans = max(ans, R-L);

		segs[i] = { {L, yy}, {R, yy} };
	}

 	FOR(i,0,n) {
 		ll val = segs[i].S.x - segs[i].F.x;
 		ans = max(ans, val + check(segs[i].F));
 		ans = max(ans, val + check(segs[i].S));
 	}

//	FOR (i,0,n) FOR(j,i+1,n) if (segs[i].F.y != segs[j].F.y) {
//		ans = max(ans, check(segs[i].F, segs[j].F));
//		ans = max(ans, check(segs[i].F, segs[j].S));
//		ans = max(ans, check(segs[i].S, segs[j].S));
//		ans = max(ans, check(segs[i].S, segs[j].F));
//	}


	printf("%lld\n", ans);


	return 0;
}
