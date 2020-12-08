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
int n;
int a[MAXN], b[MAXN];

void simplify() {
    int m = 0;
    FOR(i, 0, n) {
        if (m == 0 || b[m - 1] != a[i])
            b[m++] = a[i];
    }
    n = m;
    FOR(i, 0, n) {
        a[i] = b[i];
    }
}

int main() {
    ri(n);
    int mx = 0;
    FOR(i, 0, n) {
        ri(a[i]);
        mx = max(a[i], mx);
    }
    sort(a, a + n);
    simplify();
    a[n] = 1e8;
    n++;
    int ans = 0;
    FOR(i, 0, n - 1) {
        int aux = 2 * a[i];
        while (true) {
            auto it = lb(a + i, a + n, aux);

            if (*it >= aux)
                it--;
            if (it > a + i)
                ans = max(ans, *it % a[i]);

            if (aux > mx)
                break;
            aux += a[i];
        }
    }

    printf("%d\n", ans);
    return 0;
}