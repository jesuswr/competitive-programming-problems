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
    long double a, d; dadsadasda = scanf("%Lf %Lf", &a, &d);
    ll n; rl(n);
    FOR(i, 1, n + 1) {
        long double l = i * d;
        long double laps = l / (4 * a);
        laps = (ll)laps;
        l = l - laps * 4 * a;
        if (l <= a) {
            printf("%Lf %Lf\n", l, (long double)0);
        }
        else if (l <= 2 * a) {
            printf("%Lf %Lf\n", (long double)a, l - a);
        }
        else if (l <= 3 * a) {
            printf("%Lf %Lf\n", a - (l - a - a), (long double)a);
        }
        else {
            printf("%Lf %Lf\n", (long double)0, 4 * a - l);
        }
    }

    return 0;
}