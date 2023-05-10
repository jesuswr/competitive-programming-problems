#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second 
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
const int SQRT = 500;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct line {
	ll m, b;
};

bool cmp(line & a, line & b) {
	if (a.m == b.m) return a.b > b.b;
	return a.m < b.m;
}

ll inters(line l1, line l2) {
	return (l1.b - l2.b) / (l2.m - l1.m);
}

struct ConvexHull {
	vector <line> v;

	void add(line l) {
		int n = sz(v);
		while (n >= 2 && inters(v[n-1],v[n-2]) > inters(l, v[n-2])) {
			v.pop_back();
			n--;
		}
		
		v.pb(l);
	}

	ll query(ll x) {
		int l = 0, r = sz(v); r--;
		while (l < r) {
			int m = (l+r+1)>>1;
			if (inters(v[m], v[m-1]) > x) r = m-2;
			else l = m;
		}
		return v[l].m*x + v[l].b;
	}
};

int n, m;
ii P[MAXN];
line L[MAXN];
ConvexHull CH[1000];

vector<int> ans[MAXN];
vector<line> aux;

int main() {

	ri(n);
	FOR(i,0,n) rii(P[i].F, P[i].S);

	ri(m);
	FOR(i,0,m) {
		ll m, b;
		lrii(m, b);
		L[i].m = m;
		L[i].b = b;
	}

	
	FOR(i,0,m) {
		aux.pb(L[i]);
		if (i % SQRT == SQRT - 1) {
			sort(all(aux), cmp);
			FOR(j,0,sz(aux)) {
				if (j && L[j].m == L[j-1].m) continue;
				CH[i / SQRT].add(aux[j]);
			}
			aux.clear();
		}
	}

	int LST = (m-1) / SQRT;
	sort(all(aux), cmp);
	FOR(j,0,sz(aux)) {
		if (j && L[j].m == L[j-1].m && L[j].b == L[j-1].b) continue;
		CH[LST].add(aux[j]);
	}
	aux.clear();


	FOR(i,0,n) {
		auto [xx, yy] = P[i];
		FOR(j,0,LST+1) {
			ll y = CH[j].query(xx);
			if (y > yy) {
				FOR(k,j*SQRT,(j+1)*SQRT) {
					if (L[k].m * xx + L[k].b > yy) {
						ans[k].pb(i+1);
						break;
					}
				}
				break;
			}
		}
	}


	FOR(i,0,m) {
		printf("%d", sz(ans[i]));
		for(auto x : ans[i]) printf(" %d", x);
		printf("\n");
	}


	return 0;
}


