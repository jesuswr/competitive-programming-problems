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
const int MAXN = 1e6 + 10; // CAMBIAR ESTE

// GJNM
int n;
char s[MAXN];

ll P = 31;
ll MOD = 1e9 + 7;
ll dp;

ll bpow(ll b, ll e) {
    if (e == 0)
        return 1;
    ll ret = bpow(b, e / 2);
    ret = (ret * ret) % MOD;
    if (e & 1)
        ret = (ret * b) % MOD;
    return ret;
}

bool valid(int len, ll hl) {
    ll hr = 0;
    int l = 1, r = 1;
    ll p = 1;
    while (r - l < len) {
        hr = (hr + (s[r] - 'a') * p) % MOD;
        p = (p * P) % MOD;
        r++;
    }
    if (hl == hr) {
        return true;
    }

    while (r < n - 1) {
        hr = (hr - (s[l] - 'a') + MOD + (s[r] - 'a') * p) % MOD;
        hr = (hr * dp) % MOD;
        if (hl == hr) {
            return true;
        }
        r++;
        l++;
    }
    return false;
}


int main() {
    scanf("%s", s); n = strlen(s);
    dp = bpow(P, MOD - 2);

    int l = 0, r = n - 1;
    ll hl = 0, hr = 0;
    ll p = 1;
    vector<pair<int, ll>> bs;
    bs.pb({0, 0});
    while (r > 1) {
        hl = (hl + (s[l] - 'a') * p) % MOD;
        hr = ((s[r] - 'a') + hr * P) % MOD;
        l++, r--;
        p = (p * P) % MOD;
        if (hl == hr) {
            bs.pb({l, hl});
        }
    }

    int lo = 0, hi = bs.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (valid(bs[mid].F, bs[mid].S))
            lo = mid;
        else
            hi = mid - 1;
    }

    if (lo) {
        s[bs[lo].F] = '\0';
        printf("%s\n", s);
    }
    else
        printf("Just a legend\n");
    return 0;
}