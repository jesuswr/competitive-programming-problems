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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM

int main() {
    int rank = 25, streak = 0, stars = 0;
    string s; cin >> s;
    for (auto x : s) {
        if (x == 'W') {
            ++stars, ++streak;
            if (streak >= 3 && rank >= 6) ++stars;
            if (rank >= 21) {
                if (stars > 2) {
                    stars -= 2;
                    --rank;
                }
            }
            else if (rank >= 16) {
                if (stars > 3) {
                    stars -= 3;
                    --rank;
                }
            }
            else if (rank >= 11) {
                if (stars > 4) {
                    stars -= 4;
                    --rank;
                }
            }
            else {
                if (stars > 5) {
                    stars -= 5;
                    --rank;
                }
            }
        }
        else {
            streak = 0;
            if (rank <= 20) {
                stars = stars - 1;
                if (stars == -1 && rank != 20) {
                    ++rank;
                    if (rank >= 16) stars = 2;
                    else if (rank >= 11) stars = 3;
                    else stars = 4;
                }
                else stars = max(stars, 0);
            }
        }
        if (rank == 0) {
            printf("Legend\n");
            exit(0);
        }
    }
    printf("%d\n", rank);
    return 0;
}