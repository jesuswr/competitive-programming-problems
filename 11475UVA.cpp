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
int pf(const string &s, const string &t) {
    int n = SZ(s), m = SZ(t);
    vi pi(n);
    FOR(i, 1, n) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) j = pi[j - 1];
        if (s[j] == s[i]) pi[i] = j + 1;
    }
    int prev = 0;
    FOR(i, 0, m) {
        int j = prev;
        while (j > 0 && s[j] != t[i]) j = pi[j - 1];
        if (s[j] == t[i]) prev = j + 1;
        else prev = 0;
    }
    return prev;
}

int main() {
    string s;
    while (cin >> s) {
        string sr = s;
        reverse(ALL(sr));
        sr = sr + '$';
        int ans = SZ(s) - pf(sr, s);
        cout << s;
        for (int i = ans - 1; i >= 0; --i) printf("%c", s[i]);
        printf("\n");
    }

    return 0;
}