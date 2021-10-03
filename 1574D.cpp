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
int N, M;
int C[10][MAXN];
set<array<int, 10>> VIS, BAN;

pair<int, array<int, 10>> dfs(array<int, 10> u) {
    if (VIS.find(u) != VIS.end())
        return {0, u};
    VIS.insert(u);
    if (BAN.find(u) == BAN.end()) {
        int tot = 0;
        FOR(i, 0, N) tot += C[i][u[i]];
        return {tot, u};
    }
    else {
        int ret = 0;
        array<int, 10> ret2;
        FOR(i, 0, N)if (u[i] > 0) {
            u[i]--;
            auto [val, v] = dfs(u);
            u[i]++;
            if (val > ret) {
                ret = val;
                ret2 = v;
            }
        }
        return {ret, ret2};
    }
}

int main() {
    ri(N);
    array<int, 10> u = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    FOR(i, 0, N) {
        ri(u[i]);
        FOR(j, 0, u[i]) ri(C[i][j]);
        u[i]--;
    }
    ri(M);
    FOR(_, 0, M) {
        array<int, 10> b = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        FOR(i, 0, N) ri(b[i]), b[i]--;
        BAN.insert(b);
    }
    auto [val, comb] = dfs(u);
    FOR(i, 0, N) printf("%d ", comb[i] + 1);
    printf("\n");
    return 0;
}