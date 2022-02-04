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
bool valid(int mn, vi cnt, int k) {
    FOR(_, 0, k) {
        int c = 0;
        if (mn & 1) {
            FOR(i, 0, 30) if (cnt[i] & 1) {
                c++;
                cnt[i]--;
                break;
            }
            if (c == 0) {
                FOR(i, 0, 30) if (cnt[i]) {
                    c++;
                    cnt[i]--;
                    break;
                }
                if (c == 0)
                    return false;
            }
        }
        c = mn - c;
        FOR(i, 0, 30) if (cnt[i]) {
            int can_take = min((cnt[i] / 2) * 2, c);
            cnt[i] -= can_take;
            c -= can_take;
        }
        if (c)
            return false;
    }
    return true;
}

void solve() {
    int n, k; rii(n, k);
    string s; cin >> s;
    vi cnt(30);
    for (auto c : s) cnt[c - 'a']++;

    int odd = 0;
    FOR(i, 0, 30) odd += (cnt[i] & 1);

    int lo = 1, hi = n;
    while (lo < hi) {
        int mi = lo + (hi - lo + 1) / 2;
        if (valid(mi, cnt, k))
            lo = mi;
        else
            hi = mi - 1;
    }
    printf("%d\n", lo);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}