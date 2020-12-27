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
const int MAXN = 1e7 + 10; // CAMBIAR ESTE

// GJNM
int NS, NT;
int N;
string S, T;
int PI[100010];
vector<vi> DP;
int NXT[27][100010];

void pf(const string &s) {
    int n = SZ(s);
    FOR(i, 1, n) {
        int j = PI[i - 1];
        while (j > 0 && s[i] != s[j]) j = PI[j - 1];
        if (s[i] == s[j]) PI[i] = j + 1;
    }
}

int f2(char c, int pre) {
    if (NXT[c - 'a'][pre] != -1) return NXT[c - 'a'][pre];
    int j = pre;
    while (j > 0 && c != T[j]) j = PI[j - 1];
    if (c == T[j]) j = j + 1;
    return NXT[c - 'a'][pre] = j;
}


int f(int p, int pre) {
    if (p == N) return 0;
    if (DP[p - NT][pre] != -1) return DP[p - NT][pre];

    int ret = 0;
    if (T[p] == '?') {
        for (char c = 'a'; c <= 'z'; c++) {
            int nxt = f2(c, pre);
            ret = max(ret, f(p + 1, nxt) + (nxt == NT));
        }
    }
    else {
        int nxt = f2(T[p], pre);
        ret = f(p + 1, nxt) + (nxt == NT);
    }
    return DP[p - NT][pre] = ret;
}



int main() {
    memset(NXT, -1, sizeof(NXT));
    cin >> S; cin >> T;
    NS = SZ(S); NT = SZ(T);
    N = NT + 1 + NS;
    T = T + '$';
    pf(T);
    T = T + S;
    DP = vector<vector<int>>( NS + 10 , vector<int>(NT + 1, -1) );
    printf("%d\n", f(NT + 1, 0));

    return 0;
}