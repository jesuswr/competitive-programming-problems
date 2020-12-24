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
set<int> q;

pii query() {
    printf("?");
    for (auto x : q) printf(" %d", x);
    printf("\n");
    fflush(stdout);
    pii ret;
    rii(ret.F, ret.S);
    return ret;
}

int main() {
    int n, k; rii(n, k);
    FOR(i, 1, k + 1) q.insert(i);
    pii a = query();
    q.erase(a.F); q.insert(k + 1);
    pii b = query();

    int less = 0, gret = 0;
    if (a.S < b.S) {
        for (int i = 1; i <= k + 1; i++) {
            if (i == a.F || i == b.F) continue;
            q.erase(i);
            q.insert(a.F);
            if (query() == b)
                less++;
            else
                gret++;
            q.insert(i);
            q.erase(a.F);
        }
    }
    else {
        for (int i = 1; i <= k + 1; i++) {
            if (i == a.F || i == b.F) continue;
            q.erase(i);
            q.insert(a.F);
            if (query() == b)
                gret++;
            else
                less++;
            q.insert(i);
            q.erase(a.F);
        }
    }
    printf("! %d\n", less + 1);
    fflush(stdout);

    return 0;
}