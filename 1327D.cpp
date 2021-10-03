#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
#include <random>
#include <chrono>

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
const int MAXN = 2e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int A[MAXN], C[MAXN];
bool V[MAXN];

int go(const vi &cyc, int l) {
    for (int i = 0; i < l; ++i) {
        int j = i;
        bool good = 1;
        FOR(_, 0, SZ(cyc) / l) {
            if (cyc[j] != cyc[i])
                good = 0;
            j = (j + l) % SZ(cyc);
        }
        if (good) return l;
    }
    return N;
}

void solve() {
    ri(N);
    FOR(i, 0, N) {
        ri(A[i]);
        --A[i];
        V[i] = 0;
    }
    FOR(i, 0, N) ri(C[i]);
    int ans = N;
    FOR(i, 0, N) if (!V[i]) {
        vi cyc = {C[i]};
        V[i] = 1;
        for (int j = A[i]; j != i; j = A[j]) {
            cyc.pb(C[j]);
            V[j] = 1;
        }
        for (int j = 1; j * j <= SZ(cyc); ++j) {
            if (SZ(cyc) % j == 0) {
                ans = min(ans, go(cyc, j));
                ans = min(ans, go(cyc, SZ(cyc) / j));
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}