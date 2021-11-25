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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
void solve() {
    ll x0, n; rll(x0, n);
    if (x0 & 1) {
        if (n % 4 == 0) printf("%lld\n", x0);
        else if (n % 4 == 1) printf("%lld\n", x0 + n);
        else if (n % 4 == 2) printf("%lld\n", x0 - 1);
        else printf("%lld\n", x0 - n - 1);
    }
    else {
        if (n % 4 == 0) printf("%lld\n", x0);
        else if (n % 4 == 1) printf("%lld\n", x0 - n);
        else if (n % 4 == 2) printf("%lld\n", x0 + 1);
        else printf("%lld\n", x0 + n + 1);
    }
    // printf("%lld\n", x0);
    // FOR(i, 1, n + 1) {
    //     if (x0 & 1) x0 += i;
    //     else x0 -= i;
    //     printf("%lld (%d)\n", x0, i);
    // }
}

int main() {
    int t; ri(t);
    while (t--)
        solve();

    return 0;
}