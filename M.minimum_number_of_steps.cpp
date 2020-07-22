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
const int maxN = 1e6 + 6; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
char S[maxN];


int main() {
	scanf("%s", S);
	int n = strlen(S);

	ll cnt = 1;

	ll ans = 0;
	FOR(i, 0, n) {
		if ( S[i] == 'a' ) {
			cnt = (cnt * 2LL) % MOD;
		}
		else{
			ans = (ans + cnt-1)%MOD;
		}
	}

	printf("%lld\n", ans);
	return 0;
}