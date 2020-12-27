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
string s;
set<pii> pos;
string alpha = "RLUD";

pii add(pii a, char c) {
    if (c == 'R') return {a.F + 1, a.S};
    if (c == 'L') return {a.F - 1, a.S};
    if (c == 'U') return {a.F, a.S + 1};
    if (c == 'D') return {a.F, a.S - 1};
    return a;
}

void solve() {
    pos.clear();
    cin >> s;
    s = "?" + s;
    pii a = {0, 0};
    for (auto c : s) {
        a = add(a, c);
        for (auto c2 : alpha) pos.insert(add(a, c2));
    }
    pos.insert({60000, 60000});

    for (auto p : pos) {
        if (p.F == 0 && p.S == 0) continue;
        pii b = {0, 0};
        for (auto c : s) {
            auto d = add(b, c);
            if (d != p) b = d;
        }

        if (b.F == 0 && b.S == 0) {
            printf("%d %d\n", p.F, p.S);
            return;
        }
    }

    printf("0 0\n");
}


int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}