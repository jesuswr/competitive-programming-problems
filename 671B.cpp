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
ll C[MAXN];

int main() {
    rii(N, K);
    FOR(i, 0, N) rl(C[i]);
    ll lo = 0, hi = 1e10;
    while (lo < hi) {
        ll mi = lo + (hi - lo + 1) / 2;
        ll need = 0;
        FOR(i, 0, N) need += max(0ll, mi - C[i]);
        if (need <= K)
            lo = mi;
        else
            hi = mi - 1;
    }
    ll rem = K;
    FOR(i, 0, N)if (C[i] < lo) {
        rem -= lo - C[i];
        C[i] = lo;
    }
    FOR(i, 0, N) if (C[i] == lo && rem > 0) {
        C[i]++;
        rem--;
    }

    lo = 0, hi = 1e10;
    while (lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        ll need = 0;
        FOR(i, 0, N) need += max(0ll, C[i] - mi);
        if (need <= K)
            hi = mi;
        else
            lo = mi + 1;
    }

    rem = K;
    FOR(i, 0, N) if (C[i] > lo) {
        rem -= C[i] - lo;
        C[i] = lo;
    }
    FOR(i, 0, N) if (C[i] == lo && rem > 0) {
        C[i]--;
        rem--;
    }
    ll high = 0, low = 1e9;
    FOR(i, 0, N) {
        high = max(high, C[i]);
        low = min(low, C[i]);
    }
    printf("%lld\n", max(0ll, high - low));
    return 0;
}