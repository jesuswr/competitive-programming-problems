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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
char S[5010], T[5010];
int DP[5010][5010];

int main() {
    scanf("%s", S); N = strlen(S);
    scanf("%s", T); M = strlen(T);
    for (int i = N; i >= 0; --i) {
        for (int j = M; j >= 0; --j) {
            if (i == N && j == M)
                continue;
            DP[i][j] = INF;
            if (i < N && j < M)
                DP[i][j] = min(DP[i][j], DP[i + 1][j + 1] + (S[i] != T[j]));
            if (i < N)
                DP[i][j] = min(DP[i][j], DP[i + 1][j] + 1);
            if (j < M)
                DP[i][j] = min(DP[i][j], DP[i][j + 1] + 1);
        }
    }
    printf("%d\n", DP[0][0]);
    return 0;
}