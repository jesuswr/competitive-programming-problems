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
const int maxN = 110; // CAMBIAR ESTE

// GJNM
char s[maxN];
int n, k, m;
int dp[maxN][maxN][30];
bool vis[maxN][maxN][30];
int C[30][30];
bool V[30][30];

int f(int ind, int left, int last) {
	if ( left < 0 )
		return -INF;
	if ( ind == n )
		return 0;

	if ( vis[ind][left][last] )
		return dp[ind][left][last];
	vis[ind][left][last] = true;
	int &ret = dp[ind][left][last] = -INF;

	FOR(i, 0, 26) {
		ret = max(ret, C[last][i] + f(ind + 1, left - (i != (s[ind] - 'a')) , i) );
	}
	return ret;
}

int main() {
	scanf("%s %d", s, &k);
	n = strlen(s);
	ri(m);
	FOR(i, 0, m) {
		char a, b;
		int c;
		scanf("%*c");
		scanf("%c %c %d", &a, &b, &c);
		C[a - 'a'][b - 'a'] = c;
	}

	printf("%d\n", f(0, k, 28));
	return 0;
}