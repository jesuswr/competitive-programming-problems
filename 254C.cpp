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
#include <fstream>

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
string A, B;
int CNTA[3000], CNTB[3000];

int get_sm() {
    int ret = 0;
    for (int i = 25; i >= 0; --i) if (CNTB[i] > CNTA[i]) ret = i;
    return ret;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> A;
    cin >> B;
    for (auto c : A) ++CNTA[c - 'A'];
    for (auto c : B) ++CNTB[c - 'A'];

    int cnt = 0;
    FOR(i, 0, SZ(A)) {
        int c = A[i] - 'A';
        if (CNTA[c] <= CNTB[c]) {
            --CNTA[c];
            --CNTB[c];
        }
        else if (CNTB[c] == 0) {
            int sm = get_sm();
            A[i] = sm + 'A';
            ++cnt;
            --CNTA[c];
            --CNTB[sm];
        }
        else {
            int sm = get_sm();
            if (sm < c) {
                A[i] = sm + 'A';
                ++cnt;
                --CNTB[sm];
                --CNTA[c];
            }
            else {
                --CNTB[c];
                --CNTA[c];
            }
        }
    }
    cout << cnt << endl;
    cout << A << endl;

    return 0;
}