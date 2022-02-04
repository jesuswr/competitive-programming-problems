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
ll get_str_cnt(const vector<pair<char, int>> &a, int l) {
    __int128 cnt = 1, mx = LLINF + 69;
    for (int i = l; i < SZ(a); ++i)
        cnt = min(cnt * a[i].S, mx);
    return (ll)cnt;
}


void solve() {
    int n, k; rii(n, k);
    ll x; rl(x); --x;
    string s; cin >> s;
    vector<pair<char, int>> a;
    for (auto c : s) {
        if (!a.empty() && a.back().F == '*' && c == '*')
            a[a.size() - 1].S += k;
        else
            a.pb({c, c == 'a' ? 1 : k + 1});
    }
    // for (auto [c, cnt] : a) {
    //     printf("%c %d\n", c, cnt);
    // }
    string ans;
    for (int i = 0; i < SZ(a); ++i) {
        if (a[i].F == 'a')
            ans.pb('a');
        else {
            ll n_strs = get_str_cnt(a, i + 1);
            while (x >= n_strs) {
                ans.pb('b');
                x -= n_strs;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}