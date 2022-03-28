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
string A[1001];

vi pf(const vi &s) {
    int n = SZ(s);
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        j += s[i] == s[j];
        pi[i] = j;
    }
    return pi;
}

int main() {
    int n; ri(n);
    FOR(i, 0, n) cin >> A[i];
    int ans = 0;
    FOR(len, 1, SZ(A[0]) + 1) {
        vi S;
        FOR(i, SZ(A[0]) - len, SZ(A[0])) S.pb(A[0][i]);
        FOR(i, 1, n) {
            S.pb(i + 6969);
            for (auto c : A[i]) S.pb(c);
        }
        vi pi = pf(S);
        int mx = len;
        int act = 0;
        FOR(i, len + 1, SZ(pi)) {
            if (S[i] > 6969) {
                mx = min(mx, act);
                act = 0;
            }
            else
                act = max(act, pi[i]);
        }
        ans = max(ans, mx);
    }
    printf("%d\n", ans);
    return 0;
}