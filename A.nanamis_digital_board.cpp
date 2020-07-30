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
const int maxN = 1009; // CAMBIAR ESTE

// GJNM
int M[4][maxN][maxN];
int dp[4][maxN][maxN];

void upd(int rot, int col, int R) {
	dp[rot][0][col] = M[rot][0][col];
	FOR(i, 1, R) {
		if ( dp[rot][i][col] = M[rot][i][col] != 0 ) {
			dp[rot][i][col] += ( M[rot][i - 1][col] != 0 ? dp[rot][i - 1][col] : 0);
		}
	}
}

int sum(int rot, int row, int col, int R, int C) {
	if ( col < 0 || col >= C )
		return 0;
	return dp[rot][row][col];
}


int f(int rot, int row, int col, int R, int C) {
	int ans = sum(rot, row, col, R, C);
	int min_h = ans;
	int left = col - 1, right = col + 1;
	int left_sum, right_sum;

	while ( left_sum = sum(rot, row, left, R, C), right_sum = sum(rot, row, right, R, C), left_sum + right_sum != 0 ) {
		if ( right_sum <= left_sum ) {
			min_h = min(min_h, left_sum);
			left--;
		}
		else {
			min_h = min(min_h, right_sum);
			right++;
		}
		if ( min_h == 0 )
			break;
		ans = max(ans, ( right - left - 1 ) * min_h );
	}
	return ans;
}


int main() {
	int r, c, q;
	riii(r, c, q);

	FOR(i, 0, r) {
		FOR(j, 0, c) {
			int aux;
			ri(aux);
			M[0][i][j] = M[1][j][r - 1 - i]
			             = M[2][r - 1 - i][c - 1 - j]
			               = M[3][c - 1 - j][i]
			                 = aux;
		}
	}
	FOR(i,0,c){
		upd(0,i,r), upd(2,i,r);
	}
	FOR(i,0,r){
		upd(1,i,c), upd(3,i,c);
	}
	FOR(p, 0, q) {
		int type, i, j;
		riii(type, i, j); i--, j--;
		if ( type == 1 ) {
			M[0][i][j] = M[1][j][r - 1 - i]
			             = M[2][r - 1 - i][c - 1 - j]
			               = M[3][c - 1 - j][i]
			                 = 1 ^ M[0][i][j];

			upd(0, j, r), upd(1, r - 1 - i, c),
			    upd(2, c - 1 - j, r), upd(3, i, c);
		}
		else {
			printf("%d\n", max( max( f(0, i, j, r, c) , f(1, j, r - 1 - i, c, r)  )   ,
			                    max( f(2, r - 1 - i, c - 1 - j, r, c)  ,  f(3, c - 1 - j, i, c, r) )  ) );
		}
	}
	return 0;
}