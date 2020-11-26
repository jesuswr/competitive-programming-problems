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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int n, m;
int tmp;
set<int> vis;


int main() {
    rii(n, m);
    queue<pii> bfs;
    FOR(i, 0, n) {
        ri(tmp);
        vis.insert(tmp);
        bfs.push({0, tmp});
    }

    ll ans = 0;
    vi ans_v;
    while (SZ(ans_v) != m) {
        int y = bfs.front().S;
        int dy = bfs.front().F;
        bfs.pop();
        if (dy > 0) {
            ans += dy;
            ans_v.pb(y);
        }

        if (vis.find(y + 1) == vis.end()) {
            vis.insert(y + 1);
            bfs.push({dy + 1, y + 1});
        }
        if (vis.find(y - 1) == vis.end()) {
            vis.insert(y - 1);
            bfs.push({dy + 1, y - 1});
        }
    }

    printf("%lld\n", ans);
    for (auto y : ans_v)
        printf("%d ", y);
    printf("\n");
    return 0;
}