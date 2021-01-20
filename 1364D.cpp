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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N, M, K;
vi G[MAXN];

int MN_L = INF, START, END;
int VIS[MAXN], H[MAXN], FAT[MAXN];

void dfs(int x) {
    VIS[x] = 1;
    for (auto y : G[x]) {
        if (y == FAT[x]) continue;
        if (VIS[y] == 0) {
            FAT[y] = x;
            H[y] = H[x] + 1;
            dfs(y);
        }
        else if (VIS[y] == 1) {
            if (H[x] - H[y] + 1 < MN_L) {
                MN_L = H[x] - H[y] + 1;
                START = x;
                END = y;
            }
        }
    }
    VIS[x] = 2;
}

int COL[MAXN];
int CNT[2];
void dfs2(int x) {
    CNT[COL[x]]++;
    for (auto y : G[x]) {
        if (y == FAT[x]) continue;
        COL[y] = 1 ^ COL[x];
        dfs2(y);
    }
}


int main() {
    riii(N, M, K);
    FOR(_, 0, M) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0);
    if (MN_L == INF) {
        dfs2(0);
        int mx = (CNT[0] > CNT[1] ? 0 : 1);
        int need = (K + 1) / 2;
        printf("1\n");
        int i = 0;
        while (need > 0) {
            if (COL[i] == mx) printf("%d ", i + 1), --need;
            i++;
        }
    }
    else if (MN_L <= K) {
        printf("2\n");
        printf("%d\n", MN_L);
        while (1) {
            printf("%d ", START + 1);
            if (START == END) break;
            START = FAT[START];
        }
    }
    else {
        printf("1\n");
        int need = (K + 1) / 2;
        while (need > 0) {
            printf("%d ", START + 1);
            START = FAT[FAT[START]];
            need--;
        }
    }
    printf("\n");
    return 0;
}