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
#include <time.h>

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
int N;
int X[MAXN], Y[MAXN];

struct LINE {
    int x, y;
    LINE(int a, int b) {
        x = a,
        y = b;
    }
    ll crossp(LINE t) {
        return 1ll * x * t.y - 1ll * y * t.x;
    }
};

bool check(int i, int j) {
    vi bad;
    LINE fst(X[i] - X[j], Y[i] - Y[j]);
    FOR(k, 0, N) {
        LINE aux(X[i] - X[k], Y[i] - Y[k]);
        if (fst.crossp(aux) == 0) continue;
        bad.pb(k);
    }
    if (SZ(bad) <= 2) return true;
    i = bad[0], j = bad[1];
    LINE snd(X[i] - X[j], Y[i] - Y[j]);
    FOR(k, 2, SZ(bad)) {
        LINE aux(X[i] - X[bad[k]], Y[i] - Y[bad[k]]);
        if (snd.crossp(aux) == 0) continue;
        return false;
    }
    return true;
}

int main() {
    ri(N);
    if (N < 5) {
        printf("YES\n");
        return 0;
    }
    FOR(i, 0, N) rii(X[i], Y[i]);
    srand(time(NULL));
    FOR(_, 0, 20) {
        int i = 0, j = 0;
        while (i == j) i = rand() % N, j = rand() % N;
        if (check(i, j)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");

    return 0;
}