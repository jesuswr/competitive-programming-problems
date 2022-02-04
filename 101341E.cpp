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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
ll T[MAXN];
ll B[MAXN];
ll L[MAXN], R[MAXN];

int main() {
    rii(N, M);
    FOR(i, 1, N + 1) rl(T[i]);
    T[0] = -1e10;
    T[N + 1] = 1e10;
    N += 2;
    FOR(i, 0, M) rl(B[i]);
    FOR(i, 0, N) L[i] = R[i] = T[i];

    int ti = 0, bi = 0;
    while (bi < M) {
        while (T[ti + 1] <= B[bi]) ++ti;
        // T[ti] <= B[bi] <= T[ti+1]
        ll len = T[ti + 1] - T[ti];
        ll dst = B[bi] - T[ti];
        if (2 * dst <= len)
            R[ti] = max(R[ti], B[bi]);
        else
            L[ti + 1] = min(L[ti + 1], B[bi]);
        ++bi;
    }

    ll ans = 0;
    FOR(i, 0, N - 1) {
        ans += min(2 * (R[i] - T[i]) + 2 * (T[i + 1] - L[i + 1]), T[i + 1] - T[i]);
    }
    printf("%lld\n", ans);

    return 0;
}