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
string A, W, S;
int IND[300];

void shift() {
    FOR(i, 0, SZ(W)) W[i] = A[(IND[(int)W[i]] + 1) % SZ(A)];
}

vi pf(const string &s) {
    int n = SZ(s);
    vi pi(n);
    FOR(i, 1, n) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = j + 1;
    }
    return pi;
}



bool kmp() {
    string t = W + '$' + S;
    vi pi = pf(t);
    int cnt = 0;
    for (auto p : pi) if (p == SZ(W)) cnt++;

    return cnt == 1;
}

int main() {
    int t; ri(t);
    while (t--) {
        cin >> A; cin >> W; cin >> S;
        FOR(i, 0, SZ(A)) IND[(int)A[i]] = i;

        vi goods;
        FOR(i, 0, SZ(A)) {
            if (i > 0) shift();
            if (kmp()) goods.pb(i);
        }

        if (SZ(goods) == 0) printf("no solution\n");
        else if (SZ(goods) == 1) printf("unique: %d\n", goods[0]);
        else {
            printf("ambiguous:");
            for (auto x : goods) printf(" %d", x);
            printf("\n");
        }
    }

    return 0;
}