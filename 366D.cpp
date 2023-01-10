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
#define ri(a) dasdas = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e3 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int V, E;
vector<tuple<int,int,int>> G[MAXN];

ii inters(int l, int r, int l2, int r2){
	return {max(l, l2), min(r, r2)};
}

int go(){
	priority_queue<tuple<int, int, int>> pq;
	map< ii , int > cst;

	pq.push({INF, 1, 1});
	cst[{1, 1}] = INF;

	while(!pq.empty()){
		auto [c, u, l] = pq.top(); pq.pop();
		int r = l + c - 1;
		if (u == V) return c;
		for (auto [v, vl, vr] : G[u]){
			auto [nl, nr] = inters(l, r, vl, vr);
			if (nr - nl + 1 > cst[{v, nl}]) {
				cst[{v, nl}] = nr - nl + 1;
				pq.push({nr - nl + 1, v, nl});
			}
		}
	}
	return 0;
}

int main(){
	rii(V,E);
	FOR(_,0,E){
		int u, v, l, h;
		rii(u,v), rii(l,h);
		G[u].pb({v,l,h});
		G[v].pb({u,l,h});
	}
	int ans = go();
	if (ans == 0) printf("Nice work, Dima!\n");
	else printf("%d\n", ans);
	return 0;
}
