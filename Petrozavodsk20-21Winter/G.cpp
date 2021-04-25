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
const ll MOD = 998244353; // CAMBIAR ESTE

// GJNM

int main() {
    int n;
    ri(n);
    if (n & 1) {
        printf("0\n");
        return 0;
    }

    ll ans = 1;
    for (int i = 1; i <= n - 1; i += 2) ans = (ans * i) % MOD;
    for (int i = 1; i <= n / 2 - 1; i++) ans = (ans * 4) % MOD;
    for (int i = 1; i <= n / 2 - 2; i++) ans = (ans * n / 2) % MOD;
    printf("%lld\n", ans);
    return 0;
}