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
const int MAXN = 4e5; // CAMBIAR ESTE

// GJNM
int n;
string s;


int main() {
    ri(n);
    cin >> s;
    ll ret = (1ll * n * (n - 1)) >> 1;

    int last_a = n , last_b = n ;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            ret -= max(0, last_a - 1 - i);
            last_a = i;
        }
        else {
            ret -= max(0, last_b - 1 - i);
            last_b = i;
        }
    }
    reverse(ALL(s));
    last_a = n , last_b = n;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            ret -= max(0, last_a - 2 - i);
            last_a = i;
        }
        else {
            ret -= max(0, last_b - 2 - i);
            last_b = i;
        }
    }
    printf("%lld\n", ret);
    return 0;
}