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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int A[69];


void upd(const vi &moves) {
    vector<vi> hola;
    int i = 0;
    for (auto sz : moves) {
        vi aux;
        while (sz--)aux.pb(A[i++]);
        hola.pb(aux);
    }
    reverse(ALL(hola));
    i = 0;
    for (auto aux : hola)
        for (auto ai : aux) A[i++] = ai;
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    vector<vi> ans;
    FOR(_, 0, N) {
        // FOR(i, 0, N) printf("%d ", A[i]);
        // printf("\n");
        int lst = 0, i = 0, j = 69;
        while (i < N && A[i] == lst + 1) ++i, ++lst;
        if (i == N)
            continue;
        vi move;
        if (A[0] == 1) {
            int ii = i;
            while (A[ii + 1] == A[ii] + 1)++ii;
            FOR(k, 0, N) if (A[k] == A[i] - 1) j = k;
            // printf("%d (%d) %d (%d) %d (%d)\n", i, A[i], ii, A[ii], j, A[j]);
            if (i > 0)
                move.pb(i);
            move.pb(ii - i + 1);
            move.pb(j - ii);
            if (N - 1 - j > 0)
                move.pb(N - 1 - j);
        }
        else {
            FOR(k, 0, N) if (A[k] == A[0] - 1) j = k;
            i = 0;
            while (A[i + 1] == A[i] + 1)i++;
            move.pb(i + 1);
            move.pb(j - i);
            if (N - 1 - j > 0)
                move.pb(N - 1 - j);
        }
        ans.pb(move);
        upd(move);
        // FOR(i, 0, N) printf("%d ", A[i]);
        // printf("\n");
    }
    printf("%d\n", SZ(ans));
    for (auto moves : ans) {
        printf("%d", SZ(moves));
        for (auto sz : moves) printf(" %d", sz);
        printf("\n");
    }
    return 0;
}