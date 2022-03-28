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
const int MAXN = 2e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll N, K, T;
ll X[MAXN];
ll PX[MAXN];

int main() {
    rll(N, K), rl(T);
    FOR(i, 0, N) rl(X[i]);
    FOR(i, 0, N) PX[i] = X[i] + (i > 0 ? PX[i - 1] : 0);
    ll CST = X[N - 1] * N - PX[N - 1];
    bool FND = 0;
    int L, R;
    int r = 0;
    for (int l = 0; l + 1 < N; l++) {
        r = max(r, l);
        while (r + 1 < N && X[r + 1] - X[l] <= K) ++r;
        if (r != l) {
            ll cst = (l + 1) * X[l] - PX[l] + N * X[N - 1] - (PX[N - 1] - PX[l] + (l + 1) * X[r]) + (l + 1) * T ;
            if (cst < CST) {
                CST = cst;
                FND = 1;
                L = l + 1;
                R = r + 1;
            }
        }
    }
    if (FND) printf("%d %d %lld\n", L, R, CST);
    else printf("-1\n");

    return 0;
}