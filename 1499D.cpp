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

using namespace std;

typedef long long ll;
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
const int MAXN = 2e7 + 10; // CAMBIAR ESTE

// GJNM
int MIND[MAXN], NUMD[MAXN];
void pre() {
    FOR(i, 2, MAXN) {
        if (MIND[i] != 0) continue;
        for (int j = i; j < MAXN; j += i) if (MIND[j] == 0)
                MIND[j] = i;
    }
    FOR(i, 2, MAXN) {
        int j = i / MIND[i];
        NUMD[i] = NUMD[j] + (MIND[i] != MIND[j]);
    }
}

int main() {
    pre();
    int t; ri(t);
    while (t--) {
        int c, d, x; riii(c, d, x);
        int ans = 0;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i != 0) continue;
            int k1 = x / i + d;
            if (k1 % c == 0) ans += (1 << NUMD[k1 / c]);
            if (i * i == x) continue;
            int k2 = i + d;
            if (k2 % c == 0) ans += (1 << NUMD[k2 / c]);
        }
        printf("%d\n", ans);
    }

    return 0;
}