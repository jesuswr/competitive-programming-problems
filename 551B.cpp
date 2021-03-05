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
int CNT[3][26];

int main() {
    cin >> S[0] >> S[1] >> S[2];
    FOR(i, 0, 3) for (auto c : S[i]) ++CNT[i][c - 'a'];
    int mx1 = 0, mx2 = 0;
    FOR(i, 0, SZ(S[0]) + 1) {
        bool brk = false;
        FOR(j, 0, 26) if (CNT[1][j] * i > CNT[0][j]) brk = true;
        if (brk) break;
        vi cnt(26);
        FOR(j, 0, 26) cnt[j] = CNT[0][j] - CNT[1][j] * i;
        int mn = INF;
        FOR(j, 0, 26) if (CNT[2][j] > 0) mn = min(mn, cnt[j] / CNT[2][j]);
        if (mx1 + mx2 < i + mn) {
            mx1 = i;
            mx2 = mn;
        }
    }
    string ans;
    FOR(_, 0, mx1) ans += S[1];
    FOR(_, 0, mx2) ans += S[2];
    FOR(i, 0, 26) CNT[0][i] -= CNT[1][i] * mx1 + CNT[2][i] * mx2;
    FOR(i, 0, 26) {
        while (CNT[0][i] > 0) {
            --CNT[0][i];
            ans += (i + 'a');
        }
    }
    cout << ans << endl;
    return 0;
}