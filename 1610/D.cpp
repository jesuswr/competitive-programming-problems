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
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int A[MAXN];
int CNT[32];
int P2[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    P2[0] = 1;
    FOR(i, 1, N + 1) {
        P2[i] = (P2[i - 1] + P2[i - 1]);
        if (P2[i] >= MOD)
            P2[i] -= MOD;
    }
    FOR(i, 0, N) {
        FOR(b, 0, 31) if ((A[i] >> b) & 1) {
            ++CNT[b];
            break;
        }
    }

    int rem = N - CNT[0];
    int ans = (1ll * (P2[CNT[0]] - 1) * P2[rem] ) % MOD;

    for (int l = 1; l < 31; ++l) {
        rem -= CNT[l];
        if (CNT[l] > 1)
            ans = (ans + 1ll * (P2[CNT[l] - 1] - 1) * P2[rem] ) % MOD;
    }


    printf("%d\n", ans);
    return 0;
}