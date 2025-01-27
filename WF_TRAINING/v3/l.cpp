#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 100+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long T;
typedef vector<T> vd;
const T INF = INFLL;  // for maximum set INF to 0, and negate costs
bool zero(T x) { return x==0; }  // change to x==0, for ints/ll
struct Hungarian {
    int n;
    vector<vd> cs;
    vi L, R; // here are the matches
    Hungarian(int N, int M) : n(max(N, M)), cs(n, vd(n)), L(n), R(n) {
        FOR(x, 0, N) FOR(y, 0, M) cs[x][y] = INF;
    }
    void set(int x, int y, T c) { cs[x][y] = c; }
    T solve() {
        int mat = 0;
        vd ds(n), u(n), v(n);
        vi dad(n), sn(n);
        FOR(i, 0, n) u[i] = *min_element(all(cs[i]));
        FOR(j, 0, n) {
            v[j] = cs[0][j] - u[0];
            FOR(i, 1, n) v[j] = min(v[j], cs[i][j] - u[i]);
        }
        L = R = vi(n, -1);
        FOR(i, 0, n) FOR(j, 0, n)
            if (R[j] == -1 && zero(cs[i][j] - u[i] - v[j])) {
                L[i] = j;
                R[j] = i;
                mat++;
                break;
            }
        for (; mat < n; mat++) {
            int s = 0, j = 0, i;
            while (L[s] != -1) s++;
            fill(all(dad), -1);
            fill(all(sn), 0);
            FOR(k, 0, n) ds[k] = cs[s][k] - u[s] - v[k];
            for (;;) {
                j = -1;
                FOR(k, 0, n)
                    if (!sn[k] && (j == -1 || ds[k] < ds[j])) 
                        j = k;
                sn[j] = 1;
                i = R[j];
                if (i == -1) break;
                FOR(k, 0, n)
                    if (!sn[k]) {
                        auto new_ds = ds[j]+cs[i][k]-u[i]-v[k];
                        if (ds[k] > new_ds) {
                            ds[k] = new_ds;
                            dad[k] = j;
                        }
                    }
            }
            FOR(k, 0, n)
                if (k != j && sn[k]) {
                    auto w = ds[k] - ds[j];
                    v[k] += w;
                    u[R[k]] -= w;
                }
            u[s] += ds[j];
            while (dad[j] >= 0) {
                int d = dad[j];
                R[j] = R[d];
                L[R[j]] = j;
                j = d;
            }
            R[j] = s;
            L[s] = j;
        }
        T value = 0;
        FOR(i, 0, n) value += cs[i][L[i]];
        return value;
    }
};

int N,M;
int CNT[MAXN][MAXN]; // for each node, how much of one item it has
ll DST[MAXN][MAXN];
ll CST[MAXN][MAXN]; // for each node, how much it cost to get every item of a type

int main(){
	rii(N,M);
	FOR(i,0,N) FOR(j,0,M) ri(CNT[i][j]);
	FOR(i,0,N) FOR(j,0,N) {
		lri(DST[i][j]);
		if (DST[i][j] == -1) DST[i][j] = 1e14;
	}
	FOR(k,0,N) FOR(i,0,N) FOR(j,0,N) DST[i][j] = min(DST[i][j], DST[i][k] + DST[k][j]); 

	FOR(i,0,N) FOR(j,0,N) FOR(k,0,M) CST[j][k] += DST[i][j] * CNT[i][k];

	Hungarian h(N,M);
	FOR(i,0,N) FOR(j,0,M) h.set(i,j,CST[i][j]);
	printf("%lld\n", h.solve());


	return 0;
}
