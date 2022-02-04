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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM


vector<string> go(int n) {
    if (n == 0) {
        vector<string> ret = {"#"};
        return ret;
    }


    auto rec = go(n - 1);
    int l = SZ(rec);
    vector<string> ret(3 * l);

    FOR(i, 0, l) {
        FOR(j, 0, l) ret[i].pb(rec[i % l][j]);
        FOR(j, 0, l) ret[i].pb(' ');
        FOR(j, 0, l) ret[i].pb(rec[i % l][j]);
    }
    FOR(i, l, 2 * l) {
        FOR(j, 0, l) ret[i].pb(' ');
        FOR(j, 0, l) ret[i].pb(rec[i % l][j]);
        FOR(j, 0, l) ret[i].pb(' ');
    }
    FOR(i, 2 * l, 3 * l) {
        FOR(j, 0, l) ret[i].pb(rec[i % l][j]);
        FOR(j, 0, l) ret[i].pb(' ');
        FOR(j, 0, l) ret[i].pb(rec[i % l][j]);
    }
    return ret;
}

int main() {
    int n; ri(n);
    auto ans = go(n);
    bool aux = 0;
    for (auto s : ans) {
        if (aux) cout << endl;
        cout << s;
        aux = 1;
    }
    return 0;
}