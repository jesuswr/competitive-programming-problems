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
const int MAXN = 100; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
bool E[MAXN][MAXN];
bool COL[MAXN];

struct dsu {
    int f[MAXN];
    dsu() {
        FOR(i, 0, N) f[i] = i;
    }
    dsu(const dsu &a) {
        FOR(i, 0, N) f[i] = a.f[i];
    }
    int find(int i) {
        if (f[i] == i) return i;
        return f[i] = find(f[i]);
    }
    void unio(int a, int b) {
        a = find(a), b = find(b);
        f[a] = b;
    }
};
int ans;
void go(int p, dsu d) {
    if (p == N) {
        FOR(i, 1, N) if (d.find(i) != d.find(0))
            return;
        ans++;
        return;
    }

    FOR(_v, 0, 2) {
        COL[p] = _v;
        dsu new_d(d);
        bool valid = 1;
        FOR(q, 0, p) if (COL[p] ^ E[q][p] ^ COL[q]) {
            if (new_d.find(p) == new_d.find(q))
                valid = false;
            else
                new_d.unio(p, q);
        }
        if (valid)
            go(p + 1, new_d);
    }
}

int main() {
    rii(N, M);
    if (N == 1) {
        printf("2\n");
        return 0;
    }
    FOR(_, 0, M) {
        int a, b; rii(a, b);
        --a, --b;
        E[a][b] = E[b][a] = 1;
    }
    dsu d;
    go(1, d);
    printf("%d\n", 2 * ans);
    return 0;
}