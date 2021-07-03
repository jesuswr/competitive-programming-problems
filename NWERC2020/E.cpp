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
#include <time.h>
#include <stdlib.h>     /* srand, rand */

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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N;
int AX, AY;
int BX, BY;
int DX[MAXN], DY[MAXN];
set<pii> st;

bool valid(int x, int y) {
    return min(x, y) >= 1 && max(x, y) <= N;
}

void check_alice() {
    FOR(i, 0, N) {
        int x = AX + DX[i], y = AY + DY[i];
        if (valid(x, y)) {
            if (st.find({BX - x, BY - y}) != st.end()) {
                printf("Alice wins\n");
                exit(0);
            }
        }
    }
}

void brute_force() {
    set<pii> pos;
    pos.insert({BX, BY});

    FOR(i, 0, N) {
        int x = BX + DX[i], y = BY + DY[i];
        if (!valid(x, y))
            continue;
        pos.insert({x, y});
        FOR(j, 0, N) {
            int x2 = x + DX[j], y2 = y + DY[j];
            if (valid(x2, y2))
                pos.insert({x2, y2});
        }
    }

    if (SZ(pos) == N * N) {
        printf("Bob wins\n");
        exit(0);
    }
    else {
        FOR(i, 0, N) FOR(j, 0, N) {
            if (pos.find({i + 1, j + 1}) == pos.end()) {
                printf("tie %d %d\n", i + 1, j + 1);
                exit(0);
            }
        }
    }
}

void arrow() {
    srand (time(NULL));
    while (1) {
        int x = (rand() % N) + 1, y = (rand() % N) + 1;
        bool good = true;
        FOR(i, 0, N) {
            int xx = BX + DX[i], yy = BY + DY[i];
            if (valid(xx, yy)) {
                if (st.find({x - xx, y - yy}) != st.end()) {
                    good = false;
                }
            }
        }

        if (good) {
            printf("tie %d %d\n", x, y);
            exit(0);
        }
    }
}

int main() {
    ri(N);
    rii(AX, AY);
    rii(BX, BY);
    FOR(i, 0, N) {
        rii(DX[i], DY[i]);
        st.insert({DX[i], DY[i]});
    }
    st.insert({0, 0});


    check_alice();

    if (N <= 1000)
        brute_force();
    else
        arrow();

    return 0;
}