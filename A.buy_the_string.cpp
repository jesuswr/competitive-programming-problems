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
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
char s[1010];


void solve() {
    int n, c0, c1, h;
    rii(n, c0), rii(c1, h);
    scanf("%s", s);
    int cnt0 = 0;
    int cnt1 = 0;
    FOR(i, 0, n) {
        if (s[i] == '1')
            cnt1++;
        else
            cnt0++;
    }

    ll ans = LLINF;
    FOR(i, 0, n + 1) {
        ll new_cst = 0;
        new_cst += h * abs(i - cnt0);
        new_cst += c0 * i + c1 * (n - i);
        ans = min(ans, new_cst);
    }
    printf("%lld\n", ans);
}


int main() {
    int t = 1;
    ri(t);
    while (t--)
        solve();

    return 0;
}