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

using namespace std;

typedef long long ll;
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

// GJNM
void print(__int128 x) {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void solve() {
    ll auxy; rl(auxy);
    __int128 y = auxy, y2 = auxy;
    vector<__int128> pos;

    vector<__int128> digits;
    while (y2 > 0) {
        digits.pb(y2 % 10);
        y2 /= 10;
    } reverse(ALL(digits));

    FOR(i, 1, min(SZ(digits)+1, 12)) {
        __int128 put = 0;
        FOR(j, 0, i) put = 10 * put + digits[j];
        FOR(k, 0, 1000) {
            __int128 aux = put + k;
            __int128 aux2 = put + k;
            while (true) {
                aux2 = aux2 + 1;
                __int128 tmp = aux2;
                vector<__int128> digits2;
                while (tmp > 0) {
                    digits2.pb(tmp % 10);
                    tmp /= 10;
                } reverse(ALL(digits2));
                for (auto x : digits2) aux = 10 * aux + x;
                pos.pb(aux);
                if (aux > y) break;
            }
        }
    }
    bool anss = false;
    __int128 ans;
    for (auto x : pos) {
        if (x > y) {
            if (anss) {
                if (ans - y > x - y) ans = x;
            }
            else {
                anss = true;
                ans = x;
            }
        }
    }
    print(ans); printf("\n");

}

int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}