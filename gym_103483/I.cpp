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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
const int MOD = 1000000829;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int L, N;
string A[MAXN];
vi H[MAXN];

void go(vi inds, int msk) {
    if (SZ(inds) <= 1)
        return;
    map<int, vi> new_inds;
    FOR(i, 0, 26) {
        if (msk & (1 << i))
            continue;
        bool valid = true;
        for (int j : inds) if (H[j][i] == 0)
                valid = 0;
        if (!valid)
            continue;

        for (int j : inds)
            new_inds[H[j][i]].pb(j);
        for (auto [_, ni] : new_inds)
            go(ni, msk | (1 << i));
        return;
    }
    printf("NO\n");
    exit(0);
}

int main() {
    rii(L, N);
    vi inds;
    FOR(i, 0, N) {
        inds.pb(i);
        cin >> A[i];
        H[i].resize(26, 0);
        int P = 31;
        int p = 1;
        FOR(j, 0, L) {
            FOR(k, 0, 26) {
                if (A[i][j] - 'a' == k)
                    H[i][k] = (H[i][k] + 1ll * p * (k + 1)) % MOD;
            }
            p = (1ll * p * P) % MOD;
        }
    }
    go(inds, 0);
    printf("YES\n");
    return 0;
}