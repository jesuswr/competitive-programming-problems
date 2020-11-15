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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int a[MAXN];
int cnt[110];
int b[MAXN];
int dp[2 * MAXN];

int main() {
    int n;
    ri(n);
    int mx = 0;
    int mx_i;
    int mx_cnt = 0;
    FOR(i, 0, n) {
        ri(a[i]);
        a[i]--;
        cnt[a[i]]++;

        if (cnt[a[i]] > mx) {
            mx = cnt[a[i]];
            mx_i = a[i];
            mx_cnt = 1;
        }
        else if (cnt[a[i]] == mx) {
            mx_cnt++;
        }
    }

    if (mx_cnt > 1) {
        printf("%d\n", n);
        return 0;
    }

    int ans = 0;
    FOR(i, 0, 100) {
        if (i == mx_i || cnt[i] == 0)
            continue;

        FOR(j, 0, 2 * MAXN) {
            dp[j] = INF;
        }

        FOR(j, 0, n) {
            if (a[j] == i)
                b[j] = 1;
            else if (a[j] == mx_i)
                b[j] = -1;
            else
                b[j] = 0;
        }

        int sm = 0;
        FOR(j, 0, n) {
            sm += b[j];
            if (sm == 0)
                ans = max(ans, j + 1);
            else
                ans = max(ans, j - dp[MAXN + sm]);

            dp[MAXN + sm] = min(dp[MAXN + sm], j);
        }
    }

    printf("%d\n", ans);

    return 0;
}