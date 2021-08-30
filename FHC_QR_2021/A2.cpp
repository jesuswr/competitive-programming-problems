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
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
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
const int MAXN = 1e5; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int D[30][30];
vi G[30];

void bfs(int s) {
    queue<int> ord; ord.push(s);
    D[s][s] = 0;
    while (!ord.empty()) {
        int u = ord.front(); ord.pop();
        for (auto v : G[u]) {
            if (D[s][u] + 1 < D[s][v]) {
                D[s][v] = D[s][u] + 1;
                ord.push(v);
            }
        }
    }
}


void solve() {
    FOR(i, 0, 30) FOR(j, 0, 30) D[i][j] = INF;
    FOR(i, 0, 30) G[i].clear();
    string s; cin >> s;
    int k; ri(k);
    while (k--) {
        string x; cin >> x;
        G[x[0] - 'A'].pb(x[1] - 'A');
    }
    FOR(i, 0, 26) bfs(i);
    // FOR(i, 0, 26) FOR(j, 0, 26) printf("%c -> %c : %d\n", 'A' + i, 'A' + j, D[i][j]);

    int ans = INF;
    FOR(i, 0, 26) {
        int cst = 0;
        for (auto c : s) {
            if (D[c - 'A'][i] == INF) {
                cst = INF;
                break;
            }
            cst += D[c - 'A'][i];

        }
        // printf("%c : %d\n", i + 'A', cst);
        ans = min(ans, cst);
    }
    printf("%d\n", ans == INF ? -1 : ans );
}


int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}