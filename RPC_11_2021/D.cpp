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
int N, M;
string MAT[MAXN];
int D[MAXN][MAXN];
vii TO[MAXN][MAXN];
string S;

bool valid(int x, int y) {
    return min(x, y) >= 0 && x < N && y < M && MAT[x][y] != '#';
}
pii f(int x, int y) {
    if (D[x][y] >= SZ(S))
        return { -3, -3};
    if (S[D[x][y]] == 'N')
        return { -1, 0};
    if (S[D[x][y]] == 'S')
        return { 1, 0};
    if (S[D[x][y]] == 'E')
        return {0, 1};
    if (S[D[x][y]] == 'W')
        return {0, -1};
}

void pre() {
    int x = 0, y = 0;
    FOR(i, 0, N) FOR(j, 0, M) if (MAT[i][j] == 'S') {
        x = i;
        y = j;
    }
    FOR(i, 0, N) FOR(j, 0, M) D[i][j] = INF;
    queue<pii> ord;
    ord.push({x, y});
    D[x][y] = 0;

    while (!ord.empty()) {
        auto [a, b] = ord.front();
        ord.pop();
        for (auto da : {1, 0, -1}) for (auto db : {1, 0, -1}) {
                if (abs(da) != abs(db) && valid(a + da, b + db) && D[a + da][b + db] > D[a][b] + 1) {
                    ord.push({a + da, b + db});
                    D[a + da][b + db] = D[a][b] + 1;
                }
            }
    }

    // FOR(i, 0, N) {
    //     FOR(j, 0, M) printf("%d ", D[i][j]);
    //     printf("\n");
    // }

    FOR(a, 0, N) {
        FOR(b, 0, M) {
            if (D[a][b] > M * N) continue;
            for (auto da : {1, 0, -1}) for (auto db : {1, 0, -1}) {
                    if (abs(da) != abs(db) && valid(a + da, b + db)) {
                        if (D[a + da][b + db] == D[a][b] + 1 && make_pair(da, db) != f(a, b)) {
                            // printf("%d %d -> %d %d\n", a, b, a + da, b + db);
                            TO[a][b].pb({da, db});
                        }
                    }
                }
        }
    }


    FOR(i, 0, N) FOR(j, 0, M) D[i][j] = 1e9 + 69;
    ord.push({x, y});
    D[x][y] = 0;

    while (!ord.empty()) {
        auto [a, b] = ord.front();
        ord.pop();
        for (auto [da, db] : TO[a][b]) {
            if (abs(da) != abs(db) && valid(a + da, b + db) && D[a + da][b + db] > D[a][b] + 1) {
                ord.push({a + da, b + db});
                D[a + da][b + db] = D[a][b] + 1;
            }
        }
    }
    // FOR(i, 0, N) {
    //     FOR(j, 0, M) printf("%d ", D[i][j]);
    //     printf("\n");
    // }
    FOR(i, 0, N) FOR(j, 0, M) if (SZ(S) == D[i][j])
        MAT[i][j] = '!';
}

int main() {
    rii(M, N);
    FOR(i, 0, N) cin >> MAT[i];
    cin >> S;
    pre();

    FOR(i, 0, N) cout << MAT[i] << endl;
    return 0;
}