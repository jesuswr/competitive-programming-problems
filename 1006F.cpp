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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
ll K;
ll A[21][21];
map< tuple<int, int, ll> , int > xr_cnt1, xr_cnt2;

void dfs1(int sz) {
    FOR(msk, 0, (1 << sz)) {
        int x = 0, y = 0;
        ll xr = A[x][y];
        FOR(b, 0, sz) {
            if ((msk >> b) & 1)
                ++x;
            else
                ++y;
            if (min(x, y) >= 0 && x < N && y < M)
                xr ^= A[x][y];
            else
                xr = -1;
        }
        if (xr >= 0)
            xr_cnt1[ {x, y, xr}]++;
    }
}
void dfs2(int sz) {
    FOR(msk, 0, (1 << sz)) {
        int x = N - 1, y = M - 1;
        ll xr = A[x][y];
        // printf("%d %d\n", x, y);
        FOR(b, 0, sz) {
            if ((msk >> b) & 1) {
                // printf("1");
                --x;
            }
            else {
                // printf("0");
                --y;
            }
            if (min(x, y) >= 0 && x < N && y < M)
                xr ^= A[x][y];
            else{
                // printf("F\n");
                xr = -1;
            }
        }
        // printf("\n");
        // printf("\t\t\t%d %d %lld\n", x, y, xr);
        if (xr >= 0) {
            // printf("\t\t%lld\n", xr);
            xr_cnt2[ {x, y, xr}]++;
        }
    }
}


int main() {
    rii(N, M); rl(K);
    FOR(i, 0, N) FOR(j, 0, M) rl(A[i][j]);
    dfs1((N + M - 2) / 2);
    dfs2((N + M - 1) / 2);

    ll ans = 0;
    for (auto [t, cnt] : xr_cnt1) {
        auto [x, y, xr] = t;
        // printf("%d %d %lld %d\n", x, y, xr, cnt);
        ans += (ll)cnt * xr_cnt2[ {x, y, K ^ xr ^ A[x][y]}];
        // printf("\t%lld\n", ans);
    }
    // for (auto [t, cnt] : xr_cnt2) {
    //     auto [x, y, xr] = t;
    //     printf("\t%d %d %lld %d\n", x, y, xr, cnt);
    // }
    printf("%lld\n", ans);
    return 0;
}