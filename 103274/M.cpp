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
const int MAXN = 360; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int WH[MAXN];

struct DSU {
    vi F;
    DSU(int n) {
        F.resize(n);
        FOR(i, 0, n) F[i] = i;
    }
    int find(int x) {
        if (F[x] == x) return x;
        return F[x] = find(F[x]);
    }
    void merge(int x, int y) {
        F[y] = x;
    }
};

int go(int rot) {
    DSU dsu(N);
    FOR(a, 0, MAXN) {
        int b = (a + rot) % MAXN;
        if (WH[a] != -1 && WH[b] != -1)
            if (dsu.find(WH[a]) != dsu.find(WH[b]))
                dsu.merge(dsu.find(WH[a]), dsu.find(WH[b]));
    }
    vi cnt(N);
    FOR(i, 0, N) cnt[dsu.find(i)]++;
    int ans = 0;
    for (auto x : cnt) ans += x / 2;
    return ans;
}


int main() {
    FOR(i, 0, MAXN) WH[i] = -1;
    ri(N);
    FOR(i, 0, N) {
        int a; ri(a);
        WH[a] = i;
    }
    int mx = 0;
    FOR(i, 1, MAXN) mx = max(mx, go(i));
    printf("%d\n", mx);
    return 0;
}