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
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 998244353;
const int MAXN = 4e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, Q;
string S;
struct STN{
	int ans;
    void merge(STN& L, STN& R) {
		ans = (1ll * L.ans * R.ans) % MOD;
	}
    void operator=(int a) {
		ans = a;
	}
};
STN ST[4*MAXN];
STN STQ(int x, int y, int id = 1, int l = 0, int r = N){
    if(x == l && y == r) return ST[id];
    int m = (l+r)>>1, L = id<<1, R = L|1;
    if(x >= m) return STQ(x, y, R, m, r);
    if(y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, int x, int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        ST[id] = x;
        return;
    }
    int m = (l+r)>>1, L = id<<1, R = L|1;
    if(p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}


int main(){
	fastIO();
	cin >> N >> Q;
	cin >> S;
	FOR(i,0,N) {
		if (S[i] == '?') STU(i, i);
		else STU(i,1);
	}
	cout << ST[1].ans << endl;
	while(Q--) {
		int i; char c;
		cin >> i >> c;
		--i;
		S[i] = c;
		if (S[i] == '?') STU(i, i);
		else STU(i,1);
		cout << ST[1].ans << endl;
	}
	return 0;
}
