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
set<int> pf(const string &s) {
    int n = SZ(s);
    vi pi(n);
    FOR(i, 1, n) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = j + 1;
    }

    set<int> ret;
    int j = pi[n - 1];
    while (j > 0) {
        ret.insert(j);
        j = pi[j - 1];
    }
    return ret;
}


void solve() {
    string s; cin >> s;
    string sr = s; reverse(ALL(sr));

    string aux = s + '$' + sr;
    auto pi1 = pf(aux);


    aux = sr + '$' + s;
    auto pi2 = pf(aux);

    int n = SZ(sr);
    for (auto x : pi1) if (pi2.count(n - x) > 0) {
            printf("alindrome\n");
            return;
        }
    if (pi1.count(n) > 0) printf("palindrome\n");
    else printf("simple\n");
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}