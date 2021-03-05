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
string S, T;
string AUX, AUX2;

vi pf(const string &s) {
    int n = SZ(s);
    vi pi(n);
    FOR(i, 1, n) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) j = pi[j - 1];
        if (s[j] == s[i]) pi[i] = j + 1;
    }
    return pi;
}

int main() {
    cin >> S >> T;
    AUX = T + '$' + S;
    AUX2 = S + '$' + T;
    reverse(ALL(AUX2));

    vi ans;
    vi pref = pf(AUX), prefrev = pf(AUX2);
    FOR(i, 0, SZ(S)) {
        int l = i, r = SZ(S) - 1 - i;
        if (pref[ SZ(T) + l ] == l && prefrev[ SZ(T) + r] == r) ans.pb(i);
    }
    printf("%d\n", SZ(ans));
    for (auto x : ans) printf("%d ", x + 1);
    printf("\n");
    return 0;
}