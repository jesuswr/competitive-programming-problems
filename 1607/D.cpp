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

// B->-1
// R->+1
void solve() {
    int n; ri(n);
    vi a(n);
    FOR(i, 0, n) ri(a[i]);
    string c;
    cin >> c;
    FOR(i, 0, n) {
        if (c[i] == 'B' && a[i] <= 0) {
            printf("NO\n");
            return;
        }
        if (c[i] == 'R' && a[i] > n) {
            printf("NO\n");
            return;
        }
    }
    vi sm_p(n + 2), sm_s(n + 2);
    FOR(i, 0, n) {
        if (c[i] == 'B') {
            sm_p[min(a[i], n)]++;
        }
        else {
            sm_s[max(a[i], 1)]++;
        }
    }
    FOR(i, 1, n + 1) sm_p[i] += sm_p[i - 1];
    for (int i = n; i >= 1; --i) sm_s[i] += sm_s[i + 1];

    FOR(i, 1, n + 1) {
        if (sm_p[i] > i) {
            printf("NO\n");
            return;
        }
        if (sm_s[i] > (n - i) + 1) {
            printf("NO\n");
            return;
        }
    }
    printf("yEs\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}