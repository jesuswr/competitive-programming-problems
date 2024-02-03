#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 5e8;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e4+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int R,C;
string A[55];
string P;

vii MVS = { {0,1}, {1,0}, {0,-1}, {-1,0} };
ii NXT[55][55][4];
int CST[55][55][MAXN];

bool valid(int r, int c) {
	return min(r,c) >= 0 && r < R && c < C;
}

void pre() {
	FOR(r,0,R) FOR(c,0,C) {
		FOR(i,0,4) {
			auto [dr, dc] = MVS[i];
			int nr = r, nc = c;
			while(valid(nr, nc) && A[r][c] == A[nr][nc]) {
				nr += dr;
				nc += dc;
			}
			NXT[r][c][i] = {nr, nc};
		}
		FOR(i,0,MAXN) CST[r][c][i] = INF;
	}
}



int main(){
	cin >> R >> C;
	FOR(i,0,R) cin >> A[i];
	cin >> P;
	P += '*';

	pre();

	queue<tuple<int,int,int>> q;
	q.push({0,0,0});
	CST[0][0][0] = 0;
	while(!q.empty()) {
		auto [r, c, pi] = q.front(); q.pop();

		if (pi == sz(P)) {
			cout << CST[r][c][pi] << endl;
			return 0;
		}

		if (A[r][c] == P[pi] && CST[r][c][pi+1] == INF) {
			CST[r][c][pi+1] = CST[r][c][pi] + 1;
			q.push({r,c,pi+1});
		}

		FOR(i,0,4) {
			auto [nr,nc] = NXT[r][c][i];
			if (valid(nr,nc) && CST[nr][nc][pi] == INF){
				CST[nr][nc][pi] = CST[r][c][pi] + 1;
				q.push({nr,nc,pi});
			}
 		}

	}



	return 0;
}
