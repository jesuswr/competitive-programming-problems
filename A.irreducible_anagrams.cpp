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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int pre[MAXN][30];

int main() {
	string s;
	cin >> s;
	FOR(i, 0, s.size()) {
		pre[i][s[i] - 'a']++;
	}
	FOR(i, 1, s.size()) {
		FOR(j, 0, 30) {
			pre[i][j] += pre[i - 1][j];
		}
	}
	int q;
	ri(q);
	while (q--) {
		int l, r;
		rii(l, r);
		if (l == r) {
			printf("Yes\n");
			continue;
		}
		if (s[l - 1] != s[r - 1]) {
			printf("Yes\n");
			continue;
		}
		int cnt = 0;
		FOR(i, 0, 30) {
			if (pre[r - 1][i] - (l > 1 ? pre[l - 2][i] : 0) > 0)
				cnt++;
		}
		if ( cnt > 2 )
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}