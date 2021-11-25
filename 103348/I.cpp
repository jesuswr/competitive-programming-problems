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
const int MAXN = 20; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
int A[20];
pii DP[1 << 20];
pii f(int msk) {
    if (DP[msk].F != -1)
        return DP[msk];
    if (msk == 0)
        return DP[msk] = {1, 0};

    DP[msk] = {21, 0};
    FOR(i, 0, N) if ((msk >> i) & 1) {
        pii r = f(msk ^ (1 << i));
        if (r.S + A[i] <= K)
            r.S += A[i];
        else {
            r.F++;
            r.S = A[i];
        }
        DP[msk] = min(DP[msk], r);
    }
    return DP[msk];
}

int main() {
    FOR(i, 0, 1 << 20) DP[i].F = -1;
    rii(N, K);
    FOR(i, 0, N) ri(A[i]);
    printf("%d\n", f((1 << N) - 1).F);
    return 0;
}