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
const int MOD = 1e9 + 7;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int aux = 1e9 + 1;
int N, A[1 << 24], K, B[2];
int DP[1 << 24], SM[1 << 24];

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[1 << i]);
    ri(K);
    FOR(i, 0, 2) B[i] = -1;
    FOR(i, 0, K) ri(B[i]);

    for (int msk = 1; msk < (1 << N); ++msk) {
        int on_b = msk & ~(msk - 1);
        SM[msk] = min(SM[msk ^ on_b] + A[on_b], aux);
    }

    DP[(1 << N) - 1] =  SM[(1 << N) - 1] != B[0] && SM[(1 << N) - 1] != B[1];
    for (int msk = (1 << N) - 2; msk >= 0; --msk) {
        if (SM[msk] == B[0] || SM[msk] == B[1])
            continue;
        FOR(b, 0, N) if (~msk & (1 << b)) {
            DP[msk] += DP[msk | (1 << b)];
            if (DP[msk] >= MOD)
                DP[msk] -= MOD;
        }
    }
    printf("%d\n", DP[0]);
    return 0;
}