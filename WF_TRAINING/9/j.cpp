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

int N, M, X;
vector<tuple<int,int,long double>> E;
long double EPS = 1e-2;

void add_edge(int a, int b, long double w) {
	E.pb({a,b,w});
}
int k;
void add_edges(int A, int B, int C, int D) {
	 if (A==B&&C==D) {
			E.pb({A, C, X});
			E.pb({C, A, -X});
        }
        else if (A==C&&B==D) {
			E.pb({B, A, -X-1});
        }
        else {
			E.pb({B, C, X-1});
			E.pb({D, A, -X-1});
        }
}

void solve() {
	rii(N,M), ri(X);
	k = N;
	E.clear(); E.reserve(M + N);
	while(M--) {
		int a,b,c,d; rii(a,b), rii(c,d);
		--a; --b; --c; --d;
		add_edges(a,b,c,d);
		++k;
	}
	FOR(i,0,N-1) {
		E.pb({i, i+1, 2e9});
		E.pb({i+1, i, -1});
	}

	


	vector<long double> DST(N, INFLL);
	DST[0] = 0;
	bool change = 1;
	FOR(i,0,N + 10) {
		change = false;

		for(auto [from, to, wei] : E) {
			if (DST[from] + wei < DST[to]) {
				DST[to] = DST[from] + wei;
				change = 69;
			}
		}
	}

	if (change) {
		printf(" IMPOSSIBLE\n");
		return;
	}

	FOR(i,1,N) {
		printf(" %.13Lf", DST[i] - DST[i-1]);
	}
	printf("\n");

}


int main(){
	int t; ri(t);
	FOR(i,0,t) {
		printf("Case #%d:", i+1);
		solve();
	}
	return 0;
}
