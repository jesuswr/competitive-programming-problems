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
const int MAXN = 3e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// sqrt decomp, cnt(x) >= sqrt(n) o cnt(x) < sqrt(n)
// cnt(x) >= sqrt(n): chequear todos porque solo hay sqrt(n) x's
// cnt(x) < sqrt(n): guardarlos
int N, M;
int A[MAXN];
const int SQ = 500;

void solve() {
    map<int, int> CNT;
    map<int, vi> G;

    rii(N, M);
    FOR(i, 0, N) {
        ri(A[i]);
        CNT[A[i]]++;
    }
    FOR(_, 0, M) {
        int a, b; rii(a, b);
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<set<int>> PQ(SQ);
    set<int> BG;

    ll ans = 0;
    for (auto &[x, cntx] : CNT) {
        for (auto &y : G[x]) {
            if (y < x) {
                if (CNT[y] >= SQ)
                    BG.erase(y);
                else if (CNT[y] > 0) {
                    PQ[CNT[y]].erase(y);
                }
            }
        }

        for (auto &y : BG)
            ans = max(ans, 1ll * (x + y) * (cntx + CNT[y]));
        FOR(i, 1, SQ) if (!PQ[i].empty()) {
            int y = *PQ[i].rbegin();
            ans = max(ans, 1ll * (x + y) * (cntx + i));
        }

        if (cntx >= SQ) BG.insert(x);
        else PQ[cntx].insert(x);


        for (auto &y : G[x]) {
            if (y < x) {
                if (CNT[y] >= SQ)
                    BG.insert(y);
                else if (CNT[y] > 0) {
                    PQ[CNT[y]].insert(y);
                }
            }
        }
    }

    printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}