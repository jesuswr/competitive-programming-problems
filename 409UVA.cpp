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
const int MAXN = 23; // CAMBIAR ESTE

// GJNM
int N, M;
string KEY[MAXN], EXC[MAXN], EXC2[MAXN];
int CNT[MAXN];

int main() {
    int t = 0;
    while (scanf("%d %d\n", &N, &M) != EOF) {
        FOR(i, 0, N) cin >> KEY[i];
        dadsadasda = scanf("%*c");
        FOR(i, 0, M) {
            getline(cin, EXC[i]);
            EXC2[i] = EXC[i];
            CNT[i] = 0;
            for (auto &c : EXC[i]) if (isalpha(c)) c = tolower(c);
            EXC[i] = "A " + EXC[i] + " A";
        }
        int mx = 0;
        FOR(i, 0, N) FOR(j, 0, M) FOR(k, 2, SZ(EXC[j]) - 2) {
            if (!EXC[j].compare(k, SZ(KEY[i]), KEY[i]) && !isalpha(EXC[j][k - 1]) && !isalpha(EXC[j][ k + SZ(KEY[i]) ])) {
                ++CNT[j];
            }
            mx = max(mx, CNT[j]);
        }
        cout << "Excuse Set #" << ++t << endl;
        FOR(i, 0, M) if (mx == CNT[i]) cout << EXC2[i] << endl;
        cout << endl;
    }

    return 0;
}