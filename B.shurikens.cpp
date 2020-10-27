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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
pair<int, int> q[MAXN];

int main() {
    int n;
    ri(n);
    FOR(i, 0, 2 * n) {
        char c[5];
        scanf("%s", c);
        if (c[0] == '-') {
            int aux;
            ri(aux);
            q[i] = {1, aux};
        }
        else
            q[i] = {0, 0};
    }

    set<pii> active;
    FOR(i, 0, 2 * n) {
        if (q[i].F == 1) {
            active.insert({i, q[i].S});
        }
    }
    vi ans;
    ROF(i, 2 * n - 1, -1) {
        if (q[i].S == 0) {
            auto it = active.lb({i, 0});
            if (it == active.end()) {
                printf("NO\n");
                return 0;
            }
            ans.pb(it->second);
            active.erase(it);
        }
    }
    reverse(ans.begin(), ans.end());
    priority_queue<int> pq;
    int ansi = 0;
    FOR(i, 0, 2 * n) {
        if (q[i].F == 0) {
            pq.push(-ans[ansi]);
            ansi++;
        }
        else {
            if (pq.empty() || -pq.top() != q[i].S) {
                printf("NO\n");
                return 0;
            }
            pq.pop();
        }
    }
    printf("YES\n");
    for (auto x : ans) {
        printf("%d ", x);
    } printf("\n");

    return 0;
}