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

void NO() {
    printf("-1\n");
    exit(0);
}

// GJNM
int n, m;
set<int> G[MAXN];
int used[MAXN];
set<int> sets[3];


int main() {
    rii(n, m);
    FOR(i, 0, m) {
        int a, b; rii(a, b); a--, b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    FOR(s, 0, 3) {
        int head = -1;
        FOR(i, 0, n) {
            if (!used[i])
                head = i;
        }
        if (head == -1)
            NO();
        FOR(i, 0, n) {
            if (G[head].find(i) == G[head].end() && used[i] == 0)
                used[i] = s + 1;
            else if (G[head].find(i) == G[head].end() && used[i] != 0)
                NO();

        }
    }
    int s[3] = {0, 0, 0};
    FOR(i, 0, n) {
        if (used[i] == 0)
            NO();
        s[used[i] - 1]++;
        sets[used[i] - 1].insert(i);
    }
    if (m != s[0] * s[1] + s[1] * s[2] + s[2] * s[0])
        NO();

    FOR(i, 0, 3) {
        for (auto x : sets[i]) { 
            for (auto y : sets[(i + 1) % 3]) {
                if (G[x].find(y) == G[x].end())
                    NO();
            }
        }
    }


    FOR(i, 0, n) {
        printf("%d ", used[i]);
    } printf("\n");

    return 0;
}