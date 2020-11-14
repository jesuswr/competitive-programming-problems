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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int a[MAXN];

int main() {
    int n;
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }

    if (~n & 1) {
        int xr = 0;
        FOR(i, 0, n) {
            xr = xr ^ a[i];
        }
        if (xr != 0) {
            printf("NO\n");
            return 0;
        }
        n--;
    }
    printf("YES\n");

    vector<piii> ans;
    int h = 2;
    while (h < n) {
        ans.pb({1, {h, h + 1}});
        h += 2;
    }
    printf("%zu\n", 2 * ans.size());
    for (auto p : ans) {
        printf("%d %d %d\n", p.F, p.S.F, p.S.S);
    }
    for (auto p : ans) {
        printf("%d %d %d\n", p.F, p.S.F, p.S.S);
    }

    return 0;
}