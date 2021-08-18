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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
vector<string> p2s;
void pre() {
    ll x = 1;
    while (x <= LLINF) {
        ll aux_x = x;
        string new_p2;
        while (aux_x > 0) {
            new_p2.pb((aux_x % 10) + '0');
            aux_x /= 10;
        }
        reverse(ALL(new_p2));
        p2s.pb(new_p2);
        x <<= 1;
    }
}

void solve() {
    string s; cin >> s;
    int ans = 6969;
    for (auto t : p2s) {
        int i = 0, j = 0;
        int op = 0;
        while (i < SZ(s) && j < SZ(t)) {
            // if (t == "1024" && s == "1052")
                // printf("%d %d\n", i, j);
            if (s[i] == t[j]) {
                ++i;
                ++j;
            }
            else {
                ++op;
                ++i;
            }
            // if (t == "1024" && s == "1052")
                // printf("%d %d\n", i, j);
        }

        if (i < SZ(s))
            op += SZ(s) - i;
        else if (j < SZ(t))
            op += SZ(t) - j;

        ans = min(ans, op);
    }
    printf("%d\n", ans);
}



int main() {
    pre();
    int t; ri(t);
    while (t--) solve();

    return 0;
}