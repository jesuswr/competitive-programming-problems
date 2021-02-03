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
const int MAXN = 4e5; // CAMBIAR ESTE

// GJNM
int N;
string S[2];
bool VIS[2][2][MAXN];
int CNT[2][2][MAXN];

void dfs(int dir, int k, int p) {
    VIS[dir][k][p] = true;
    int cnt = 1;
    if (dir == 0 && p > 0 && S[k][p - 1] == 'L') {
        if (!VIS[dir][1 ^ k][p - 1]) dfs(dir, 1 ^ k, p - 1);
        cnt += CNT[dir][1 ^ k][p - 1];
    }
    if (dir == 1 && p < N && S[k][p] == 'R') {
        if (!VIS[dir][1 ^ k][p + 1]) dfs(dir, 1 ^ k, p + 1);
        cnt += CNT[dir][1 ^ k][p + 1];
    }
    CNT[dir][k][p] = cnt;
    //printf("%d %d %d : %d\n", dir, k, p, CNT[dir][k][p]);
}

void solve() {
    ri(N);
    cin >> S[0];
    S[1].resize(N);
    FOR(i, 0, N) S[1][i] = (S[0][i] == 'L' ? 'R' : 'L');
    FOR(dir, 0, 2) FOR(k, 0, 2) FOR(i, 0, N + 1) VIS[dir][k][i] = false;
    FOR(dir, 0, 2) FOR(k, 0, 2) FOR(i, 0, N + 1) if (!VIS[dir][k][i]) dfs(dir, k, i);
    FOR(i, 0, N + 1) printf("%d ", CNT[0][0][i] + CNT[1][0][i] - 1);
    printf("\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}