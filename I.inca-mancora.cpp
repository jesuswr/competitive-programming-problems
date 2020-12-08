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

// GJNM
int n, m, q;
struct EVENT {
    int x;
    bool open, close;
    int ind;
};
bool comp(EVENT &a, EVENT &b) {
    if (a.x != b.x)
        return a.x < b.x;

    if (a.close && b.close)
        return a.x < b.x;
    if (a.close)
        return true;
    if (b.close)
        return false;

    if (a.open && b.open)
        return a.x < b.x;
    if (a.open)
        return true;
    if (b.open)
        return false;

    return a.x < b.x;
}
vector<EVENT> A[MAXN];

int ans[MAXN];

int main() {
    riii(n, m, q);
    FOR(i, 0, m) {
        int a, b, k; riii(k, a, b);
        EVENT aux;
        aux.open = true, aux.close = false;
        aux.x = a;
        A[b - a].pb(aux);
        EVENT aux2;
        aux2.open = false, aux2.close = true;
        aux2.x = a + k;
        A[b - a].pb(aux2);
    }
    FOR(i, 0, q) {
        int a, b; rii(a, b);
        EVENT aux;
        aux.open = aux.close = false;
        aux.x = min(a, b), aux.ind = i;
        A[abs(b - a)].pb(aux);

    }
    FOR(i, 0, n + 1) {
        sort(ALL(A[i]), comp);

        int open = 0;
        for (auto e : A[i]) {
            if (e.open)
                open++;
            else if (e.close)
                open--;
            else
                ans[e.ind] = open;
        }
    }
    FOR(i, 0, q) {
        if (ans[i] & 1)
            printf("SI\n");
        else
            printf("NO\n");
    }

    return 0;
}