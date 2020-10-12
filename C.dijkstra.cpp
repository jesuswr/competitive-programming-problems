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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int v, e;
ll cst[MAXN];
vii G[MAXN];
int father[MAXN];

void dijkstra(int s) {
    priority_queue< pair<ll, int> > pq;

    FOR(i, 0, v) {
        cst[i] = LLINF;
    }
    cst[s] = 0;
    father[s] = -1;
    pq.push({0, s});

    while (!pq.empty()) {
        ll cost = -pq.top().F;
        int x = pq.top().S;
        pq.pop();
        if (cost != cst[x])
            continue;
        if (x == v - 1)
            return;

        for (auto edge : G[x]) {
            int y = edge.F;
            ll e_cst = edge.S;

            if (cst[y] > cst[x] + e_cst) {
                cst[y] = cst[x] + e_cst;
                pq.push({ -cst[y], y});
                father[y] = x;
            }
        }
    }

    printf("-1\n");
    exit(0);
}

int main() {
    rii(v, e);
    FOR(i, 0, e) {
        int a, b, c;
        riii(a, b, c);
        a--, b--;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }

    dijkstra(0);

    stack<int> outp;
    int curr = v - 1;
    while (curr != -1) {
        outp.push(curr);
        curr = father[curr];
    }
    while (!outp.empty()) {
        printf("%d ", outp.top()+1);
        outp.pop();
    }
    printf("\n");

    return 0;
}