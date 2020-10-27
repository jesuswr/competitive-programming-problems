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

const int INF = 1e9 + 20;
const ll LLINF = 1e18;
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int n;
int a[6];
int b[MAXN];
int cnt[MAXN];
pii all[6 * MAXN];

int main() {
    FOR(i, 0, 6) {
        ri(a[i]);
    }
    ri(n);
    if (n == 1) {
        printf("%d\n", 0);
        return 0;
    }

    FOR(i, 0, n) {
        ri(b[i]);
        FOR(j, 0, 6) {
            all[6 * i + j] = {b[i] - a[j], i};
        }
    }
    sort(all, all + 6 * n);

    int best_ans = INF;
    int l = 0, r = 0;
    cnt[all[0].S] = 1;
    int help = 1;

    while (r < 6 * n) {
        if (help == n) {
            best_ans = min(best_ans, all[r].F - all[l].F);
            cnt[all[l].S]--;
            if (cnt[all[l].S] == 0)
                help--;
            l++;
        }
        else {
            r++;
            if (cnt[all[r].S] == 0)
                help++;
            cnt[all[r].S]++;
        }
    }

    printf("%d\n", best_ans);
    return 0;
}