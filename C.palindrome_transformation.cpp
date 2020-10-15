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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM

int main() {
    int n, p; rii(n, p); p--;
    string s; cin >> s;

    if (p >= (n + 1) / 2) {
        reverse(s.begin(), s.end());
        p = n - p - 1;
    }
    int ans = 0;
    int mn = p;
    int mx = p;
    FOR(i, 0, n / 2) {
        ans += min(abs(s[i] - s[n - 1 - i]), 26 - abs(s[i] - s[n - 1 - i]));

        if (s[i] != s[n - 1 - i]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    ans += min(2 * abs(p - mn) + abs(p - mx), 2 * abs(p - mx) + abs(p - mn));
    printf("%d\n", ans);

    return 0;
}