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
const int MAXN = 5010; // CAMBIAR ESTE

// GJNM
int n, q;
int pre[MAXN][MAXN];
char s[MAXN];

struct trie {
    vector<pair<char, trie*>> nxt;
    int last;
    trie() {
        last = 0;
    }
};

trie root;

void ins(int prei, int si, int sn) {
    trie *act = &root;
    FOR(i, si, sn) {
        bool found = false;
        for (auto p : act->nxt) {
            if (p.F == s[i]) {
                act = p.S;
                found = true;
                break;
            }
        }

        if (!found) {
            trie *aux = new trie;
            act->nxt.pb({s[i], aux});
            act = aux;
        }

        if (act->last != 0)
            --pre[prei][act->last];
        ++pre[prei][prei];
        act->last = prei;
    }
}

int main() {
    rii(n, q);
    FOR(i, 1, n + 1) {
        if (i > 0)
            FOR(j, 0, n) pre[i][j] = pre[i - 1][j];

        dadsadasda =  scanf("%s", s);
        int sn = strlen(s);
        FOR(j, 0, sn) ins(i, j, sn);
    }
    FOR(i, 1, n + 1) FOR(j, 1, n + 1) pre[i][j] += pre[i][j - 1];

    int lst = 0;
    while (q--) {
        int a, b; rii(a, b);
        int l = (lst + a - 1) % n + 1;
        int r = (lst + b - 1) % n + 1;
        if (l > r)
            swap(l, r);
        lst = pre[r][r] - pre[r][l - 1];
        printf("%d\n", lst);
    }

    return 0;
}