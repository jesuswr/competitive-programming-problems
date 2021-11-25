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
vector<string> split(string s) {
    vector<string> ret;
    string t;
    for (auto c : s) {
        if (c == '/' && !t.empty()) {
            ret.pb(t);
            t.clear();
        }
        else
            t.pb(c);
    }
    if (!t.empty())
        ret.pb(t);
    return ret;
}

int main() {
    string s, t;
    cin >> s >> t;
    auto vs = split(s), vt = split(t);
    int l = 0;
    while (l < min(SZ(vs), SZ(vt)) && vs[l] == vt[l]) ++l;
    int r = 0;
    while (l + r < min(SZ(vs), SZ(vt)) && vs[SZ(vs) - r - 1] == vt[SZ(vt) - r - 1])++r;
    if (l == min(SZ(vs), SZ(vt)))
        --l;
    else if (r == min(SZ(vs), SZ(vt)))
        --r;
    for (int i = 0; i < l; ++i) {
        cout << vs[i];
        if (i + 1 < SZ(vs))
            cout << '/';
    }
    cout << '{';
    for (int i = l; i < SZ(vs) - r; ++i) {
        if (i > l)
            cout << '/';
        cout << vs[i];
    }
    cout << " => ";
    for (int i = l; i < SZ(vt) - r; ++i) {
        if (i > l)
            cout << '/';
        cout << vt[i];
    }
    cout << '}';
    for (int i = SZ(vs) - r; i < SZ(vs); ++i) {
        if (i > 0)
            cout << '/';
        cout << vs[i];
    }
    cout << endl;
    return 0;
}