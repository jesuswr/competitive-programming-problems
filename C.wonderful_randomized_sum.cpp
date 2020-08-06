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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int A[maxN];

int main() {
	int n;
	ri(n);
	int tot_sum = 0;
	FOR(i, 0, n) {
		ri(A[i]);
		tot_sum += A[i];
	}
	int mx_sum = 0;
	int mx_curr = 0;
	FOR(i, 0, n) {
		mx_curr += A[i];
		mx_sum = max(mx_sum, mx_curr);
		mx_curr = max(mx_curr, 0);
	}

	printf("%d\n", mx_sum - (tot_sum - mx_sum));


	return 0;
}