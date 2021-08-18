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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int N;
int CNT[30];
string S, T;

bool all_eq() {
    FOR(i, 0, 30) if (CNT[i] == N) {
        cout << S << endl;
        return true;
    }
    return false;
}

bool one_oc() {
    FOR(i, 0, 30) if (CNT[i] == 1) {
        printf("%c", 'a' + i);
        FOR(j, 0, i) FOR(_, 0, CNT[j]) printf("%c", 'a' + j);
        FOR(j, i + 1, 30) FOR(_, 0, CNT[j]) printf("%c", 'a' + j);
        printf("\n");
        return true;
    }
    return false;
}

int get_smallest() {
    FOR(i, 0, 30) if (CNT[i] > 0)
        return i;
}

int get_dif() {
    int ret = 0;
    FOR(i, 0, 30) ret += CNT[i] > 0;
    return ret;
}

void solve() {
    cin >> S;
    N = SZ(S);
    FOR(i, 0, 30) CNT[i] = 0;
    FOR(i, 0, N) CNT[S[i] - 'a']++;

    if (all_eq())
        return;
    if (one_oc())
        return;
    int sm = get_smallest();

    if (CNT[sm] - 2 <= N - CNT[sm]) {
        printf("%c%c", 'a' + sm, 'a' + sm);
        CNT[sm] -= 2;
        N -= 2;
        while (N > 0) {
            FOR(j, sm + 1, 30) if (CNT[j]) {
                printf("%c", j + 'a');
                CNT[j]--;
                N--;
                break;
            }
            if (CNT[sm] > 0) {
                printf("%c", sm + 'a');
                CNT[sm]--;
                N--;
            }
        }
        printf("\n");
    }
    else {
        int dif = get_dif();
        if (dif == 2) {
            printf("%c", 'a' + sm);
            FOR(i, sm + 1, 30) FOR(_, 0, CNT[i]) printf("%c", 'a' + i);
            FOR(_, 1, CNT[sm]) printf("%c", 'a' + sm);
        }
        else {
            int sm2, sm3;
            FOR(i, sm + 1, 30)if (CNT[i] > 0) {
                sm2 = i;
                break;
            }
            FOR(i, sm2 + 1, 30)if (CNT[i] > 0) {
                sm3 = i;
                break;
            }
            printf("%c%c", 'a' + sm, 'a' + sm2);
            CNT[sm]--; CNT[sm2]--;
            FOR(i, 0, CNT[sm]) printf("%c", 'a' + sm);
            printf("%c", 'a' + sm3);
            CNT[sm3]--;
            FOR(i, sm2, 30) FOR(_, 0, CNT[i]) printf("%c", 'a' + i);
        }
        printf("\n");
    }
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}