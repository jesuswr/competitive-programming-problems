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
int N, K;
int TRIE[MAXN][26], SZ;
bool CAN_W[MAXN], CAN_L[MAXN];
void ins(const string &s) {
    int u = 0;
    for (auto c : s) {
        int nxt = c - 'a';
        if (TRIE[u][nxt] == 0)
            TRIE[u][nxt] = ++SZ;
        u = TRIE[u][nxt];
    }
}


int main() {
    rii(N, K);
    while (N--) {
        string s; cin >> s;
        ins(s);
    }
    for (int i = SZ; i >= 0; --i) {
        bool leaf = true;
        FOR(c, 0, 26) leaf &= TRIE[i][c] == 0;
        if (leaf) {
            CAN_W[i] = 0;
            CAN_L[i] = 1;
        }
        else {
            FOR(c, 0, 26) if (TRIE[i][c] != 0)
                CAN_W[i] |= !CAN_W[TRIE[i][c]];
            FOR(c, 0, 26) if (TRIE[i][c] != 0)
                CAN_L[i] |= !CAN_L[TRIE[i][c]];
        }
    }
    if (CAN_L[0] && CAN_W[0])
        printf("First\n");
    else if (!CAN_W[0])
        printf("Second\n");
    else {
        if (K & 1)
            printf("First\n");
        else
            printf("Second\n");
    }

    return 0;
}