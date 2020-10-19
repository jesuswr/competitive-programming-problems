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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
bool has_zero(const string &s) {
    for (auto c : s) {
        if (c == '0')
            return true;
    }
    return false;
}


void solve() {
    string s;
    cin >> s;
    int n;
    ri(n);
    vi b(n);
    FOR(i, 0, n) {
        ri(b[i]);
    }

    vector<pair<int, char>> have;
    string t(n, '0');
    vector<int> cnt(30, 0);

    for (auto c : s) {
        cnt[c - 'a']++;
    }

    int curr = 'z' - 'a';
    while (has_zero(t)) {
        if (cnt[curr] == 0) {
            curr--;
            continue;
        }
        vi put;
        FOR(i, 0, n) {
            if (t[i] != '0')
                continue;
            int cnt = 0;
            for (auto p : have) {
                cnt += abs(i - p.F);
            }
            if (cnt == b[i]) {
                put.pb(i);
            }
        }

        if (put.size() == 0) {
            curr--;
            continue;
        }
        if (put.size() > cnt[curr]) {
            curr--;
            continue;
        }

        for (auto i : put) {
            t[i] = 'a' + curr;
            have.pb({i, curr + 'a'});
        }
        curr--;
    }

    cout << t << endl;
}


int main() {
    int q;
    ri(q);
    while (q--) {
        solve();
    }

    return 0;
}