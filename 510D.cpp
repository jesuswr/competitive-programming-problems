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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
int l[MAXN], c[MAXN];

map< pii , int > dp;

int f(int p, int gcd) {
    if (p == n) {
        if (gcd == 1) return 0;
        else return INF;
    }
    if (dp.find({p, gcd}) != dp.end()) return dp[ {p, gcd}];

    return dp[ {p, gcd}] = min(f(p + 1, gcd), f(p + 1, __gcd(gcd, l[p])) + c[p]);
}

int main() {
    ri(n);
    FOR(i, 0, n) ri(l[i]);
    FOR(i, 0, n) ri(c[i]);
    int ans = f(0, 0);
    if (ans >= INF)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}