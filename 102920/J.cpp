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
#include <bitset>

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
bitset<1002> A[501];
bitset<501> MAT[501];
void inv_mat() {
    FOR(row, 0, N) {
        FOR(aux, row, N) if (A[aux][row]) {
            if (aux != row)
                swap(A[aux], A[row]);
            break;
        }
        if (!A[row][row]) {
            printf("-1\n");
            exit(0);
        }
        FOR(i, 0, N) if (i != row && A[i][row]) {
            A[i] ^= A[row];
        }
    }
    FOR(i, 0, N) FOR(j, 0, N)MAT[i][j] = A[i][N + j];
}


int trash;
int main() {
    ri(N);
    FOR(i, 0, N) FOR(j, 0, N) {
        ri(trash);
        A[j][i] = trash;
    }
    FOR(i, 0, N) A[i][N + i] = 1;
    inv_mat();

    FOR(i, 0, N) {
        FOR(j, 0, N) if (MAT[j][i]) printf("%d ", j + 1);
        printf("\n");
    }

    return 0;
}