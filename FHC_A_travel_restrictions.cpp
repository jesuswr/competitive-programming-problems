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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
char IN[100], OUT[100];
char ANS[100][100];

void dfs_l(int col, int row) {
	ANS[row][col] = 'Y';
	if ( col == 0 )
		return;
	if ( OUT[col] == 'Y' && IN[col - 1] == 'Y' )
		dfs_l(col - 1, row);
}

void dfs_r(int col, int row){
	ANS[row][col] = 'Y';
	if ( col == n - 1 )
		return;
	if ( OUT[col] == 'Y' && IN[col + 1] == 'Y' )
		dfs_r(col + 1, row);
}

void solve() {
	ri(n);
	scanf("%s", IN);
	scanf("%s", OUT);
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			ANS[i][j] = 'N';
		}
	}

	FOR(i, 0, n) {
		dfs_l(i, i);
		dfs_r(i, i);
	}

	FOR(i, 0, n) {
		FOR(j, 0, n) {
			printf("%c", ANS[i][j]);
		}
		printf("\n");
	}

}

int main() {
	int t;
	ri(t);
	int tc = 1;
	while (t--) {
		printf("Case #%d: \n", tc++);
		solve();
	}
	return 0;
}