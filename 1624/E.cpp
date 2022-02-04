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
const int MAXN = 1e3 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
map<string, pii> H;
string S;
bool DP[MAXN];

void solve() {
    H.clear();
    rii(N, M);
    FOR(i, 0, N) {
        string s; cin >> s;
        FOR(l, 0, M - 1) H[ s.substr(l, 2) ] = {i + 1, l + 1};
        FOR(l, 0, M - 2) H[ s.substr(l, 3) ] = {i + 1, l + 1};
    }
    cin >> S;
    S = S + "$$$$69$MONEY$69$$$$";

    DP[M] = 1;
    DP[M + 1] = DP[M + 2] = DP[M + 3] = 0;
    for (int i = M - 1; i >= 0; --i) {
        DP[i] = 0;
        if (H.find(S.substr(i, 2)) != H.end() )
            DP[i] |= DP[i + 2];
        if (H.find(S.substr(i, 3)) != H.end())
            DP[i] |= DP[i + 3];
    }

    if (DP[0] == false) {
        printf("-1\n");
        return;
    }

    vector<pii> ans;
    vi aux;
    for (int i = 0; i < M;) {
        if (DP[i + 2]) {
            ans.pb(H[S.substr(i, 2)]);
            aux.pb(2);
            i += 2;
        }
        else if (DP[i + 3]) {
            ans.pb(H[S.substr(i, 3)]);
            aux.pb(3);
            i += 3;
        }
    }
    printf("%d\n", SZ(ans));
    FOR(i, 0, SZ(ans)) {
        printf("%d %d %d\n", ans[i].S, ans[i].S + aux[i] - 1, ans[i].F);
    }

}


int main() {
    int t; ri(t);
    while (t--) solve();

    return 0;
}