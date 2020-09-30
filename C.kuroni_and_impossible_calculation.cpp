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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
ll n, m;
ll a[MAXN];
ll cnt[1010];

ll binpow(ll b, ll e) {
    if (e == 0)
        return 1;
    ll ret = binpow(b, e / 2);
    ret = (ret * ret) % m;
    if (e & 1)
        ret = (ret * b) % m;
    return ret;
}

int main() {
    rll(n, m);
    FOR(i, 0, n) {
        rl(a[i]);
    }
    sort(a, a + n);
    ll prod = 1;
    FOR(i, 0, n) {
        ll aux = a[i] % m;
        FOR(j, 0, m) {
            if (cnt[j] == 0)
                continue;
            prod = (prod * binpow((aux - j + m) % m, cnt[j])) % m;
        }
        cnt[aux]++;
        if (prod == 0)
            break;
    }

    printf("%lld\n", prod);


    return 0;
}