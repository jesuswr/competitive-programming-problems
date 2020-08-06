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
const int maxN = 1000; // CAMBIAR ESTE

// GJNM
int m[maxN][maxN][2];
int dp[maxN][maxN][2];
bool vis[maxN][maxN][2];
char moves[maxN][maxN][2];
int n;

int f(int r, int c, int aux) {
	if ( r < 0 || c < 0 )
		return INF;
	if ( r <= 0 && c <= 0 )
		return m[r][c][aux];
	if ( vis[r][c][aux] )
		return dp[r][c][aux];
	vis[r][c][aux] = true;

	if ( f(r - 1, c, aux) < f(r, c - 1, aux) ) {
		moves[r][c][aux] = 'D';
		return dp[r][c][aux] = f(r - 1, c, aux) + m[r][c][aux];
	}
	else {
		moves[r][c][aux] = 'R';
		return dp[r][c][aux] = f(r, c - 1, aux) + m[r][c][aux];
	}
}

int main() {
	ri(n);
	int aux;
	bool hasZero = false;
	int zr, zc;
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			ri(aux);
			if ( aux == 0 ) {
				aux = 10;
				hasZero = true;
				zr = i;
				zc = j;
			}
			while ( aux % 2 == 0 ) {
				m[i][j][0]++;
				aux >>= 1;
			}
			while ( aux % 5 == 0 ) {
				m[i][j][1]++;
				aux /= 5;
			}
			//printf("{%d,%d} ", m[i][j][0], m[i][j][1]);
		}
		//printf("\n");
	}
	int path[2];
	path[0] = f(n - 1, n - 1, 0); path[1] = f(n - 1, n - 1, 1);
	int choice = (path[0] < path[1] ? 0 : 1);

	if ( path[choice] > 1 && hasZero ) {
		printf("1\n");
		int r = 0, c = 0;
		while ( c != zc ) {
			printf("%c", 'R');
			c++;
		}
		while ( r != n - 1 ) {
			printf("%c", 'D');
			r++;
		}
		while ( c != n - 1 ) {
			printf("%c", 'R');
			c++;
		}
	}
	else {
		printf("%d\n", path[choice]);
		int r = n - 1, c = n - 1;
		stack<char> prnt;
		while ( r != 0 || c != 0 ) {
			prnt.push(moves[r][c][choice]);
			if ( moves[r][c][choice] == 'D' )
				r--;
			else
				c--;
		}
		while(!prnt.empty()){
			printf("%c", prnt.top());
			prnt.pop();
		}
	}
	printf("\n");

	return 0;
}