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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int n, m;
int a[MAXN][10];
int b[1 << 8];

pii valid(int mi) {
    FOR(i, 0, 1 << m) b[i] = 0;
    FOR(i, 0, n) {
        int aux = 0;
        FOR(j, 0, m) {
            if (a[i][j] >= mi)
                aux |= (1 << j);
        }
        b[aux] = i + 1;
    }

    FOR(i, 0, 1 << m) {
        FOR(j, 0, 1 << m) {
            if (b[i] != 0 && b[j] != 0 && ((i | j) == (1 << m) - 1))
                return {b[i], b[j]};
        }
    }
    return { -1, -1};
}

int main() {
    rii(n, m);
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            ri(a[i][j]);
        }
    }
    pii ans = {1, 1};
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mi = lo + (hi - lo + 1) / 2;
        pii aux;
        aux = valid(mi);
        if (aux.F != -1) {
            ans = aux;
            lo = mi;
        }
        else
            hi = mi - 1;
    }
    printf("%d %d\n", ans.F, ans.S);
    return 0;
}