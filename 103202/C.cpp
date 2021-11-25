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
#define rii(a,b) dadsadasda=scanf("%d %d\n", &a, &b)
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
const int MAXN = 1e6 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;

int CONC[MAXN];
int NEED[MAXN];
vi TO[MAXN];
int T[MAXN];

void conflict() {
    printf("conflict\n");
    exit(0);
}

int main() {
    memset(T, -1, sizeof(T));
    rii(N, M);
    FOR(i, 1, N + 1) {
        string s; getline(cin, s);
        vi aux;
        int j = 0;
        while (j < SZ(s)) {
            if (s[j] == '!' || (s[j] >= '0' && s[j] <= '9')) {
                bool minus = false;
                if (s[j] == '!') {
                    minus = 1;
                    ++j;
                }
                int x = 0;
                while (j < SZ(s) && (s[j] >= '0' && s[j] <= '9')) {
                    x = 10 * x + (s[j] - '0');
                    ++j;
                }
                if (minus)
                    x = -x;
                aux.pb(x);
            }
            ++j;
        }
        CONC[i] = aux.back();
        aux.pop_back();
        NEED[i] = SZ(aux);
        for (auto x : aux) TO[x].pb(i);
    }

    vi c;
    FOR(i, 1, N + 1) if (NEED[i] == 0) {
        int t = CONC[i] > 0;
        if (T[abs(CONC[i])] != -1 && T[abs(CONC[i])] != t)
            conflict();
        if (T[abs(CONC[i])] == -1)
            c.pb(abs(CONC[i]));
        T[abs(CONC[i])] = t;
    }

    FOR(i, 0, SZ(c)) if (T[c[i]] == 1) {
        for (auto j : TO[c[i]]) {
            --NEED[j];
            if (NEED[j] == 0) {
                int t = CONC[j] > 0;
                if (T[abs(CONC[j])] != -1 && T[abs(CONC[j])] != t)
                    conflict();
                if (T[abs(CONC[j])] == -1)
                    c.pb(abs(CONC[j]));
                T[abs(CONC[j])] = t;
            }
        }
    }
    FOR(i, 1, M + 1) {
        if (T[i] > 0) printf("T");
        else printf("F");
    }
    printf("\n");



    return 0;
}