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
#include <assert.h>
#include <array>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int query(int t, int i, int j, int x) {
    printf("? %d %d %d %d\n", t, i + 1, j + 1, x);
    fflush(stdout);
    int y; ri(y);
    return y;
}

void solve() {
    int n; ri(n);

    vi per(n), used(n+10);

    for (int i = 0; i < n / 2; ++i) {
        int mx = query(1, 2 * i, 2 * i + 1, n - 1);
        if (mx == n - 1 && query(1, 2 * i + 1, 2 * i, n - 1) == n) mx = n;

        if (query(2, 2 * i, 2 * i + 1, mx - 1) == mx) {
            per[2 * i] = mx;
            per[2 * i + 1] = query(2, 2 * i + 1, 2 * i, 1);
        }
        else {
            per[2 * i + 1] = mx;
            per[2 * i] = query(2, 2 * i, 2 * i + 1, 1);
        }
        used[per[2 * i]] = used[per[2 * i + 1]] = 1;
    }
    if (n & 1) {
        int free = 1;
        FOR(i, 1, n + 1) if (!used[i]) free = i;
        per[n - 1] = free;
    }
    printf("! ");
    FOR(i, 0, n) printf("%d ", per[i]);
    printf("\n");
    fflush(stdout);
}

int main() {
    srand(0);
    int t; ri(t);
    while (t--) solve();
    return 0;
}