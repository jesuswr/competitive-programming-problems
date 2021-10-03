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
vi divs, primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int SUM[1 << 10];
__int128 poww(__int128 b, int e) {
    __int128 ret = 1;

    FOR(_, 0, e) ret = min(ret * b, (__int128)1e18 + 69);
    return ret;
}
__int128 DP[1 << 10][10];
__int128 f(int msk, int p) {
    if (DP[msk][p] != -1)
        return DP[msk][p];
    if (p == SZ(primes))
        return DP[msk][p] = (msk + 1 == (1 << SZ(divs)) ? 1 : LLINF + 69);
    DP[msk][p] = LLINF + 69;
    FOR(new_msk, 0, 1 << SZ(divs)) {
        if (msk & new_msk)
            continue;
        DP[msk][p] = min(DP[msk][p], poww(primes[p], SUM[new_msk] - 1) * f(new_msk | msk, p + 1));
    }
    return DP[msk][p];
}


int main() {
    memset(DP, -1, sizeof(DP));
    int n; ri(n);
    FOR(d, 2, n + 1) {
        while (n % d == 0) {
            n /= d;
            divs.pb(d);
        }
    }
    FOR(i, 0, 1 << SZ(divs)) {
        SUM[i] = 1;
        FOR(b, 0, SZ(divs)) if ((i >> b) & 1)
            SUM[i] = min(SUM[i] * divs[b], 100);
    }
    printf("%lld\n", (ll)f(0, 0));
    return 0;
}