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

int main() {
    ll n, a, b; rl(n), rll(a, b);
    n = n * 6;
    if (a * b >= n) {
        printf("%lld\n", a * b);
        printf("%lld %lld\n", a, b);
        return 0;
    }
    bool swp = false;
    if (b > a) {
        swp = true;
        swap(a, b);
    }
    ll act = max(n, a * b);
    while (true) {
        for (ll i = b; i * i <= act; i++) {
            if (act % i == 0) {
                ll mx = max(i, act / i);
                ll mn = min(i, act / i);
                if (mx >= a && mn >= b) {
                    printf("%lld\n", act);
                    if (swp)
                        printf("%lld %lld\n", mn, mx);
                    else
                        printf("%lld %lld\n", mx, mn);
                    return 0;
                }
            }
        }
        act++;
    }

    return 0;
}