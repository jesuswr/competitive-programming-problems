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
const int MAXN = 1e5 + 69; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
vi G[MAXN];
ll A[MAXN];

const int LOGN = 25;
int ANC[MAXN][LOGN];
ll GCD[MAXN][LOGN];
int H[MAXN];
ll ans = 0;
void pre(int u = 0, int f = 0) {
    ANC[u][0] = f;
    GCD[u][0] = __gcd(A[u], A[f]);
    for (int i = 1; i < LOGN; ++i) {
        ANC[u][i] = ANC[ ANC[u][i - 1] ][i - 1];
        GCD[u][i] = __gcd(GCD[u][i - 1], GCD[ ANC[u][i - 1] ][i - 1]);
    }
    for (auto v : G[u]) {
        if (v == f)
            continue;
        H[v] = H[u] + 1;
        pre(v, u);
    }

    ll gcd = A[u];
    int lst = u;
    while (6969) {
        int new_lst = u;
        for (int i = LOGN - 1; i >= 0; --i) 
            if (__gcd(gcd, GCD[new_lst][i]) == gcd) 
                new_lst = ANC[new_lst][i];
        ans = (ans + gcd * (H[lst] - H[new_lst] + 1)) % MOD;
        if (new_lst == 0)
            break;
        lst = ANC[new_lst][0];
        gcd = __gcd(gcd, A[lst]);
    }
}

int main() {
    ri(N);
    FOR(i, 0, N) rl(A[i]);
    FOR(_, 1, N) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    pre();
    printf("%lld\n", ans);
    return 0;
}