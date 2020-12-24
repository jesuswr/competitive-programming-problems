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
const int MAXN = 1000; // CAMBIAR ESTE

// GJNM
int N;
vi G[MAXN];
int DEG[MAXN];

int query(int a, int b) {
    printf("? %d %d\n", a + 1, b + 1); fflush(stdout);
    int r; ri(r); r--;
    return r;
}

void ans(int a) {
    printf("! %d\n", a + 1); fflush(stdout);
    exit(0);
}

int main() {
    ri(N);
    FOR(i, 1, N) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
        DEG[a]++; DEG[b]++;
    }
    queue<int> leafs;
    FOR(i, 0, N) {
        if (DEG[i] <= 1) {
            leafs.push(i);
            DEG[i] = INF;
        }
    }

    while (leafs.size() >= 2) {
        int a = leafs.front(); leafs.pop();
        int b = leafs.front(); leafs.pop();
        int c = query(a, b);
        if (c == a || c == b)
            ans(c);
        for (auto f : G[a]) {
            DEG[f]--;
            if (DEG[f] <= 1) {
                leafs.push(f);
                DEG[f] = INF;
            }
        }
        for (auto f : G[b]) {
            DEG[f]--;
            if (DEG[f] <= 1) {
                leafs.push(f);
                DEG[f] = INF;
            }
        }
    }

    int c = leafs.front();
    ans(c);
    return 0;
}