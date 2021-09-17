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
const int MAXN = 1e6 + 69; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
string S;
int TRIE[MAXN][26], T_SZ = 1;
bool LEAF[MAXN];

int DP[5069];

void insert(const string &s) {
    int u = 0;
    for (auto &c : s) {
        int nxt = c - 'a';
        if (TRIE[u][nxt] == 0)
            TRIE[u][nxt] = ++T_SZ;
        u = TRIE[u][nxt];
    }
    LEAF[u] = true;
}
int search(int p) {
    int ans = 0;
    int u = 0;
    FOR(i, p, SZ(S)) {
        int nxt = S[i] - 'a';
        if (TRIE[u][nxt] == 0)
            break;
        u = TRIE[u][nxt];
        if (LEAF[u]) {
            ans += DP[i + 1];
            if (ans >= MOD)
                ans -= MOD;
        }
    }
    return ans;
}

int main() {
    cin >> S;
    int k; ri(k);
    while (k--) {
        string t; cin >> t;
        insert(t);
    }
    DP[SZ(S)] = 1;
    for (int i = SZ(S) - 1; i >= 0; --i) {
        DP[i] += search(i);
        if (DP[i] >= MOD)
            DP[i] -= MOD;
    }
    printf("%d\n", DP[0]);
    return 0;
}