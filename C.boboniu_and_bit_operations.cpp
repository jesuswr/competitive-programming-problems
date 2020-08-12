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
const int maxN = 2010; // CAMBIAR ESTE

// GJNM
int n, m;
int a[maxN], b[maxN];

bool valid(int exp) {
	FOR(i, 0, n) {
		bool found = false;
		FOR(j, 0, m) {
			if ( ((a[i] & b[j]) & exp) == (a[i] & b[j]) ) {
				found = true;
			}
		}
		if ( !found )
			return false;
	}
	return true;
}

int main() {
	rii(n, m);
	FOR(i, 0, n) {
		ri(a[i]);
	}
	FOR(i, 0, m) {
		ri(b[i]);
	}

	FOR(i, 0, 1 << 9) {
		if ( valid(i) ) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}