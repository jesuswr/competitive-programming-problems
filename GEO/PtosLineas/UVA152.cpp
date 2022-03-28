#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct PTO {
    int x, y, z;
    void read() {
        ri(x), rii(y, z);
    }
    bool valid() {
        return max({x, y, z}) > 0;
    }
    PTO operator-(PTO p) {
        return {x - p.x, y - p.y, z - p.z};
    }
    int abs() {
        return sqrt(x * x + y * y + z * z);
    }
};
int N;
PTO P[5010];
int CNT[20];

int main() {
    while (P[N].read(), P[N].valid()) ++N;

    FOR(i, 0, N) {
        int mn = 15;
        FOR(j, 0, N) if (i != j) {
            mn = min(mn, (P[i] - P[j]).abs());
        }
        CNT[mn]++;
    }

    FOR(i, 0, 10) {
        if (CNT[i] < 10) printf("   ");
        else if (CNT[i] < 100) printf("  ");
        else if (CNT[i] < 1000) printf(" ");
        printf("%d", CNT[i]);
    }
    printf("\n");
    return 0;
}
