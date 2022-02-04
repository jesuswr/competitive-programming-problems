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

bool all_equal(string s) {
    sort(ALL(s));
    return s[0] == s.back();
}

void solve() {
    int n; ri(n);
    string s; cin >> s;
    if (all_equal(s)) {
        cout << s[0] << s[0] << endl;
        return;
    }
    if (n > 1 && s[0] == s[1]) {
        cout << s[0] << s[0] << endl;
        return;
    }
    FOR(i, 0, n - 1) {
        if (s[i + 1] > s[i]) {
            FOR(j, 0, i + 1) cout << s[j];
            FOR(j, 0, i + 1) cout << s[i - j];
            cout << endl;
            return;
        }
    }
    FOR(j, 0, n) cout << s[j];
    FOR(j, 0, n) cout << s[n - 1 - j];
    cout << endl;
}

int main() {
    int t; ri(t);
    while (t--) {
        solve();
    }

    return 0;
}