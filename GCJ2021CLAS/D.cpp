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
#include <fstream>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

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

// GJNM
int N, Q;

int query(int a, int b, int c) {
    printf("%d %d %d\n", a, b, c);
    fflush(stdout);
    int ret; ri(ret);
    if (ret == -1) exit(0);
    return ret;
}

struct node {
    node *l, *r;
    int ind;
    node(int x) {
        l = NULL;
        r = NULL;
        ind = x;
    }
};


void place_right(node *root, int i);

void place_left(node *root, int i) {
    if (root->l == NULL) {
        root->l = new node(i);
    }
    else {
        int mid = query(i, root->ind, root->l->ind);
        if (mid == i) place_right(root->l, i);
        else if (mid == root->ind) place_right(root, i);
        else place_left(root->l, i);
    }
}

void place_right(node *root, int i) {
    if (root->r == NULL) {
        root->r = new node(i);
    }
    else {
        int mid = query(i, root->ind, root->r->ind);
        if (mid == i) place_left(root->r, i);
        else if (mid == root->ind) place_left(root, i);
        else place_right(root->r, i);
    }
}


void dfs(node *root) {
    if (root == NULL) return;
    dfs(root->l);
    printf("%d ", root->ind);
    dfs(root->r);
}

void solve() {
    vi inds;
    FOR(i, 0, N) inds.pb(i + 1);
    random_shuffle(ALL(inds));
    int r = query(inds[0], inds[1], inds[2]);

    node *root = new node(r);
    FOR(i, 0, 3) if (r != inds[i]) root->r = new node(inds[i]);
    FOR(i, 0, 3) if (r != inds[2 - i]) root->l = new node(inds[2 - i]);
    FOR(i, 3, N) place_right(root, inds[i]);

    dfs(root);
    printf("\n");
    fflush(stdout);
    int trash; ri(trash);
    if (trash == -1) exit(0);
}

int main() {
    std::srand ( unsigned ( std::time(0) ) );
    int t;
    riii(t, N, Q);
    FOR(i, 1, t + 1) {
        solve();
    }

    return 0;
}