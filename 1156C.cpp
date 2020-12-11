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
const int MAXN = 3e5 + 10; // CAMBIAR ESTE

// GJNM
int n, z;
int x[MAXN];

bool valid(int c) {
    FOR(i, 0, c) {
        if (x[n - c + i] - x[i] < z)
            return false;
    }
    return true;
}

int main() {
    rii(n, z);
    FOR(i, 0, n) {
        ri(x[i]);
    }
    sort(x, x + n);

    int lo = 0, hi = n / 2;
    while (lo < hi) {
        int mi = lo + (hi - lo + 1) / 2;
        if (valid(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    printf("%d\n", lo);
    return 0;
}