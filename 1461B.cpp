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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int n, m;
int a[MAXN];
int b[MAXN]; // sorted a
bool suf[MAXN];

void solve() {
    rii(n, m);
    FOR(i, 0, n) {
        ri(a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    suf[n] = true;
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = b[i] == a[i];
        suf[i] &= suf[i + 1];
    }

    long double ans = 0;
    long double p = 1;
    FOR(_, 0, m) {
        int r; long double pi;
        dadsadasda = scanf("%d %Lf", &r, &pi); r--;
        if (suf[r + 1]) {
            ans += p * pi;
            p = p * (1 - pi);
        }
    }
    if (suf[0])
        ans = 1;
    printf("%Lf\n", ans);
}


int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}