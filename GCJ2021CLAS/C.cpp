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

using namespace std;

typedef long long ll;
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
const int MAXN = 110; // CAMBIAR ESTE

// GJNM
int N, C;
int A[MAXN];

bool f(int l, int r, int c) {
    if (l == r) return c == 0;
    int keep = r - l - 1;
    int mx = min(r - l, c - keep);
    if (f(l + 1, r, c - mx)) {
        A[l] = l + 1;
        reverse(A + l, A + l + mx);
        return true;
    }
    return false;
}



void solve() {
    rii(N, C);
    if (f(0, N, C + 1) && C + 1 >= N) {
        FOR(i, 0, N) printf("%d ", A[i]);
    }
    else
        printf("IMPOSSIBLE");
    printf("\n");
}

int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}