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

bool good(const string &s) {
    int ab = 0, ba = 0;
    FOR(i, 0, SZ(s) - 1) {
        if (s[i] == 'a' && s[i + 1] == 'b')
            ab++;
        if (s[i] == 'b' && s[i + 1] == 'a')
            ba++;
    }
    return ab == ba;
}

void solve() {
    string s; cin >> s;
    if (good(s)) {
        cout << s << endl;
        return;
    }
    FOR(i, 0, SZ(s)) {
        char original = s[i];
        s[i] = 'a';
        if (good(s)) {
            cout << s << endl;
            return;
        }
        s[i] = 'b';
        if (good(s)) {
            cout << s << endl;
            return;
        }
        s[i] = original;
    }
}


int main() {
    int t = 1;
    ri(t);
    while (t--)
        solve();
    return 0;
}