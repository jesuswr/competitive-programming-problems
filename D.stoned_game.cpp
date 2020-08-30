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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
void solve() {
	int n;
	ri(n);
	priority_queue<int> pq;
	FOR(i, 0, n) {
		int aux; ri(aux);
		pq.push(aux);
	}
	int turn = 0;
	int t_last = -1, hl_last = -1;
	while (true) {
		turn++;

		if ( (turn & 1) && t_last > 1 ) {
			pq.push(t_last - 1);
		}
		if ( ((~turn) & 1) && hl_last > 1) {
			pq.push(hl_last - 1);
		}

		if ( pq.empty() )
			break;

		if ( turn & 1 ) {
			t_last = pq.top(); pq.pop();
		}
		else {
			hl_last = pq.top(); pq.pop();
		}
	}
	if ( ~turn & 1 ) {
		printf("T\n");
	}
	else {
		printf("HL\n");
	}
}

int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}