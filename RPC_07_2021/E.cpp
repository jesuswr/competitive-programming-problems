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
const int MAXN = 15; // CAMBIAR ESTE

// GJNM
int MP[1000]; char INVMP[1000];
void pre() {
    int aux = 0;
    for (char a = 'A'; a <= 'Z'; ++a)
        MP[(int)a] = aux++;
    for (char a = '0'; a <= '9'; ++a)
        MP[(int)a] = aux++;
    MP[(int)' '] = aux++;

    aux = 0;
    for (char a = 'A'; a <= 'Z'; ++a)
        INVMP[aux++] = a;
    for (char a = '0'; a <= '9'; ++a)
        INVMP[aux++] = a;
    INVMP[aux++] = ' ';
}


int N;
int MAT[MAXN][MAXN];
string A;

int M;
vector< vector<int> > IN, OUT;

void mult(vector<int> &in, vector<int> &out) {
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            out[i] += MAT[i][j] * in[j];
        }
    }
    FOR(i, 0, N) out[i] %= 37;
}

int main() {
    pre();

    ri(N);
    FOR(i, 0, N) FOR(j, 0, N) ri(MAT[i][j]);
    getline(cin, A);
    getline(cin, A);

    M = -1;
    FOR(i, 0, SZ(A)) {
        if (i % N == 0) {
            IN.emplace_back();
            OUT.emplace_back();
            M++;
        }
        OUT[M].pb(0);
        IN[M].pb(MP[(int)A[i]]);
    }
    while (IN[M].size() % N != 0) {
        OUT[M].pb(0);
        IN[M].pb(MP[(int)' ']);
    }
    M++;

    FOR(i, 0, M) {
        //for (auto x : IN[i]) cout << x << " ";
        //cout << endl;;

        mult(IN[i], OUT[i]);
    }

    string ANS;
    FOR(i, 0, M) for (auto x : OUT[i]) ANS.pb(INVMP[x]);
    cout << ANS << endl;
    return 0;
}