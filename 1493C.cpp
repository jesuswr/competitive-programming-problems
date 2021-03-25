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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
const int ALPHA = 26;

// GJNM
int N, K;
string S;
int CNT[MAXN][ALPHA];

int main() {
    int t; ri(t);
    while (t--) {
        rii(N, K);
        cin >> S;
        if (N % K != 0) {
            printf("-1\n");
            continue;
        }
        FOR(i, 0, N) {
            FOR(a, 0, ALPHA) {
                CNT[i][a] = (S[i] - 'a' == a) + (i > 0 ? CNT[i - 1][a] : 0);
            }
        }

        bool good = true;
        FOR(a, 0, ALPHA) good &= CNT[N - 1][a] % K == 0;
        if (good) {
            cout << S << endl;
            continue;
        }

        int need[ALPHA];
        for (int i = N - 2; i >= -1; --i) {
            if (i >= 0)
                FOR(a, 0, ALPHA) need[a] = (K - (CNT[i][a] % K)) % K;
            else
                FOR(a, 0, ALPHA) need[a] = 0;
            int tot_need = 0;
            FOR(a, 0, ALPHA) tot_need += need[a];

            if (tot_need > N - 1 - i) continue;
            if (tot_need == N - 1 - i) {
                int nxt = -1;
                for (int a = ALPHA - 1; a >= 0; --a) if (need[a] > 0 && a > (S[i + 1] - 'a'))
                        nxt = a;
                if (nxt == -1) continue;
                S[i + 1] = 'a' + nxt;
                --need[nxt];
                good = true;
                break;
            }
            else {
                int nxt = -1;
                for (int a = ALPHA - 1; a >= 0; --a) if (need[a] > 0 && a > (S[i + 1] - 'a'))
                        nxt = a;
                int remaining = (N - 1 - i) - tot_need;
                if (nxt - 1 == S[i + 1] - 'a') {
                    S[i + 1] = nxt + 'a';
                    --need[nxt];
                    need[0] += remaining;
                    good = true;
                    break;
                }
                else if (S[i + 1] != 'z') {
                    S[i + 1] = S[i + 1] + 1;
                    --need[S[i + 1] - 'a'];
                    need[S[i + 1] - 'a'] = K - 1;
                    remaining -= K;
                    need[0] += remaining;
                    good = true;
                    break;
                }
            }
        }

        if (!good) {

        }
        else {
            for (int i = N - 1; i >= 0; --i) {
                int swp = -1;
                FOR(a, 0, ALPHA) if (need[a] > 0) swp = a;
                if (swp != -1) {
                    need[swp]--;
                    S[i] = swp + 'a';
                }
            }
            cout << S << endl;
        }


    }

    return 0;
}