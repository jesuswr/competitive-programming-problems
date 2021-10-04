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
const int MAXN = 510; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
string TXT, PAT;


int NXT[MAXN][2];
void pre() {
    vi pi(M + 1);
    FOR(i, 1, M) {
        int j = pi[i - 1];
        while (j > 0 && PAT[j] != PAT[i]) j = pi[j - 1];
        if (PAT[j] == PAT[i]) pi[i] = j + 1;
    }
    FOR(p, 0, M + 1) {
        FOR(c, 0, 2) {
            int j = p;
            while (PAT[j] != ('0' + c) && j > 0) j = pi[j - 1];
            if (PAT[j] == ('0' + c)) NXT[p][c] = j + 1;
        }
    }
}

int DP[2][MAXN][MAXN];


int main() {
    FOR(i, 0, 2) FOR(j, 0, MAXN) FOR(k, 0, MAXN) DP[i][j][k] = INF;
    rii(N, M);
    cin >> TXT >> PAT;
    PAT.pb('$');
    pre();
    FOR(p, 0, M + 1) DP[N & 1][p][0] = 0;

    for (int i = N - 1; i >= 0; --i) FOR(p, 0, M + 1) FOR(k, 0, N - M + 2) {
        int curr = i & 1, prev = ~i & 1;
        DP[curr][p][k] = INF;
        FOR(c, 0, 2) {
            int np = NXT[p][c];
            if (np != M || k > 0)
                DP[curr][p][k] = min(DP[curr][p][k], DP[prev][np][k - (np == M)] + (c != (TXT[i] - '0')));
        }
    }
    FOR(i, 0, N - M + 2) {
        if (DP[0][0][i] != INF)
            printf("%d ", DP[0][0][i]);
        else
            printf("-1 ");
    }
    printf("\n");
    return 0;
}