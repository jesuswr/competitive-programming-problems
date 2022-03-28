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
const int MAXN = 200 + 5;


string to_bin(int x) {
    string ret;
    while (x > 0) {
        ret.pb('0' + (x & 1));
        x >>= 1;
    }
    reverse(all(ret));
    return ret;
}
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int is_on(int x, int b) {
    return (x >> b) & 1;
}



int N;
int A[MAXN];
void inp() {
    ri(N);
    FOR(i, 0, N) {
        int aux; ri(aux);
        A[1 + i] |= (aux << 0);
    }
    FOR(i, 0, N + 1) {
        int aux; ri(aux);
        if (i == 0) A[1 + i] |= (aux << 1);
        else if (i == N) A[1 + i - 1] |= (aux << 2);
        else {
            A[1 + i - 1] |= (aux << 2);
            A[1 + i] |= (aux << 1);
        }
    }
    FOR(i, 0, N) {
        int aux; ri(aux);
        A[1 + i] |= (aux << 3);
    }
    FOR(i, 0, N + 1) {
        int aux; ri(aux);
        if (i == 0) A[1 + i] |= (aux << 4);
        else if (i == N) A[1 + i - 1] |= (aux << 5);
        else {
            A[1 + i - 1] |= (aux << 5);
            A[1 + i] |= (aux << 4);
        }
    }
    FOR(i, 0, N) {
        int aux; ri(aux);
        A[1 + i] |= (aux << 6);
    }
    FOR(i, 0, N + 1) {
        int aux; ri(aux);
        if (i == 0) A[1 + i] |= (aux << 7);
        else if (i == N) A[1 + i - 1] |= (aux << 8);
        else {
            A[1 + i - 1] |= (aux << 8);
            A[1 + i] |= (aux << 7);
        }
    }
    FOR(i, 0, N) {
        int aux; ri(aux);
        A[1 + i] |= (aux << 9);
    }
    FOR(i, 0, N + 1) {
        int aux; ri(aux);
        if (i == 0) A[1 + i] |= (aux << 10);
        else if (i == N) A[1 + i - 1] |= (aux << 11);
        else {
            A[1 + i - 1] |= (aux << 11);
            A[1 + i] |= (aux << 10);
        }
    }
    FOR(i, 0, N) {
        int aux; ri(aux);
        A[1 + i] |= (aux << 12);
    }
}
int MSK[10] = {0b1110111, 0b0100100, 0b1011101, 0b1101101, 0b0101110, 0b1101011, 0b1111011, 0b0100101, 0b1111111, 0b1101111};

int get_l(int msk) {
    return ( is_on(msk, 1) + 2 * is_on(msk, 4) + 4 * is_on(msk, 7) + 8 * is_on(msk, 10) );
}

int get_m(int msk) {
    return ( is_on(msk, 0) + 2 * is_on(msk, 3) + 4 * is_on(msk, 6) + 8 * is_on(msk, 9) + 16 * is_on(msk, 12) );
}

int get_r(int msk) {
    return ( is_on(msk, 2) + 2 * is_on(msk, 5) + 4 * is_on(msk, 8) + 8 * is_on(msk, 11) );
}

vi get_nexts(int msk, int subm) {
    vi ret;
    FOR(i, 0, 16) if (msk == (subm | i)) {
        ret.pb(i);
    }
    return ret;
}
vi X[3];
void answer() {
    FOR(i, 0, 3) reverse(all(X[i]));
    FOR(i, 0, 3) {
        for (auto x : X[i]) printf("%d", x);
        printf("\n");
    }
    exit(0);
}

bool VIS[110][16][2];
void dfs(int p, int msk, int carry) {
    if (p == 0) {
        if (msk == 0 && carry == 0)
            answer();
        else
            return;
    }
    if (VIS[p][msk][carry]) return;
    VIS[p][msk][carry] = 1;
    for (int d1 = 0; d1 <= 9; ++d1) {
        for (int d2 = 0; d2 <= 9; ++d2) {
            int d3 = (d1 + d2 + carry) % 10;
            int n_msk = MSK[d1] | (MSK[d2] << 3) | (MSK[d3] << 6);
            if (get_r(n_msk) != msk) continue;
            if (get_m(n_msk) != get_m(A[p])) continue;
            for (int next_msk : get_nexts(get_l(A[p]), get_l(n_msk))) {
                X[0].pb(d1);
                X[1].pb(d2);
                X[2].pb(d3);
                dfs(p - 1, next_msk, (d1 + d2 + carry) / 10);
                X[0].pop_back();
                X[1].pop_back();
                X[2].pop_back();
            }
        }
    }
}


int main() {
    freopen("digital.in", "r", stdin);
    freopen("digital.out", "w", stdout);
    inp();
    dfs(N, get_r(A[N]), 0);
    printf("NO\n");
    return 0;
}
