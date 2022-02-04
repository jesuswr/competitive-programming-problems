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
string to_bin(ll a) {
    string ret;
    while (a > 0) {
        ret.pb('0' + (a & 1));
        a /= 2;
    }
    return ret;
}

bool match(string a, string b) {
    FOR(i, 0, SZ(a)) if (a.compare(i, SZ(b), b) == 0)
        return true;
    return false;
}

int main() {
    ll x, y; rll(x, y);
    auto bin_x = to_bin(x), bin_y = to_bin(y);
    {
        reverse(ALL(bin_x));
        while (bin_x.back() == '0') bin_x.pop_back();
    }
    if (match(bin_y, bin_x)) {
        printf("YES\n");
        return 0;
    }
    reverse(ALL(bin_x));
    if (match(bin_y, bin_x)) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}