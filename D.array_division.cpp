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
int n;
ll s1, s2;
unordered_map<ll, int> n1, n2;
ll a[MAXN];

int main() {
    ri(n);
    FOR(i, 0, n) {
        rl(a[i]);
        s2 += a[i];
        n2[a[i]]++;;
    }
    n1.reserve(n);
    n2.reserve(n);
    bool ans = false;
    FOR(i, 0, n + 1) {
        if (s1 == s2)
            ans = true;
        if (s1 < s2) {
            ll need = s2 - s1;
            if (~need & 1) {
                need = need >> 1;
                if (n2[need] > 0)
                    ans = true;
            }
        }
        if (s1 > s2) {
            ll need = s1 - s2;
            if (~need & 1) {
                need = need >> 1;
                if (n1[need] > 0)
                    ans = true;
            }
        }

        if (i == n)
            continue;

        s1 += a[i];
        s2 -= a[i];
        n1[a[i]]++;
        n2[a[i]]--;
    }
    printf("%s\n", (ans ? "YES" : "NO"));
    return 0;
}