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
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1000+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M;
char A[MAXN][MAXN];

int UP[MAXN][MAXN], DOWN[MAXN][MAXN];
void pre() {
	FOR(j,0,M) {
		UP[0][j] = -1;
		DOWN[N-1][j] = N;
	}
	FOR(i,1,N) FOR(j,0,M) {
		if (A[i-1][j] != '.') UP[i][j] = i-1;
		else UP[i][j] = UP[i-1][j];
	}
	for(int i = N-2; i >= 0; --i) FOR(j,0,M) {
		if (A[i+1][j] != '.') DOWN[i][j] = i+1;
		else DOWN[i][j] = DOWN[i+1][j];
	}
}

ii find(char a) {
	FOR(i,0,N) FOR(j,0,N) if (A[i][j] == a) return {i,j};
	return {-1,-1};
}

tuple<int,int,int,int> fillAs() {
	int mx_sz = 0;
	int r1, r2, c1, c2;

	auto [r,c] = find('A');
	int upLft = -1, downLft = N;
	for(int lft = c; lft >= 0 && (A[r][lft] == '.' || A[r][lft] == 'A'); --lft) {
		upLft = max(upLft, UP[r][lft]);
		downLft = min(downLft, DOWN[r][lft]);

		int upRgt = -1, downRgt = N;
		for(int rgt = c; rgt < M && (A[r][rgt] == '.' || A[r][rgt] == 'A'); ++rgt) {
			upRgt = max(upRgt, UP[r][rgt]);
			downRgt = min(downRgt, DOWN[r][rgt]);
			
			int up = max(upRgt, upLft), down = min(downRgt, downLft);
			int sz = (down - up - 1) * (rgt - lft + 1);
			if (sz > mx_sz) {
				mx_sz = sz;
				r1 = up + 1;
				r2 = down - 1;
				c1 = lft;
				c2 = rgt;
			}
		}
	}

	FOR(i,r1,r2+1) FOR(j,c1, c2+1) if (A[i][j] == '.') A[i][j] ='a';

	return {r1, c1, r2, c2};
}

int main(){
	rii(N,M);
	FOR(i,0,N) das=scanf("%s\n", A[i]);
	pre();

	auto [r1, c1, r2, c2] = fillAs();
	printf("%d %d %d %d\n", r1, c1, r2, c2);
	FOR(i,0,N) printf("%s\n", A[i]);

	return 0;
}
