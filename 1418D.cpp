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
int N, Q;
int P[MAXN];
set<int> xs;
multiset<int> gaps;

int f() {
    if (gaps.size() <= 1) return 0;
    return *xs.rbegin() - *xs.begin() - *gaps.rbegin();
}

void erase(int x) {
    auto it = xs.ub(x);
    int x2 = -1;
    if (it != xs.end()) {
        x2 = *it;
        gaps.erase(gaps.lb(*it - x));
    }
    it = xs.lb(x);
    int x3 = -1;
    if (it != xs.begin()) {
        --it;
        x3 = *it;
        gaps.erase(gaps.lb(x - *it));
    }
    if (x2 != -1 && x3 != -1) gaps.insert(x2 - x3);
    xs.erase(x);
}

void add(int x) {
    auto it = xs.lb(x);
    int x2 = -1, x3 = -1;
    if (it != xs.end()) x2 = *it;
    if (it != xs.begin()) x3 = *(--it);
    if (x2 != -1 && x3 != -1) gaps.erase(gaps.lb(x2 - x3));
    if (x2 != -1) gaps.insert(x2 - x);
    if (x3 != -1) gaps.insert(x - x3);
    xs.insert(x);
}

int main() {
    rii(N, Q);
    FOR(i, 0, N) ri(P[i]);
    sort(P, P + N);

    FOR(i, 0, N) {
        xs.insert(P[i]);
        if (i > 0)
            gaps.insert(P[i] - P[i - 1]);
    }

    printf("%d\n", f());
    while (Q--) {
        int t, x; rii(t, x);
        if (t == 0) erase(x);
        else add(x);
        printf("%d\n", f());
    }

    return 0;
}