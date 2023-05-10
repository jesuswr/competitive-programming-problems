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
const int MAXN = 110;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int R, C;
int M[MAXN][MAXN];
vii A[MAXN][MAXN];
bool G[MAXN][MAXN];

bool good(int r, int c) {
	return r < R && c < C && min(r,c) >= 0;
}

vii MVs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
void calc_adj(int r, int c) {
	int mn = R*C + 69;
	for(auto [dr, dc] : MVs) {
		int nr = r + dr, nc = c + dc;
		if (good(nr, nc)) {
			mn = min(mn, M[nr][nc]);
			A[r][c].pb({nr, nc});
		}
	}
	G[r][c] = M[r][c] < mn;
}


int go(int r, int c) {
	priority_queue< tuple<int, int, int> > pq;
	int mx = -1;
	pq.push({-M[r][c], r, c});
	int ans = 0;
	while(!pq.empty()) {
		auto [v, r, c] = pq.top(); pq.pop();
		v = -v;
		if (v <= mx) continue;
		ans++;
		mx = v;
		for(auto [nr, nc] : A[r][c]) if (mx < M[nr][nc]) {
			pq.push({-M[nr][nc], nr, nc});
		}
	}
	return ans;
}



int main(){
	rii(R, C);
	FOR(i,0,R) FOR(j,0,C) ri(M[i][j]);
	FOR(i,0,R) FOR(j,0,C) calc_adj(i, j);
	int mx = 0;
	FOR(i,0,R) FOR(j,0,C) if (G[i][j]) mx = max(mx, go(i, j));
	cout << mx << endl;
	return 0;
}
