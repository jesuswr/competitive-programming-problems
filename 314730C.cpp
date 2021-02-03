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
const int MAXN = 260; // CAMBIAR ESTE

// GJNM
int N, M;
string S[MAXN];
bool CAN[MAXN][MAXN][MAXN];
vi OPTS[MAXN][MAXN];


int main() {
    rii(N, M);
    FOR(i, 0, N) cin >> S[i];
    FOR(i, 0, N) FOR(j, 0, M) {
        vi cnt(26);
        int odd = 0;
        FOR(k, j, M) {
            int c = S[i][k] - 'a';
            if (cnt[c] & 1) odd--;
            cnt[c]++;
            if (cnt[c] & 1) odd++;
            CAN[i][j][k - j + 1] = odd < 2;
            if (CAN[i][j][k - j + 1]) {
                OPTS[i][j].pb(k - j + 1);
            }
        }
    }
    int ans = 0;
    FOR(l, 1, M + 1) {
        FOR(j, 0, M) {
            int carry = 0;
            FOR(i, 0, N) {
                if (CAN[i][j][l]) carry++;
                else carry = 0;
                ans += carry;
            }
        }
        printf("%d : %d\n", l, ans);
    }
    printf("%d\n", ans);
    return 0;
}