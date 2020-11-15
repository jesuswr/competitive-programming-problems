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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int a[12][12];

void solve() {
    int n, m;
    rii(n, m);
    int mn = 110;
    int sm = 0;
    int neg = 0;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            ri(a[i][j]);
            sm += abs(a[i][j]);
            mn = min(abs(a[i][j]), mn);
            if (a[i][j] < 0)
                neg++;
        }
    }
    if (neg & 1) {
        printf("%d\n", sm - 2 * mn);
    }
    else {
        printf("%d\n", sm);
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