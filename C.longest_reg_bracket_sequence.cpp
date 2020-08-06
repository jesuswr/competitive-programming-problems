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
const int maxN = 1e6 + 10; // CAMBIAR ESTE

// GJNM
char s[maxN];
int dp[maxN];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	int mx = 0;
	int mx_cnt = 0;
	ROF(i, n - 1, -1) {
		if ( s[i] == ')' )
			continue;
		if ( s[i + 1] == ')' ) { // () something
			dp[i] = 2 + dp[i + 2];
		}
		else {
			if ( s[dp[i + 1] + i + 1] == ')' ) {// ( something ) something2
				dp[i] = 2 + dp[i + 1] + dp[dp[i + 1] + i + 2];
			}
		}
		if ( dp[i] > mx ) {
			mx = dp[i];
			mx_cnt = 1;
		}
		else if ( dp[i] == mx ) {
			mx_cnt++;
		}
		//printf("%d %d\n", i, dp[i]);
	}

	if ( mx == 0 ) {
		printf("0 1\n");
	}
	else {
		printf("%d %d\n", mx, mx_cnt);
	}

	return 0;
}