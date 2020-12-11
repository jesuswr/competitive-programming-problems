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
const int ALPHA = 26;

// GJNM
int t = 1;
bool win[MAXN], lose[MAXN];
int trie[MAXN][ALPHA];

void ins(string &s) {
    int p = 0;
    for (auto c : s) {
        int to = c - 'a';
        if (trie[p][to] == 0)
            trie[p][to] = t++;
        p = trie[p][to];
    }
}

void dfs(int id) {
    bool is_leaf = true;
    lose[id] = false;

    FOR(i, 0, ALPHA) {
        if (trie[id][i] == 0)
            continue;
        is_leaf = false;
        dfs(trie[id][i]);
        lose[id] |= !lose[trie[id][i]];
        win[id] |= !win[trie[id][i]];
    }

    if (is_leaf) {
        win[id] = false;
        lose[id] = true;
    }
}


int main() {
    int n, k;
    rii(n, k);
    FOR(_, 0, n) {
        string s; cin >> s;
        ins(s);
    }
    dfs(0);

    if (lose[0] && win[0])
        printf("First\n");
    else if (!win[0])
        printf("Second\n");
    else if (k & 1)
        printf("First\n");
    else
        printf("Second\n");
    return 0;
}