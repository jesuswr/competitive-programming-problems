#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for (int i = n; i < (int)m; i++)
#define ROF(i,n,m) for (int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 6e3+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int r, c;

string grid[MAXN];

int best[MAXN/2][MAXN][10];

int dr[] = {0, -1, -1, 0, 1, 1};
int dc[] = {-1, 0, 1, 1, 0, 1};


bool valid(int ri, int ci) {
	return ri >= 0 && ci >= 0 && ri < r && ci < c;
}

ii mapCell(int ri, int ci) {
	return { 2*ri, (ri&1) ? 4*ci + 2 : 4*ci };
}

bool checkConnected(int ri, int ci, int rj, int cj) {
	auto [gri, gci] = mapCell(ri, ci);
	auto [grj, gcj] = mapCell(rj, cj);
	if (ri == rj) return grid[gri][(gci+gcj)/2] == '-';
	return grid[(gri+grj)/2][(gci+gcj)/2] != ' ';
}


int main() {
	cin >> r >> c;
	getline(cin, grid[MAXN-1]);
	FOR(i,0,2*r-1) { getline(cin, grid[i]); }

	FOR(ri,0,r) FOR(ci,0,c) {
		FOR(k,0,3) {
			int rj = ri+dr[k], cj = ci+dc[k];
			if(!valid(rj, cj)) continue;
			if(checkConnected(ri, ci, rj, cj)) best[ri][ci][k] = best[rj][cj][k] + 1;
		}
	}

	ROF(ri,r-1,-1) ROF(ci,c-1,-1) {
		FOR(k,3,6) {
			int rj = ri+dr[k], cj = ci+dc[k];
			if(!valid(rj, cj)) continue;
			if(checkConnected(ri, ci, rj, cj)) best[ri][ci][k] = best[rj][cj][k] + 1;
		}
	}

	int ans = 0;
	FOR(ri,0,r) FOR(ci,0,c) {
		FOR(k,1,min(best[ri][ci][1], best[ri][ci][2])+1) {
			int rj = ri + dr[1]*k, cj = ci + dc[1]*k;

			if (best[rj][cj][3] >= k) ans++;
		}
		FOR(k,1,min(best[ri][ci][4], best[ri][ci][5])+1) {
			int rj = ri + dr[4]*k, cj = ci + dc[4]*k;

			if (best[rj][cj][3] >= k) ans++;
		}
	}

	printf("%d\n", ans);


	return 0;
}
