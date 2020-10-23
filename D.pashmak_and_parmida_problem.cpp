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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e6 + 10; // CAMBIAR ESTE

// GJNM
int n;
int a[MAXN];

void compress() {
    set<int> vals;
    map<int, int> new_vals;
    FOR(i, 0, n) {
        vals.insert(a[i]);
    }

    if (vals.size() == n) {
        printf("0\n");
        exit(0);
    }
    
    int aux = 0;
    for (auto x : vals) {
        new_vals[x] = aux++;
    }
    FOR(i, 0, n) {
        a[i] = new_vals[a[i]];
    }
}

int cnt_left[MAXN], cnt_right[MAXN];

ll BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
    p++;    // esto es porque el bit esta indexado desde 1
    for (; p < MAXN; p += p & -p) // se puede cambiar maxN por n+1 si hace falta mas velocidad
        BIT[p] += val;
}
ll sumBIT(int p) {
    p++;
    ll ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}

int main() {
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    compress();
    FOR(i, 0, n) {
        cnt_left[a[i]]++;
    }

    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += sumBIT(cnt_left[a[i]] - 1);

        cnt_left[a[i]]--;
        cnt_right[a[i]]++;

        updBIT(cnt_right[a[i]], 1);
    }

    printf("%lld\n", ans);
    return 0;
}