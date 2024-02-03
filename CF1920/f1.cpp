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
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M, C;
string A[MAXN];
vi DST[MAXN];
vector<bool> VIS[MAXN];

void preBfs() {
	FOR(i,0,N) DST[i].resize(M,INF);
	queue<ii> q;
	FOR(i,0,N) FOR(j,0,M) if (A[i][j] == 'v') {
		q.push({i,j});
		DST[i][j] = 0;
	}
	while(!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		for(int dx : {1,0,-1}) for(int dy : {1,0,-1}) if (abs(dx) != abs(dy)) {
			int nx = x + dx, ny = y + dy;
			if (nx < N && ny < M && min(nx, ny) >= 0 && DST[nx][ny] == INF) {
				q.push({nx, ny});
				DST[nx][ny] = DST[x][y] + 1;
			}
		}
	}

	// FOR(i,0,N) {
	// 	FOR(j,0,M) cout << (DST[i][j] == INF ? -1 : DST[i][j]) << '\t';
	// 	cout << endl;
	// }
}

vii bfs(int val, int x, int y) {
	FOR(i,0,N) VIS[i].resize(M,0);
	FOR(i,0,N) FOR(j,0,M) VIS[i][j] = 0;

	VIS[x][y] = 1;
	queue<ii> q;
	q.push({x,y});

	vii ret;
	while(!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		ret.pb({x,y});
		for(int dx : {1,0,-1}) for(int dy : {1,0,-1}) if (abs(dx) != abs(dy)) {
			int nx = x + dx, ny = y + dy;
			if (nx < N && ny < M && min(nx, ny) >= 0 && !VIS[nx][ny] && DST[nx][ny] >= val && A[nx][ny] != '#') {
				q.push({nx, ny});
				VIS[nx][ny] = 1;
			}
		}
	}
	return ret;
}

bool bfs2(vii blocked) {
	FOR(i,0,N) VIS[i].resize(M);
	FOR(i,0,N) FOR(j,0,M) VIS[i][j] = 0;
	for(auto [x,y] : blocked) VIS[x][y] = 1;

	queue<ii> q;
	FOR(i,0,N) FOR(j,0,M) if (A[i][j] == '#') {
		q.push({i,j});
		VIS[i][j] = 1;
	}
	while(!q.empty()) {
		auto [x,y] = q.front(); q.pop();
		if (min(x, y) == 0 || x == N-1 || y == M-1) return false;
		for(int dx : {1,0,-1}) for(int dy : {1,0,-1}) {
			int nx = x + dx, ny = y + dy;
			if (nx < N && ny < M && min(nx, ny) >= 0 && VIS[nx][ny] == 0) {
				q.push({nx, ny});
				VIS[nx][ny] = 1;
			}
		}
	}
	return true;
}

bool f(int val, int x, int y) {
	vii blockedCells = bfs(val, x, y);
	// cout << x << " " << y << endl;
	// for(auto [x,y] : blockedCells) printf("(%d, %d)  ", x, y);
	return bfs2(blockedCells);
}

int go(int x, int y) {
	int lo = 0, hi = DST[x][y];
	while(lo < hi) {
		int mi = lo + (hi - lo + 1) / 2;
		if (f(mi, x, y))
			lo = mi;
		else
			hi = mi - 1;
	}
	return lo;
}

int main(){
	rii(N,M), ri(C);
	FOR(i,0,N) cin >> A[i];
	preBfs();

	while(C--) {
		int x,y; rii(x,y); --x, --y;
		printf("%d\n", go(x,y));
	}

	return 0;
}
