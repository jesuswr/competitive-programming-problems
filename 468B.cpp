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
int N, AB[2];
int P[MAXN];
map<int, int> IND_OF;
int BELONGS[MAXN];

int REP[MAXN], RANK[MAXN], CAN[2][MAXN];
int find(int x) {
    if (REP[x] == -1) return x;
    return REP[x] = find(REP[x]);
}
void unio(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (RANK[x] > RANK[y]) {
        REP[y] = x;
        FOR(i, 0, 2) CAN[i][x] &= CAN[i][y];
    }
    else {
        REP[x] = y;
        FOR(i, 0, 2) CAN[i][y] &= CAN[i][x];
        if (RANK[x] == RANK[y]) RANK[y]++;
    }
}

int main() {
    riii(N, AB[0], AB[1]);
    FOR(i, 0, N) {
        int p; ri(p);
        P[i] = p;
        IND_OF[p] = i;
        REP[i] = -1;
        RANK[i] = 0;
        CAN[0][i] = CAN[1][i] = true;
    }

    FOR(i, 0, N) {
        if (IND_OF.find(AB[0] - P[i]) != IND_OF.end()) {
            unio(i, IND_OF[AB[0] - P[i]]);
        }
        else {
            CAN[0][find(i)] = false;
        }

        if (IND_OF.find(AB[1] - P[i]) != IND_OF.end()) {
            unio(i, IND_OF[AB[1] - P[i]]);
        }
        else {
            CAN[1][find(i)] = false;
        }
    }

    FOR(i, 0, N) {
        if (i != find(i)) continue;
        if (CAN[0][i]) continue;
        else if (CAN[1][i]) {
            BELONGS[i] = 1;
        }
        else {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    FOR(i, 0, N) printf("%d ", BELONGS[find(i)]);
    printf("\n");

    return 0;
}