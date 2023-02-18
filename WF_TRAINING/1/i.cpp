
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
const int SQRTN = 500;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int P[MAXN];

int N, A, B;
struct block {
	set<int> a;
	vector< ii> l, r;
	void add(int i) {
		a.insert(i);
		l.pb({i - P[i], i});
		r.pb({i + P[i], i});
	}
	void build() {
		sort(all(l)); reverse(all(l));
		sort(all(r));
	}
	void erase(int x) {
		a.erase(x);
	}
	
};


void solve() {
	rii(N,A), ri(B);
	--A, --B;
	int M = (N + SQRTN - 1) / SQRTN;
	vector<block> segs( M );
	FOR(i,0,N) {
		ri(P[i]);
		segs[i / SQRTN].add(i);
	}
	FOR(i,0,M) segs[i].build();

	vi dst(N, INF);
	queue<int> q;
	q.push(A);
	dst[A] = 0;
	segs[A/SQRTN].erase(A);

	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (u == B) {
			printf("%d\n", dst[u]);
			break;
		}
		int l = u - P[u], r = u + P[u];
		int bu = u / SQRTN, bl = (l) / SQRTN, br = r / SQRTN; 
		bl = max(bl, 0);
		br = min(br, M-1);
		vi nexts;

		for(int bi = bl; bi <= br; ++bi) {
			if (bi == bl || bi == br || bi == bu) {
				for(int v : segs[bi].a) {
					if (abs(u - v) <= min(P[u], P[v])) nexts.push_back(v);
				}
			}
			else if (bi > bu) {
				while(!segs[bi].l.empty()) {
					auto [_, v] = segs[bi].l.back();
					if (dst[v] != INF || abs(u - v) <= min(P[u], P[v])) {
						if (dst[v] == INF) nexts.pb(v);
						segs[bi].l.pop_back();
					}
					else break;
				}
			}
			else {
				while(!segs[bi].r.empty()) {
					auto [_, v] = segs[bi].r.back();
					if (dst[v] != INF || abs(u - v) <= min(P[u], P[v])) {
						if (dst[v] == INF) nexts.pb(v);
						segs[bi].r.pop_back();
					}
					else break;
				}
			}
		}

		for(int v : nexts) {
			dst[v] = dst[u] + 1;
			q.push(v);
			segs[v / SQRTN].erase(v);
		}

	}


}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
