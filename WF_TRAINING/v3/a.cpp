#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
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
const int MAXN = 50+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int get_dir(char c) {
	if (c == 'N') return 0;
	if (c == 'E') return 1;
	if (c == 'S') return 2;
	return 3;
}

int R,C,E;
int X[2], Y[2]; char D[2];
int DIR[2];
int DIFF;
bool CAN[MAXN][MAXN][4];
ii MV[4] = { {1,0} , {0,1}, {-1,0}, {0,-1} };

ii try_move(int x, int y, int di) {
	if (CAN[x][y][di] && x > 0) {
		x += MV[di].F;
		y += MV[di].S;
	}
	return {x,y};
}

ii DST[MAXN][MAXN][MAXN][MAXN];
ii f(int x, int y, int x2, int y2) {

	queue< tuple< int, int, int, int> > q;
	q.push({x,y,x2,y2});
	DST[x][y][x2][y2] = {0,0};
	while(!q.empty()) {
		auto [x,y,x2,y2] = q.front(); q.pop();
		// printf("(%d, %d)  (%d, %d)  : %d\n", x,y,x2,y2,DST[x][y][x2][y2].F);
		if (x == 0 && x2 == 0) return DST[x][y][x2][y2];

		FOR(i,0,4) {
			auto [new_x, new_y] = try_move(x,y,i);
			auto [new_x2, new_y2] = try_move(x2,y2,(i+DIFF)&3);
			if (new_x > 0 && new_x == new_x2 && new_y == new_y2) continue;

			if (DST[new_x][new_y][new_x2][new_y2].F == INF) {
				DST[new_x][new_y][new_x2][new_y2] = DST[x][y][x2][y2];
				DST[new_x][new_y][new_x2][new_y2].F += 1;
				DST[new_x][new_y][new_x2][new_y2].S += (x > 0 && x == new_x && y == new_y) + (x2 > 0 && x2 == new_x2 && y2 == new_y2);
				q.push({new_x, new_y, new_x2, new_y2});
			}
			else if (DST[new_x][new_y][new_x2][new_y2].F == DST[x][y][x2][y2].F + 1) {
				DST[new_x][new_y][new_x2][new_y2].S = min(
					DST[new_x][new_y][new_x2][new_y2].S,
					DST[x][y][x2][y2].S + (x > 0 && x == new_x && y == new_y) + (x2 > 0 && x2 == new_x2 && y2 == new_y2)
				);
			}
		}
	}
	return {-1,-1};
}


int main(){
	FOR(i,0,MAXN) FOR(j,0,MAXN) FOR(k,0,MAXN) FOR(l,0,MAXN) DST[i][j][k][l] = {INF, 0};
	FOR(i,0,MAXN) FOR(j,0,MAXN) FOR(k,0,4) CAN[i][j][k] = 1;
	rii(C,R), ri(E);
	das=scanf("%d %d %c %d %d %c\n", Y, X, D, Y+1, X+1, D+1);
	DIR[0] = get_dir(D[0]);
	DIR[1] = get_dir(D[1]);
	DIFF = (DIR[1] - DIR[0] + 4) & 3;
	int _n; ri(_n);
	FOR(i,0,_n) {
		int a, b; rii(b,a);
		CAN[a][b][0] = 0;
		CAN[a+1][b][2] = 0;
	}
	ri(_n);
	FOR(i,0,_n) {
		int a,b; rii(b,a);
		CAN[a][b][1] = 0;
		CAN[a][b+1][3] = 0;
	}
	FOR(i,1,C+1) {
		CAN[R][i][0] = 0;
		if (i != E) CAN[1][i][2] = 0;
	} 
	FOR(i,1,R+1) {
		CAN[i][1][3] = 0;
		CAN[i][C][1] = 0;
	}
	
	auto ans = f(X[0], Y[0], X[1], Y[1]);
	cout << ans.F << " " << ans.S << endl;
	return 0;
}
