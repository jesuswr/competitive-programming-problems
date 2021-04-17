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
const int MAXN = 1e5; // CAMBIAR ESTE
const int ALPHA = 26;

// GJNM
class trie
{
public:
    trie *nxt[ALPHA];
    trie *prev;
    trie *best;
    bool vis;
    int dst;
    trie(trie *p) {
        FOR(i, 0, ALPHA) nxt[i] = NULL;
        prev = p;
        best = NULL;
        vis = false;
        dst = 0;
    }

};

int N, M;

void ins(trie *root, const string &s) {
    int j;
    for (int i = 0; i < SZ(s); ++i) {
        j = s[i] - 'a';
        if (root->nxt[j] == NULL)
            root->nxt[j] = new trie(root);
        root = root->nxt[j];
    }
    trie *tmp = root;
    if (root->best == NULL) root->best = tmp;
    for (int i = SZ(s) - 1; i >= 0 ; --i) {
        if (root->prev->best == NULL)
            root->prev->best = tmp;
        root = root->prev;
    }
}

void query(trie *root, const string &s) {
    int j;
    for (int i = 0; i < SZ(s); ++i) {
        j = s[i] - 'a';
        if (root->nxt[j] == NULL) {
            root->nxt[j] = new trie(root);
            root->nxt[j]->dst = root->dst + 1;
        }
        root = root->nxt[j];
    }
    printf("%d\n", root->dst);
}

int main() {
    rii(N, M);
    trie root(NULL);
    FOR(_, 0, N) {
        string s; cin >> s;
        ins(&root, s);
    }

    queue<trie*> bfs;
    bfs.push(&root); root.vis = true;
    root.best = NULL;
    while (!bfs.empty()) {
        trie *x = bfs.front(); bfs.pop();
        FOR(i, 0, ALPHA) if (x->nxt[i] != NULL && x->nxt[i]->vis == false) {
            x->nxt[i]->vis = true;
            x->nxt[i]->dst = x->dst + 1;
            bfs.push(x->nxt[i]);
        }
        if (x->best != NULL && x->best->vis == false) {
            x->best->vis = true;
            x->best->dst = x->dst + 1;
            bfs.push(x->best);
        }
        if (x->prev != NULL && x->prev->vis == false) {
            x->prev->vis = true;
            x->prev->dst = x->dst + 1;
            bfs.push(x->prev);
        }
    }

    FOR(_, 0, M) {
        string s; cin >> s;
        query(&root, s);
    }

    return 0;
}