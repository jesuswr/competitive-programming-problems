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
const int MAXN = 1e5 + 1; // CAMBIAR ESTE

// GJNM
int a[MAXN];
map<int, int> cnt;

int main() {
    int n;
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
        cnt[a[i]]++;
    }

    if (cnt[0] > 1) {
        printf("cslnb\n");
        return 0;
    }
    int more_than_1 = 0;
    for (auto p : cnt) {
        if (p.S > 2) {
            printf("cslnb\n");
            return 0;
        }
        if (p.S > 1) {
            more_than_1++;
            if (cnt[p.F - 1] > 0) {
                printf("cslnb\n");
                return 0;
            }
        }
    }
    if (more_than_1 > 1) {
        printf("cslnb\n");
        return 0;
    }

    sort(a, a + n);
    ll moves = 0;
    int curr = 0;
    FOR(i, 0, n) {
        moves += (a[i] - curr++);
    }
    if (moves & 1) {
        printf("sjfnb\n" );
    }
    else {
        printf("cslnb\n");
    }

    return 0;
}