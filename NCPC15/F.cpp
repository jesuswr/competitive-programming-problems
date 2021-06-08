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
const int MAXN = 110; // CAMBIAR ESTE

// GJNM
int T, N;
pii A[MAXN];

void solve() {
    rii(T, N);
    FOR(i, 0, N) rii(A[i].F, A[i].S);

    set<int> valid;
    FOR(i, 0, T + 1) valid.insert(i);

    FOR(i, 0, N) {
        set<int> new_valid;
        for (auto j : valid) {
            if (j + (A[i].S - A[i].F) <= T) new_valid.insert(j + (A[i].S - A[i].F));
            if (j - (A[i].S - A[i].F) >= 0) new_valid.insert(j - (A[i].S - A[i].F));
        }
        swap(valid, new_valid);
    }
    if (valid.empty()) {
        printf("impossible\n");
        exit(0);
    }
}

int main() {
    int t; ri(t);
    while (t--) solve();
    printf("possible\n");
    return 0;
}