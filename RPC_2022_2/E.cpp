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
const int MAXN = 6e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;

int FREQ[MAXN];
vi MULTS[MAXN], DVS[MAXN];
set<int> PENDING[MAXN];
void pre_divs() {
    FOR(d, 2, MAXN) {
        for (int m = d; m < MAXN; m += d) {
            MULTS[d].pb(m);
            DVS[m].pb(d);
        }
    }
}

int main() {
    pre_divs();
    rii(N, M);
    FOR(i, 0, N) {
        int a; ri(a);
        FREQ[a]++;
        if (FREQ[a] == 1) {
            for (auto d : DVS[a]) PENDING[d].insert(a);
        }
    }
    ll ans = 0;
    FOR(_, 0, M) {
        int d; ri(d);
        vi del;
        for (int m : PENDING[d]) {
            ans += FREQ[m];
            if (FREQ[m + 1] == 0) {
                for (auto div : DVS[m + 1]) PENDING[div].insert(m + 1);
            }
            FREQ[m + 1] += FREQ[m];
            FREQ[m] = 0;
        }
        PENDING[d].clear();
        for (auto x : del) {
            for (auto div : DVS[x]) PENDING[div].erase(x);
        }
    }
    printf("%lld\n", ans);
    return 0;
}