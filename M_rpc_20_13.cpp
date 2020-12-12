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
int R, C;
int mn = INF, cnt = 0;

char inp[21][21];
int mat[21][21];

bool valid(int r, int c) {
    return min(r, c) >= 0 && c < C && r < R;
}

void check() {
    int bomb_cnt = 0;
    FOR(r, 0, R) {
        FOR(c, 0, C) {
            bomb_cnt += mat[r][c];
        }
    }
    if (bomb_cnt > mn)
        return;

    FOR(r, 0, R) {
        FOR(c, 0, C) {
            if (inp[r][c] == '.')
                continue;
            int need = inp[r][c] - '0';
            for (auto dr : {1, 0, -1}) {
                for (auto dc : {1, 0, -1}) {
                    if (dr == 0 && dc == 0)
                        continue;
                    if (valid(r + dr, c + dc) && mat[r + dr][c + dc])
                        need--;
                }
            }
            if (need != 0)
                return;
        }
    }

    if (bomb_cnt == mn)
        cnt++;
    else {
        mn = bomb_cnt;
        cnt = 1;
    }
}

void place(int r, int c) {
    if (c == C) {
        place(r + 1, 0);
        return;
    }
    if (r == R) {
        check();
        return;
    }

    if (inp[r][c] == '.') {
        mat[r][c] = 0;
        place(r, c + 1);
        mat[r][c] = 1;
        place(r, c + 1);
    }
    else
        place(r, c + 1);
}


int main() {
    rii(R, C);
    FOR(i, 0, R) {
        dadsadasda = scanf("%s", inp[i]);
    }
    place(0, 0);
    if (mn == INF)
        printf("0\n");
    else
        printf("%d %d\n", cnt, mn);
    return 0;
}