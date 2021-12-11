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
const int MAXN = 769; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

string A[MAXN];

int main() {
    int n, m;
    rii(n, m);
    FOR(i, 0, n) cin >> A[i];

    FOR(i, 0, n) FOR(j, 0, m) if (A[i][j] == '.') {
        for (auto c : "12345") {
            bool good = 1;
            for (auto di : {1, 0, -1}) for (auto dj : {1, 0, -1}) {
                    if (abs(di) != abs(dj) && i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m) {
                        if (A[i + di][j + dj] == c)
                            good = false;
                    }
                }
            if (good) {
                A[i][j] = c;
                break;
            }
        }
    }
    FOR(i, 0, n) cout << A[i] << endl;
    return 0;
}