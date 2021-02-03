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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
int N, K, D;
vii G[MAXN];
int VIS[MAXN];
queue<int> Q;
set<int> ANS;

int main() {
    riii(N, K, D);
    FOR(i, 0, K) {
        int tmp; ri(tmp); --tmp;
        if (VIS[tmp] == 0) Q.push(tmp);
        VIS[tmp] = i + 1;
    }
    FOR(i, 1, N) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb({b, i});
        G[b].pb({a, i});
    }
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (auto tmp : G[x]) {
            int y = tmp.F;
            if (VIS[y] == 0) {
                VIS[y] = VIS[x];
                Q.push(y);
            }
            else if (VIS[y] != VIS[x]) ANS.insert(tmp.S);
        }
    }
    printf("%d\n", SZ(ANS));
    for (auto x : ANS) printf("%d ", x);
    printf("\n");
    return 0;
}