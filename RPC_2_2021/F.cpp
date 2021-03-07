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
const int MAXN = 2e4 + 10; // CAMBIAR ESTE

// GJNM
int N;
int K[MAXN];
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

int query(int cnt) {
    int l = 0, r = MAXN - 1;
    while (l < r) {
        int mi = l + (r - l) / 2;
        if (sumBIT(mi) >= cnt) r = mi;
        else l = mi + 1;
    }
    return r;
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(K[i]);
    FOR(i, 0, N) updBIT(i, 1);
    int curr = 0;
    int n = N;
    FOR(_, 1, N) {
        int curr_ind = query(curr + 1);
        int del = (curr + K[curr_ind] - 1) % n;
        int del_ind = query(del + 1);
        updBIT(del_ind, -1);
        --n;
        curr = del % n;
    }
    printf("%d\n", query(1) + 1);
    return 0;
}