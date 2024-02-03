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
const int MAXRC = 2e3+10;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int R, C, N, Q;
vii A, AT;

ii transform(ii p) {
	return {1000 + p.F - p.S, p.F + p.S};
}

int DP[MAXRC][MAXRC];

void go(int d) {
	ms(DP, 0);
	for(auto [x,y] : AT) {
		int xmn = max(0, x-d), xmx = min(MAXRC-4, x+d), ymn = max(0, y - d), ymx = min(MAXRC-4,y+d); 
		DP[xmn][ymn] += 1;
		DP[xmn][ymx+1] -= 1;
		DP[xmx+1][ymn] -= 1;
		DP[xmx+1][ymx+1] += 1;
	}

	FOR(i,0,MAXRC) FOR(j,1,MAXRC) DP[i][j] += DP[i][j-1];
	FOR(j,0,MAXRC) FOR(i,1,MAXRC) DP[i][j] += DP[i-1][j];

	// FOR(i,0,10) {
	// 	FOR(j,0,10) cout << DP[i][j] << '\t';
	// 	cout << endl;
	// }


	int bst = -1;
	ii ans;
	FOR(j,1,C+1) FOR(i,1,R+1) {
		auto [x,y] = transform({i,j});
		// cout << i << " " << j << "     " << DP[x][y] <<  "     " << x-5 << " " << y << endl;
		if (DP[x][y] > bst) {
			bst = DP[x][y];
			ans = {i,j};
		}
	} 
	printf("%d (%d,%d)\n", bst, ans.F, ans.S);
}

int main(){
	int t = 1;
	while(1) {
	
		rii(R,C), rii(N,Q);
		if (max({R,C,N,Q}) == 0) {
			break;
		}
		FOR(i,0,N) {
			int a,b; rii(a,b);
			A.pb({a,b});
			AT.pb( transform(A.back()) );
			
		}

		printf("Case %d:\n", t++);
		while(Q--) {
			int x; ri(x);
			go(x);
		}

		A.clear();
		AT.clear();

	}


	return 0;
}
