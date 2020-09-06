#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 2010; // CAMBIAR ESTE

// GJNM
int n, m;
char MAT[MAXN][MAXN];
int mv[MAXN][MAXN][4]; // up down left right
bool vis[MAXN][MAXN];
int cst[MAXN][MAXN];
char to[MAXN][MAXN];

int f(int r, int c) {
	queue<pii> bfs;
	bfs.push({r, c});
	vis[r][c] = true;
	while (!bfs.empty()) {
		int nr = bfs.front().F, nc = bfs.front().S; bfs.pop();
		if (MAT[nr][nc] == 'E')
			return cst[nr][nc];

		if (mv[nr][nc][1] != -1 && (!vis[ mv[nr][nc][1] ][nc])) {
			cst[ mv[nr][nc][1] ][nc] = cst[nr][nc] + 1;
			to[ mv[nr][nc][1] ][nc] = 'D';
			bfs.push( {mv[nr][nc][1], nc} );
			vis[ mv[nr][nc][1] ][nc] = true;
		}
		if (mv[nr][nc][2] != -1 && (!vis[nr][ mv[nr][nc][2] ])) {
			cst[nr][ mv[nr][nc][2] ] = cst[nr][nc] + 1;
			to[nr][ mv[nr][nc][2] ] = 'L';
			bfs.push( {nr, mv[nr][nc][2]} );
			vis[nr][mv[nr][nc][2]] = true;
		}
		if (mv[nr][nc][3] != -1 && (!vis[nr][ mv[nr][nc][3] ])) {
			cst[nr][ mv[nr][nc][3] ] = cst[nr][nc] + 1;
			to[nr][ mv[nr][nc][3] ] = 'R';
			bfs.push( {nr, mv[nr][nc][3]} );
			vis[nr][mv[nr][nc][3]] = true;
		}
		if (mv[nr][nc][0] != -1 && (!vis[ mv[nr][nc][0] ][nc])) {
			cst[ mv[nr][nc][0] ][nc] = cst[nr][nc] + 1;
			to[ mv[nr][nc][0] ][nc] = 'U';
			bfs.push( {mv[nr][nc][0], nc} );
			vis[mv[nr][nc][0]][nc] = true;
		}




	}
	return -1;
}


int main() {
	rii(n, m);
	FOR(i, 0, n) {
		scanf("%s", MAT[i]);
	}

	FOR(i, 0, n) {
		FOR(j, 0, m) {
			mv[i][j][0] = mv[i][j][1] = mv[i][j][2] = mv[i][j][3] = -1;
		}
	}
	FOR(c, 0, m) {
		// up
		int lst = -1;
		FOR(r, 0, n) {
			if (MAT[r][c] == 'X') continue;
			mv[r][c][0] = lst;
			lst = r;
		}
		// down
		lst = -1;
		ROF(r, n - 1, -1) {
			if (MAT[r][c] == 'X') continue;
			mv[r][c][1] = lst;
			lst = r;
		}
	}

	FOR(r, 0, n) {
		// left
		int lst = -1;
		FOR(c, 0, m) {
			if (MAT[r][c] == 'X') continue;
			mv[r][c][2] = lst;
			lst = c;
		}

		// right
		lst = -1;
		ROF(c, m - 1, -1) {
			if (MAT[r][c] == 'X') continue;
			mv[r][c][3] = lst;
			lst = c;
		}
	}

	int start_r, start_c;
	int end_r, end_c;
	FOR(r, 0, n) {
		FOR(c, 0, m) {
			if ( MAT[r][c] == 'S' ) {
				start_r = r;
				start_c = c;
			}
			if ( MAT[r][c] == 'E' ) {
				end_r = r;
				end_c = c;
			}
		}
	}

	int ans = f(start_r, start_c);
	printf("%d\n", ans);
	if (ans != -1) {
		string s;
		while (end_r != start_r || end_c != start_c) {
			s.pb(to[end_r][end_c]);
			if (to[end_r][end_c] == 'U') {
				end_r = mv[end_r][end_c][1];
			}
			else if (to[end_r][end_c] == 'D') {
				end_r = mv[end_r][end_c][0];
			}
			else if (to[end_r][end_c] == 'L') {
				end_c = mv[end_r][end_c][3];
			}
			else if (to[end_r][end_c] == 'R') {
				end_c = mv[end_r][end_c][2];
			}
		}
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
	return 0;
}