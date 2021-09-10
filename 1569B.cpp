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
char M[69][69];
void solve() {
    int n; ri(n);
    FOR(i, 0, n) FOR(j, 0, n) M[i][j] = (i == j ? 'X' : '=');
    string s; cin >> s;
    vi inds;
    FOR(i, 0, n) if (s[i] == '2')
        inds.pb(i);

    if (SZ(inds) <= 2 && SZ(inds) >= 1)
        printf("NO\n");
    else {
        FOR(i, 0, SZ(inds)) {
            M[inds[i]][inds[(i + 1) % SZ(inds)]] = '+';
            M[inds[(i + 1) % SZ(inds)]][inds[i]] = '-';
        }
        printf("YES\n");
        FOR(i, 0, n) {
            FOR(j, 0, n) printf("%c", M[i][j]);
            printf("\n");
        }
    }
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}