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
int n;
ll cst[10010];

int main() {
    ri(n);
    int m = (n * (n - 1)) >> 1;
    FOR(i, 0, m) {
        rl(cst[i]);
    }
    sort(cst, cst + m);

    ll mn = 0;
    FOR(i, 0, n - 1) {
        mn += cst[i];
    }

    ll mx = 0;
    int curr = 0;
    FOR(i, 1, n) {
        mx += cst[curr++];

        curr += (i - 1);
    }
    printf("%lld %lld\n", mn, mx);

    return 0;
}