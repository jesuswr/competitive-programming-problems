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
const int MAXN = 5e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
int A[MAXN], B[MAXN];
bool CNST[MAXN];

int f(const vi &a, int l, int r) {
    vi lis;
    for (auto x : a) if (l <= x && x <= r) {
            auto it = ub(ALL(lis), x);
            if (it == lis.end())
                lis.pb(x);
            else
                *it = x;
        }
    return SZ(a) - SZ(lis);
}

int main() {
    rii(N, K);
    FOR(i, 0, N) ri(A[i + 1]);
    A[0] = -1e9 - 1e6;
    A[N + 1] = 1e9 + 1e6;
    FOR(i, 0, K) {
        ri(B[i + 1]);
    }
    B[0] = 0; B[K + 1] = N + 1;
    N += 2; K += 2;
    int ans = 0;
    FOR(i, 0, K - 1) {
        if (A[B[i + 1]] - A[B[i]] < B[i + 1] - B[i]) {
            printf("-1\n");
            return 0;
        }
        vi suba;
        // printf("%d %d\n", B[i], B[i + 1]);
        FOR(j, B[i] + 1, B[i + 1]) suba.pb(A[j] - j);
        // printf("alo\n");
        ans += f(suba, A[B[i]] - B[i], A[B[i + 1]] - B[i + 1]);
    }
    printf("%d\n", ans);
    return 0;
}