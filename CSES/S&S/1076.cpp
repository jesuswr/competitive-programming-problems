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

void add(multiset<int> &sm, multiset<int> &bg, int a) {
    if (SZ(sm) == SZ(bg)) {
        if (!bg.empty() && *bg.begin() < a) {
            sm.insert(*bg.begin());
            bg.erase(bg.begin());
            bg.insert(a);
        }
        else
            sm.insert(a);
    }
    else {
        if (*sm.rbegin() > a) {
            bg.insert(*sm.rbegin());
            sm.erase(sm.find(*sm.rbegin()));
            sm.insert(a);
        }
        else
            bg.insert(a);
    }
}
void rm(multiset<int> &sm, multiset<int> &bg, int a) {
    if (SZ(sm) == SZ(bg)) {
        if (bg.find(a) != bg.end())
            bg.erase(bg.find(a));
        else {
            sm.erase(sm.find(a));
            sm.insert(*bg.begin());
            bg.erase(bg.begin());
        }
    }
    else {
        if (sm.find(a) != sm.end())
            sm.erase(sm.find(a));
        else {
            bg.erase(bg.find(a));
            bg.insert(*sm.rbegin());
            sm.erase(sm.find(*sm.rbegin()));
        }
    }
}

int main() {
    rii(n, k);
    FOR(i, 0, n) ri(x[i]);
    multiset<int> sm, bg;
    FOR(i, 0, k) add(sm, bg, x[i]);
    printf("%d ", *sm.rbegin());
    FOR(i, 1, n - k + 1) {
        rm(sm, bg, x[i - 1]);
        add(sm, bg, x[i - 1 + k]);
        printf("%d ", *sm.rbegin());
    }
    printf("\n");
    return 0;
}