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
void solve(int ind, const vi &p, vi &ans, set<int> &free) {
    if (SZ(p) - 1 == ind) {
        for (auto it = free.rbegin(); it != free.rend(); ++it)
            ans.pb(*it);
    }
    else {
        ans.pb(p[ind]);
        free.erase(p[ind]);
        int aux = *free.begin();
        if (aux < p[ind]) {
            ans.pb(aux);
            free.erase(aux);
            aux++;
        }
        solve(ind + 1, p, ans, free);
    }
}

int main() {
    int n, m; rii(n, m);
    vi p(m);
    FOR(i, 0, m) ri(p[i]);
    vi ans;
    set<int> free;
    FOR(i, 0, n) free.insert(i + 1);
    solve(0, p, ans, free);
    FOR(i, 0, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}