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
int n;
int bfs[MAXN];

void solve() {
    ri(n);
    FOR(i, 0, n) {
        ri(bfs[i]);
    }
    queue<pii> aux;
    aux.push({1, 0});
    int ans = 0;
    FOR(i, 1, n) {
        int v = aux.front().F;
        int h = aux.front().S;
        aux.pop();
        ans = max(ans, h);
        aux.push({bfs[i], h + 1});
        int j = i + 1;
        ans = max(ans, h + 1);
        while (j < n && bfs[j] > bfs[j - 1]) {
            aux.push({bfs[j], h + 1});
            j++;
            ans = max(ans, h + 1);
        }
        i = j - 1;
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}