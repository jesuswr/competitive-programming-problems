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
const int maxN = 1e6 + 1; // CAMBIAR ESTE

// GJNM
string m[maxN];
string m2[maxN];
vector< vector< vi > > help;
int dp[maxN][20];
bool vis[maxN][20];
int r, c;

int f(int pos, int put) {
	if ( vis[pos][put] )
		return dp[pos][put];
	vis[pos][put] = true;
	if ( pos == c - 1 ) {
		int cst = 0;
		FOR(j, 0, r) {
			cst += ( (int)(m[j][pos] - '0') != help[put][j][1]);
		}
		return dp[pos][put] = cst;
	}

	dp[pos][put] = INF;
	FOR(i, 0, help.size()) {
		bool valid = true;
		FOR(j, 0, r) {
			if ( help[put][j][1] != help[i][j][0] )
				valid = false;
		}
		if ( !valid )
			continue;

		int cst = 0;
		FOR(j, 0, r) {
			cst += ( (int)(m[j][pos] - '0') != help[i][j][0]);
		}
		cst += f(pos + 1, i);
		dp[pos][put] = min(cst, dp[pos][put]);
	}
	return dp[pos][put];

}

int main() {
	rii(r, c);
	if ( r >= 4 && c >= 4 ) {
		printf("-1\n");
		return 0;
	}
	if ( r == 1 || c == 1 ) {
		printf("0\n");
		return 0;
	}

	FOR(i, 0, r) {
		cin >> m[i];
	}
	if ( r > c ) {
		FOR(i, 0, c) {
			FOR(j, 0, r) {
				m2[i].pb(m[j][i]);
			}
		}
		FOR(i, 0, c) {
			m[c - i - 1] = m2[i];
		}
		swap(r, c);
	}

	if ( r == 2 ) {
		FOR(zz, 0, 2) FOR(zo, 0, 2) FOR(oz, 0, 2) FOR(oo, 0, 2) {
			vector<vi> aux = {{zz, zo}, {oz, oo}};
			if ( (zz + zo + oz + oo) & 1 )
				help.pb(aux);
		}
	}
	else if ( r == 3 ) {
		FOR(zz, 0, 2) FOR(zo, 0, 2) FOR(oz, 0, 2) FOR(oo, 0, 2) FOR(tz, 0, 2) FOR(to, 0, 2) {
			vector<vi> aux = {{zz, zo}, {oz, oo}, {tz, to}};
			if ( ((zz + zo + oz + oo) & 1) && ((tz + to + oz + oo) & 1) ) {
				help.pb(aux);
			}
		}
	}

	int mn = INF;
	FOR(i, 0, help.size()) {
		int cst = 0;
		FOR(j, 0, r) {
			cst += ( (int)(m[j][0] - '0') != help[i][j][0]);
		}
		cst += f(1, i);
		mn = min(cst, mn);
	}
	printf("%d\n", mn);

	return 0;
}