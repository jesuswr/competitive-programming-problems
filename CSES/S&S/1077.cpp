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
const int MAXN = 2e5; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int n, k;
int x[MAXN];

void add(multiset<int> &sm, multiset<int> &bg, ll &sum_sm, ll &sum_bg, int a) {
    if (SZ(sm) == SZ(bg)) {
        if (!bg.empty() && *bg.begin() < a) {
            sum_sm += *bg.begin();
            sm.insert(*bg.begin());
            sum_bg -= *bg.begin();
            bg.erase(bg.begin());
            sum_bg += a;
            bg.insert(a);
        }
        else {
            sum_sm += a;
            sm.insert(a);
        }
    }
    else {
        if (*sm.rbegin() > a) {
            sum_bg += *sm.rbegin();
            bg.insert(*sm.rbegin());
            sum_sm -= *sm.rbegin();
            sm.erase(sm.find(*sm.rbegin()));
            sum_sm += a;
            sm.insert(a);
        }
        else {
            sum_bg += a;
            bg.insert(a);
        }
    }
}
void rm(multiset<int> &sm, multiset<int> &bg, ll &sum_sm, ll &sum_bg, int a) {
    if (SZ(sm) == SZ(bg)) {
        if (bg.find(a) != bg.end()) {
            sum_bg -= a;
            bg.erase(bg.find(a));
        }
        else {
            sum_sm -= a;
            sm.erase(sm.find(a));
            sum_sm += *bg.begin();
            sm.insert(*bg.begin());
            sum_bg -= *bg.begin();
            bg.erase(bg.begin());
        }
    }
    else {
        if (sm.find(a) != sm.end()) {
            sum_sm -= a;
            sm.erase(sm.find(a));
        }
        else {
            sum_bg -= a;
            bg.erase(bg.find(a));
            sum_bg += *sm.rbegin();
            bg.insert(*sm.rbegin());
            sum_sm -= *sm.rbegin();
            sm.erase(sm.find(*sm.rbegin()));
        }
    }
}

int main() {
    rii(n, k);
    FOR(i, 0, n) ri(x[i]);
    multiset<int> sm, bg;
    ll sum_sm = 0, sum_bg = 0;
    FOR(i, 0, k) add(sm, bg, sum_sm, sum_bg, x[i]);
    ll med = *sm.rbegin();
    printf("%lld ", (1ll * SZ(sm) * med - sum_sm) + (sum_bg - 1ll * SZ(bg) * med));
    FOR(i, 1, n - k + 1) {
        rm(sm, bg, sum_sm, sum_bg, x[i - 1]);
        add(sm, bg, sum_sm, sum_bg, x[i - 1 + k]);
        med = *sm.rbegin();
        printf("%lld ", (1ll * SZ(sm) * med - sum_sm) + (sum_bg - 1ll * SZ(bg) * med));
    }
    printf("\n");
    return 0;
}