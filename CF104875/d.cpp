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
const int MAXN = 710;
const long double PI = 2 * acos(0);
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int R,C;
char M[MAXN][MAXN];
vector< tuple< int, int, int, long double, bool > > Moves[8]; // <delta r, delta c, new pos (base 8), cost, needCircle
long double DST[MAXN][MAXN][8];
const long double lineCost = 10 / 2;
const long double circleCost = 10 * PI / 4;

void fillMoves() {
	FOR(i,0,8) {
		int j = (i + 1) % 8;
		Moves[i].pb({0,0,j,lineCost,false});
		Moves[j].pb({0,0,i,lineCost,false});
	}

	for(int i = 1; i < 8; i += 2) {
		int j = (i + 2) % 8;
		Moves[i].pb({0,0,j,circleCost,true});
		Moves[j].pb({0,0,i,circleCost,true});
	}

	Moves[1].pb({-1,0,5,0,false});
	Moves[5].pb({1,0,1,0,false});

	Moves[3].pb({0,1,7,0,false});
	Moves[7].pb({0,-11,3,0,false});

	Moves[2].pb({0,1,0,0,false});
	Moves[3].pb({0,1,7,0,false});
	Moves[4].pb({0,1,6,0,false});
	Moves[4].pb({1,0,2,0,false});
	Moves[5].pb({1,0,1,0,false});
	Moves[6].pb({1,0,0,0,false});
}


int main(){
	fillMoves();
	das = scanf("%d %d\n", &R, &C);
	FOR(i,0,R) das = scanf("%s\n", M[i]);
	FOR(i,0,R+1) FOR(j,0,C+1) FOR(k,0,8) DST[i][j][k] = INFLL;
	DST[0][0][0] = 0;
	priority_queue< tuple <long double, int, int, int> > pq;
	pq.push({0,0,0,0});

	while(!pq.empty()) {
		auto [dst, r, c, k] = pq.top();
		if (r == R && c == C && k == 4) break;
		pq.pop();
		dst = -dst;
		// cout << r << " " << c << " " << k << " : " << dst << endl;

		for(auto [dr, dc, nk, cst, needCircle] : Moves[k]) {
			int nr = r + dr, nc = c + dc;
			long double ndst = dst + cst;
			if (nr >= R || nc >= C || min(nc, nr) < 0) continue;
			if (needCircle && M[nr][nc] != 'O') continue;
			if (DST[nr][nc][nk] <= ndst) continue;
			DST[nr][nc][nk] = ndst;
			pq.push({-ndst, nr, nc, nk});
		}
	}
	printf("%.10Lf\n", DST[R-1][C-1][4]);
	return 0;
}
