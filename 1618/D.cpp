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
int get_mn(vi a) {
    map<int, int> cnt;
    for (auto x : a) cnt[x]++;
    int mx = 0;
    for (auto x : a) mx = max(mx, cnt[x]);
    return max(0, mx - SZ(a) / 2);
}

void solve() {
    int n, k; rii(n, k);
    vi a(n);
    FOR(i, 0, n) ri(a[i]);
    sort(ALL(a)); reverse(ALL(a));
    vi aux(2 * k);
    FOR(i, 0, 2 * k) aux[i] = a[i];
    int ans = get_mn(aux);
    FOR(i, 2 * k, n) ans += a[i];
    printf("%d\n", ans);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}