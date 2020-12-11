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
const int MAXN = 5010; // CAMBIAR ESTE

// GJNM
int p, n, m;
int cnt[MAXN], pre[MAXN];
int tmp;

int main() {
    rii(n, p);
    FOR(i, 0, n) {
        ri(tmp); cnt[tmp]++;
        m = max(m, tmp);
    }
    FOR(i, 1, m + 1) {
        pre[i] = cnt[i] + pre[i - 1];
    }
    vi ans;
    FOR(k, max(m - n + 1, 1), m) {
        ll ansa = 1;
        ll v = pre[k - 1];
        FOR(i, k, k + n) {
            v = v + cnt[i];
            ansa *= v;
            v--;
            v %= p;
            ansa %= p;
        }
        if (ansa % p != 0)
            ans.pb(k);
    }
    printf("%d\n", SZ(ans));
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");

    return 0;
}
