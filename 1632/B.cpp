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
int f(int x) {
    int cnt = 0;
    while (x > 1) {
        cnt++;
        x >>= 1;
    }
    return cnt;
}

void solve() {
    int n; ri(n);
    vi a;
    vector<bool> used(n);
    int bg_bit = f(n - 1);
    FOR(i, 0, n) if ((i >> bg_bit) & 1) {
        a.pb(i);
        used[i] = 1;
    }
    int msk = (1 << (bg_bit)) - 1;
    int aux = ((n - 1) & msk);
    a.pb(aux);
    used[aux] = 1;
    FOR(i, 0, n) if (!used[i]) {
        a.pb(i);
        used[i] = 1;
    }
    FOR(i, 0, n) printf("%d ", a[i]);
    printf("\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}