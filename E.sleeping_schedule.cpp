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
const int MAXN = 2010; // CAMBIAR ESTE

// GJNM
int n, h, l, r;
int a[MAXN];
int dp[MAXN][MAXN];
bool vis[MAXN][MAXN];

bool valid(int x) {
    return x >= l && x <= r;
}

int f(int p, int hour) {
    if (p == n)
        return 0;
    if (vis[p][hour])
        return dp[p][hour];
    vis[p][hour] = true;

    int op1 = f(p + 1, (hour + a[p]) % h) + (valid((hour + a[p]) % h));
    int op2 = f(p + 1, (hour + a[p] - 1) % h) + (valid((hour + a[p] - 1) % h));
    return dp[p][hour] = max(op1, op2);
}

int main() {
    rii(n, h), rii(l, r);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    printf("%d\n", f(0, 0));

    return 0;
}