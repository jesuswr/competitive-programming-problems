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
bool query(ll a, ll b) {
    printf("? %lld %lld\n", a, b);
    fflush(stdout);
    string s; cin >> s;
    return s[0] == 'x';
}

int main() {
    string s;
    while (cin >> s, s[0] == 's') {
        ll lo = 0, hi = 1;
        while (!query(lo, hi)) {
            lo = hi;
            hi <<= 1;
        }
        ll l = lo + 1, h = hi;
        while (l < h) {
            ll mi = l + (h - l) / 2;
            if (query(lo, mi))
                h = mi;
            else
                l = mi + 1;
        }
        printf("! %lld\n", l);
        fflush(stdout);
    }
    return 0;
}