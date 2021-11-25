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
const ll MAXN = 1e12; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

ll read() {
    string s; cin >> s;
    int j = 0;
    FOR(i, 0, SZ(s)) if (s[i] == '.')
        j = i;
    while (SZ(s) - j <= 4) s.pb('0');
    ll ret = 0;
    for (auto c : s) {
        if (c == '.') continue;
        ret = 10 * ret + (c - '0');
    }
    return ret;
}

int main() {
    ll x;
    x = read();
    ll jump = (x * 10000) / gcd(x, 10000);

    vector<ll> ans;

    for (ll y = jump; y <= MAXN; y += jump) {
        if (y % 100000 == 0)
            continue;
        ll a = y / 10000;
        ll dig = a % 10;
        a /= 10;

        ll aux = a;
        while (aux > 0) {
            aux /= 10;
            dig *= 10;
        }

        a = dig + a;

        if (a * x == y && a < 1e8)
            ans.pb(a);

    }

    if (ans.empty())
        printf("No solution\n");
    else {
        sort(ALL(ans));
        for (auto a : ans) printf("%lld\n", a);
    }


    return 0;
}