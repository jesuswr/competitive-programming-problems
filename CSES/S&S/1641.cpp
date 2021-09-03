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
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

int main() {
    int n, x; rii(n, x);
    vector<pair<ll, int>> a(n);
    FOR(i, 0, n) rl(a[i].F), a[i].S = i + 1;
    sort(ALL(a));
    FOR(i, 0, n) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (a[i].F + a[l].F + a[r].F < x) {
                ++l;
                while (a[l].F == a[l - 1].F) ++l;
            }
            else if (a[i].F + a[l].F + a[r].F > x) {
                --r;
                while (a[r].F == a[r + 1].F) --r;
            }
            else {
                printf("%d %d %d\n", a[i].S, a[l].S, a[r].S);
                return 0;
            }
        }
        while (i + 1 < n && a[i].F == a[i + 1].F) ++i;
    }
    printf("IMPOSSIBLE\n");
    return 0;
}