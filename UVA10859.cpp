#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int _d;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) _d=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) _d=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e3+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int V,E;
vi G[MAXN];

ii DP[MAXN][2];
ii f(int u, int o, int p) {
	if (DP[u][o].F != -1) return DP[u][o];

	int cnt_on = 0, cnt_2x = 0;
	if (o){
		cnt_on++;
		for(int v : G[u]) if (v != p){
			ii op1 = f(v, 1, u), op2 = f(v, 0, u);
			if (op1.F < op2.F) {
				cnt_on += op1.F;
				cnt_2x += op1.S + 1;
			}
			else if (op1.F > op2.F) {
				cnt_on += op2.F;
				cnt_2x += op2.S;
			}
			else {
				if (op1.S >= op2.S) {
					cnt_on += op1.F;
					cnt_2x += op1.S + 1;
				}
				else {
					cnt_on += op2.F;
					cnt_2x += op2.S;
				}
			}
		}
	}
	else{
		for(int v : G[u]) if (v != p){
			ii op = f(v, 1, u);
			cnt_on += op.F;
			cnt_2x += op.S;
		}
	}

	return DP[u][o] = {cnt_on, cnt_2x};
}

void solve(){
	rii(V,E);
	FOR(i,0,V){
		DP[i][0].F = DP[i][1].F = -1;
		G[i].clear();
	}
	FOR(_,0,E){
		int a,b; rii(a,b);
		G[a].pb(b);
		G[b].pb(a);
	}

	int on = 0, dbl = 0;
	for(int i = 0; i < V; ++i){
		if (DP[i][0].F != -1) continue;

		ii op1 = f(i, 1, -1), op2 = f(i, 0, -1);
		if (op1.F < op2.F) {
			on += op1.F;
			dbl += op1.S;
		}
		else if (op1.F > op2.F) {
			on += op2.F;
			dbl += op2.S;
		}
		else {
			if (op1.S >= op2.S) {
				on += op1.F;
				dbl += op1.S;
			}
			else {
				on += op2.F;
				dbl += op2.S;
			}
		}
	}

	printf("%d %d %d\n", on, dbl, E - dbl);
}

int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
