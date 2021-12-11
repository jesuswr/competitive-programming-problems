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

vi go(int n, int mx, int mn) {
    vi ret(n);
    int l = 2, r = n;
    ret[0] = 1;
    if (mx == mn) {
        int aux = 2;
        FOR(i, 0, mn) {
            ret[aux] = l++;
            aux += 2;
        }
        aux = 1;
        FOR(i, 0, mx) {
            ret[aux] = r--;
            aux += 2;
        }
        while (aux < n) {
            ret[aux] = l++;
            aux++;
        }
    }
    else {
        int aux = 2;
        FOR(i, 0, mn) {
            ret[aux] = l++;
            aux += 2;
        }
        aux = 1;
        FOR(i, 0, mx) {
            ret[aux] = r--;
            aux += 2;
        }
        --aux;
        while (aux < n) {
            ret[aux] = r--;
            aux++;
        }
    }
    return ret;
}

void solve() {
    int n, a, b; riii(n, a, b);
    if (a + b > n - 2 || abs(a - b) > 1) {
        printf("-1\n");
        return;
    }
    vi ans;
    if (a >= b)
        ans = go(n, a, b);
    else {
        ans = go(n, b, a);
        for (auto &x : ans) x = n - x + 1;
    }

    for (auto x : ans) printf("%d ", x);
    printf("\n");
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}