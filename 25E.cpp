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
string S[3];

bool is_substr(const string &pat, const string &txt) {
    int n = SZ(pat);
    vi pi(n + 1);
    FOR(i, 1, n) {
        int j = pi[i - 1];
        while (j > 0 && pat[i] != pat[j]) j = pi[j - 1];
        if (pat[i] == pat[j]) pi[i] = j + 1;
    }
    int lst = 0;
    for (auto c : txt) {
        int j = lst;
        while (j > 0 && c != pat[j]) j = pi[j - 1];
        if (c == pat[j]) lst = j + 1;
        else lst = 0;
        if (lst == n) return true;
    }
    return false;
}

int solve_aux(const string &a) {
    int n = SZ(a);
    vi pi(n);
    FOR(i, 1, n) {
        int j = pi[i - 1];
        while (j > 0 && a[j] != a[i]) j = pi[j - 1];
        if (a[j] == a[i]) pi[i] = j + 1;
    }
    return pi[n - 1];
}

int solve(string f, const string &s, const string &t) {
    int mx = solve_aux(s + '$' + f);
    FOR(i, mx, SZ(s)) f += s[i];
    mx = solve_aux(t + '$' + f);
    FOR(i, mx, SZ(t)) f += t[i];
    return SZ(f);
}

int main() {
    FOR(i, 0, 3) cin >> S[i];
    FOR(i, 0, 3) FOR(j, 0, 3) if (i != j) {
        if (is_substr(S[i], S[j])) S[i].clear();
    }
    int mn = 3e5;
    FOR(i, 0, 3) FOR(j, 0, 3) FOR(k, 0, 3) if (i != j && j != k && i != k)
        mn = min(mn, solve(S[i], S[j], S[k]));
    printf("%d\n", mn);
    return 0;
}