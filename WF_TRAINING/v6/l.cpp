#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
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
const int MOD = 1e9+7;
const int MAXN = 2e6+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
string A, B;
struct STN{
	int sm, mn_prf;
    void merge(STN& L, STN& R) {
		sm = L.sm + R.sm;
		mn_prf = min(L.mn_prf, L.sm + R.mn_prf);
	}
    void operator=(char c) {
		sm = mn_prf = (c == '(' ? 1 : -1);
	}
};
STN ST[4*MAXN];
void STB(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        ST[id] = A[l];
        return;
    }
    int m = (l+r)>>1, L = id<<1, R = L|1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
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

vi preff(string &s){
    int n = s.length();
    vi P(n);
    FOR(i,1,n){
        int j = P[i-1];
        while(j>0 && s[i]!=s[j]) j = P[j-1];
        j += s[i] == s[j];
        P[i] = j;
    }
    return P;
}

bool BAD[MAXN];
vi KMP(string &s, string &t){
    int n = s.length();
    int m = t.length();
    int j = 0;
    vi P = preff(t), ans;
    FOR(i,0,n){
        while(j>0 && s[i]!=t[j]) j = P[j-1];
        j += s[i] == t[j];
        if(j==m) BAD[i-m+1] = 1, j = P[j-1];
    }
    return ans;
}



int main(){
	cin >> B;
	A = B + B;
	N = sz(A);
	STB();
	KMP(A,B);
	FOR(i,1,N/2) if (!BAD[i]) {
		auto stn = STQ(i, i + N / 2);
		if (stn.sm == 0 && stn.mn_prf >= 0) {
			FOR(j,i,i+N/2) printf("%c", A[j]);
			printf("\n");
			return 0;
		}
	}
	printf("no\n");
	return 0;
}
