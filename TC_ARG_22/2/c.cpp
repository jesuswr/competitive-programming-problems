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



int main(){
	ii s, e;
	rii(s.F, s.S); rii(e.F, e.S);

	int n; ri(n);
	map<ii, bool> h;
	FOR(_,0,n) {
		int r, a, b;
		rii(r,a), ri(b);
		FOR(i,a,b+1) h[{r,i}] = 1;
	}

	map<ii, int> dst;
	queue<ii> q;

	q.push(s);
	dst[s] = 0;
	while(!q.empty()) {
		auto [r,c] = q.front(); q.pop();
		if (!h[{r,c}]) continue;

		for(int dr : {1,0,-1}) for(int dc : {1,0,-1}) if (dr != 0 || dc != 0) {
			int nr = r + dr, nc = c + dc;
			if (dst.find({nr, nc}) == dst.end()) {
				dst[{nr, nc}] = dst[{r, c}] + 1;
				q.push({nr, nc});
			}
		}
	}

	if (dst.find(e) != dst.end()) cout << dst[e] << endl;
	else cout << -1 << endl;

	return 0;
}
