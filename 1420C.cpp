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
const int MAXN = 4e5; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, Q;
ll A[MAXN];
ll ans = 0;

void insert(int i, int mode) {
    if (i == 0 || i == N + 1) return;
    if (A[i] > A[i - 1] && A[i] > A[i + 1]) ans += mode * A[i];
    if (A[i] < A[i - 1] && A[i] < A[i + 1]) ans -= mode * A[i];
}

void solve() {
    rii(N, Q);
    ans = 0;
    A[0] = A[N + 1] = -1;
    FOR(i, 0, N) rl(A[i + 1]);
    FOR(i, 1, N + 1) insert(i, 1);
    printf("%lld\n", ans);
    while (Q--) {
        int l, r; rii(l, r);
        set<int> inds;
        FOR(i, -1, 2) {
            inds.insert(l + i);
            inds.insert(r + i);
        }

        for (auto i : inds) insert(i, -1);
        swap(A[l], A[r]);
        for (auto i : inds) insert(i, 1);

        printf("%lld\n", ans);
    }
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}