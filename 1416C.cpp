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
const int MAXN = 3e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;

int T = 1;
int TRIE[MAXN * 27][2];
vi INDS[MAXN * 27];
ll SM[30][2];

void ins(int a, int i) {
    int u = 0;
    for (int b = 29; b >= 0; --b) {
        int nxt = (a >> b) & 1;
        if (TRIE[u][nxt] == 0)
            TRIE[u][nxt] = ++T;
        u = TRIE[u][nxt];
        INDS[u].pb(i);
    }
}

void solve(int b, int u) {
    if (TRIE[u][0] == 0 && TRIE[u][1] == 0)
        return;
    if (TRIE[u][0] == 0)
        return solve(b - 1, TRIE[u][1]);
    if (TRIE[u][1] == 0)
        return solve(b - 1, TRIE[u][0]);

    int l = TRIE[u][0], r = TRIE[u][1];
    sort(ALL(INDS[l])); sort(ALL(INDS[r]));

    FOR(k, 0, 2) {
        for (auto i : INDS[r]) 
            SM[b][k] += INDS[l].end() - lb(ALL(INDS[l]), i);
        swap(l, r);
    }
    solve(b - 1, l);
    solve(b - 1, r);
}

int main() {
    ri(N);
    FOR(i, 0, N) {
        int a; ri(a);
        ins(a, i);
    }
    solve(29, 0);
    ll ans = 0, ind = 0;
    FOR(i, 0, 30) {
        // printf("%d : %lld %lld\n", i, SM[i][0], SM[i][1]);
        if (SM[i][0] <=  SM[i][1])
            ans += SM[i][0];
        else {
            ans += SM[i][1];
            ind |= (1 << i);
        }
    }
    printf("%lld %lld\n", ans, ind);
    return 0;
}