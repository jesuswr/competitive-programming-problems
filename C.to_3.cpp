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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
vi digits;

int main() {
    ll n;
    rl(n);
    while (n > 0) {
        digits.pb(n % 10);
        n = n / 10;
    }

    n = digits.size();
    int ans = 100;
    FOR(i, 1, 1 << n) {
        int sm = 0;
        int cnt = 0;
        FOR(b, 0, n) {
            if (i & (1 << b))
                sm += digits[b];
            else
                cnt++;
        }

        if (sm % 3 == 0)
            ans = min(ans, cnt);
    }

    if (ans == 100)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}