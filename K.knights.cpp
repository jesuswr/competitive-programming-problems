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
#include <bitset>

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
#define rlll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
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
int n, m, k;
bitset<1100> IN[1100];
ll X[maxN], Y[maxN];

int main() {
	riii(n, m, k);
	FOR(i,0,n){
		rll(X[i],Y[i]);
	}
	FOR(i,0,m){
		ll x,y,r;
		rlll(r,x,y);
		FOR(j,0,n){
			if ( (X[j] - x)*(X[j]-x) + (Y[j]-y)*(Y[j]-y) < r*r ){
				IN[j][i] = 1;
			}
		}
	}

	FOR(i, 0, k) {
		int a, b;
		rii(a, b);
		a--, b--;
		int ans = IN[a].count() + IN[b].count();
		ans = (IN[a] ^ IN[b]).count();
		printf("%d\n", ans);
	}
	return 0;
}