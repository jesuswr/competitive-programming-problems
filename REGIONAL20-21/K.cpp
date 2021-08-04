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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int N, K;
char TMP[5];
vi REC[MAXN];
int CNT[43046721];
int POW[10];
int T = 1;

void upd(int ind, int val) {
    vi hashes;
    FOR(i, 0, K) {
        int m = SZ(hashes);
        FOR(j, 0, m) {
            FOR(k, 1, REC[ind][i] + 1) {
                hashes.pb(hashes[j] + k * POW[i]);
            }
        }
        FOR(k, 1, REC[ind][i] + 1) {
            hashes.pb(k * POW[i]);
        }
    }

    for (auto h : hashes)
        CNT[h] += val;
}

void solve(vi rec) {
    int hash = 0;
    FOR(i, 0, K) {
        hash += rec[i] * POW[i];
    }
    printf("%d\n", CNT[hash]);
}

int main() {
    POW[0] = 1;
    FOR(i, 1, 9) POW[i] = POW[i - 1] * 9;

    rii(N, K);
    FOR(i, 1, N + 1) {
        dadsadasda = scanf("%s", TMP);
        if (TMP[0] == 'C') {
            int m; ri(m);
            REC[T].resize(K);
            FOR(_, 0, m) {
                int aux; ri(aux);
                REC[T][aux - 1]++;
            }
            upd(T, 1);
            T++;
        }
        else if (TMP[0] == 'D') {
            int aux; ri(aux);
            upd(aux, -1);
        }
        else {
            int m; ri(m);
            vi rec(K);
            FOR(_, 0, m) {
                int aux; ri(aux);
                rec[aux - 1]++;
            }
            solve(rec);
        }
    }

    return 0;
}