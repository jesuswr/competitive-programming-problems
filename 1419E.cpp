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
    int n; ri(n);
    vi divs = {n};
    vi primes;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.pb(i);
            if (i * i != n)
                divs.pb(n / i);
        }
    }
    sort(ALL(divs));
    FOR(i, 0, SZ(divs)) {
        bool is_p = 1;
        FOR(j, 0, i) if (divs[i] % divs[j] == 0) {
            is_p = 0;
            break;
        }
        if (is_p)
            primes.pb(divs[i]);
    }
    vi ans = {n};
    map<int, bool> used; used[n] = true;
    FOR(i, 0, SZ(primes)) {
        bool put_mid = 0;
        if (i + 1 < SZ(primes) && !used[primes[i] * primes[i + 1]]) {
            put_mid = 1;
            used[primes[i] * primes[i + 1]] = 1;
        }
        for (auto d : divs) if (d % primes[i] == 0 && !used[d]) {
                used[d] = 1;
                ans.pb(d);
            }
        if (put_mid)
            ans.pb(primes[i] * primes[i + 1]);
    }

    int cnt = SZ(primes) == 2 && SZ(divs) == 3;
    for (auto x : ans) printf("%d ", x);
    printf("\n");
    printf("%d\n", cnt);
}



int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}