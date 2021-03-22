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
const int MAXN = 1 << 21; // CAMBIAR ESTE

// GJNM
int N, K;
vi G[MAXN];
int D[MAXN];

int main() {
    rii(N, K);
    FOR(i, 0, 1 << K) {
        D[i] = INF;
        FOR(b, 0, K) {
            int aux = i | (1 << b);
            if (aux != i) {
                G[i].pb(aux);
                G[aux].pb(i);
            }
        }
    }

    queue<int> bfs;
    FOR(i, 0, N) {
        string aux; cin >> aux;
        int msk = 0;
        for (auto c : aux) {
            msk <<= 1;
            if (c == '1') msk |= 1;
        }
        bfs.push(msk);
        D[msk] = 0;
    }

    while (!bfs.empty()) {
        int x = bfs.front();
        bfs.pop();
        for (auto y : G[x]) {
            if (D[y] > D[x] + 1) {
                D[y] = D[x] + 1;
                bfs.push(y);
            }
        }
    }
    int mx = -1;
    int mxi = 0;
    FOR(i, 0, 1 << K) {
        mx = max(mx, D[i]);
        if (mx == D[i]) mxi = i;
    }
    for (int i = K - 1; i >= 0; --i) printf("%d", (mxi >> i) & 1);
    printf("\n");
    return 0;
}