#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 400 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ii P[MAXN];

int main() {
    while (scanf("%d %d", &P[0].F, &P[0].S) == 2) {
        if (P[0].F == 0 && P[0].S == 0) break;
        int N = 1;
        while (scanf("%d %d", &P[N].F, &P[N].S) == 2) {
            if (P[N].F == 0 && P[N].S == 0) break;
            ++N;
        }
        sort(P, P + N);
        bool fnd = 0;
        FOR(fst, 0, N) FOR(snd, fst + 1, N) {
            int dx = P[snd].F - P[fst].F, dy = P[snd].S - P[fst].S;
            bool good = 1;
            FOR(i, 0, fst) {
                int nx = P[snd].F - P[i].F, ny = P[snd].S - P[i].S;
                if (dx * ny - dy * nx == 0) good = 0;
            }
            FOR(i, fst + 1, snd) {
                int nx = P[snd].F - P[i].F, ny = P[snd].S - P[i].S;
                if (dx * ny - dy * nx == 0) good = 0;
            }
            vector<int> inds;
            inds.pb(fst);
            inds.pb(snd);
            FOR(i, snd + 1, N) {
                int nx = P[snd].F - P[i].F, ny = P[snd].S - P[i].S;
                if (dx * ny - dy * nx == 0) inds.pb(i);
            }
            if (good && sz(inds) > 2) {
                if (!fnd) printf("The following lines were found:\n");
                fnd = 1;
                for (int j : inds) {
                    printf("(");
                    if (P[j].F < 1000) printf(" ");
                    if (P[j].F < 100) printf(" ");
                    if (P[j].F < 10) printf(" ");
                    printf("%d,", P[j].F);
                    if (P[j].S < 1000) printf(" ");
                    if (P[j].S < 100) printf(" ");
                    if (P[j].S < 10) printf(" ");
                    printf("%d)", P[j].S);
                }
                printf("\n");
            }
        }
        if (!fnd) printf("No lines were found\n");
    }
    return 0;
}
