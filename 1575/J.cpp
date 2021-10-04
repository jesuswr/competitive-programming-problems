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
const int MAXN = 1010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M, K;
int MAT[MAXN][MAXN];
int DX[3] = {0, 1, 0};
int DY[3] = {1, 0, -1};

int main() {
    riii(N, M, K);
    FOR(i, 0, N) FOR(j, 0, M) ri(MAT[i][j]), MAT[i][j]--;
    vi cnt(M, 0);
    FOR(i, 0, N) FOR(j, 0, M) cnt[j] += MAT[i][j] == 1;
    while (K--) {
        int x = 0, y; ri(y); y--;
        if (cnt[y] == N)
            printf("%d ", y + 1);
        else {
            while (x < N) {
                if (MAT[x][y] != 1)
                    cnt[y]++;
                int aux = MAT[x][y];
                MAT[x][y] = 1;
                x += DX[aux], y += DY[aux];
            }
            printf("%d ", y + 1);
        }
    }
    printf("\n");
    return 0;
}