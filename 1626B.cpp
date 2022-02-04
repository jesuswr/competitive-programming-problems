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


void solve() {
    string s; cin >> s;
    int n = SZ(s);
    FOR(i, 0, n - 1) {
        int d1 = s[i] - '0', d2 = s[i + 1] - '0';
        int sm = d1 + d2;
        if (sm < 10) continue;
        int new_d1 = sm / 10, new_d2 = sm % 10;
        if (new_d1 > d1 || (new_d1 >= d1 && new_d2 > d2)) {
            s[i] = new_d1 + '0';
            s[i + 1] = new_d2 + '0';
            cout << s << endl;
            return;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        int d1 = s[i] - '0', d2 = s[i + 1] - '0';
        int sm = d1 + d2;
        if (sm < 10) continue;
        int new_d1 = sm / 10, new_d2 = sm % 10;
        s[i] = new_d1 + '0';
        s[i + 1] = new_d2 + '0';
        cout << s << endl;
        return;
    }
    FOR(i, 0, n - 1) {
        int d1 = s[i] - '0', d2 = s[i + 1] - '0';
        int sm = d1 + d2;
        int new_d1 = sm % 10, new_d2 = sm % 10;
        s[i] = new_d1 + '0';
        FOR(j, 0, i + 1) cout << s[j];
        FOR(j, i + 2, n) cout << s[j];
        cout << endl;
        return;
    }

}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}