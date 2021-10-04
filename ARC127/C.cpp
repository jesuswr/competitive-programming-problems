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
string S;
int fst_one;
void pre() {
    FOR(i, 0, SZ(S)) if (S[i] == '1') {
        fst_one = i;
        break;
    }
    S[fst_one] = '0';
    FOR(i, 0, fst_one) S[i] = '1';
    fst_one = INF;
    FOR(i, 0, SZ(S)) if (S[i] == '1') {
        fst_one = i;
        break;
    }
}
void subs() {
    S[fst_one] = '0';
    FOR(i, 0, fst_one) S[i] = '1';
    fst_one = INF;
    FOR(i, 0, SZ(S)) if (S[i] == '1') {
        fst_one = i;
        break;
    }
}


int main() {
    ri(N);
    cin >> S;
    reverse(ALL(S));
    pre();
    string ans = "1";
    for (int i = N ; i > 0; --i) {
        if (i - 1 < fst_one)
            break;
        if (SZ(S) > i - 1 && S[i - 1] == '1') {
            S[i - 1] = '0';
            ans.pb('1');
        }
        else {
            subs();
            ans.pb('0');
        }
    }
    cout << ans << endl;
    return 0;
}