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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
struct QUERY {
    int l, r;
    int ind;
    bool operator<(QUERY &other) {
        if (l / 300 != other.l / 300)
            return l < other.l;
        return r < other.r;
    }
};
int n, m, k;
int a[MAXN];
QUERY q[MAXN];
ll ans[MAXN];
ll cnt[1 << 20];
ll pre[MAXN];
ll curr_ans;

int main() {
    riii(n, m, k);
    FOR(i, 0, n) ri(a[i + 1]);
    FOR(i, 1, n + 1) pre[i] = a[i] ^ pre[i - 1];
    FOR(i, 0, m) {
        rii(q[i].l, q[i].r);
        q[i].l--;
        q[i].ind = i;
    }
    sort(q, q + m);
    cnt[0] = 1;
    int l = 0, r = 0;
    FOR(i, 0, m) {
        while (l > q[i].l) {
            l--;
            curr_ans += cnt[pre[l] ^ k];
            cnt[pre[l]]++;
        }
        while (r < q[i].r) {
            r++;
            curr_ans += cnt[pre[r] ^ k];
            cnt[pre[r]]++;
        }
        while (l < q[i].l) {
            cnt[pre[l]]--;
            curr_ans -= cnt[pre[l] ^ k];
            l++;
        }
        while (r > q[i].r) {
            cnt[pre[r]]--;
            curr_ans -= cnt[pre[r] ^ k];
            r--;
        }
        ans[q[i].ind] = curr_ans;
    }
    FOR(i, 0, m) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}