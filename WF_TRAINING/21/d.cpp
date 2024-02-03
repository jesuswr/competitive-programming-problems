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
#define rii(a,b) das=ri(a), ri(b)
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
const int MAXN = 101;
const int MAXLEN = 1e5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
string P;
string A[MAXN];

void pre() {
	A[0] = "0";
	A[1] = "1";
	FOR(i,2,MAXN) {
		int mn = min(sz(A[i-1]), sz(A[i-2]));
		if (mn == 0 || mn > MAXLEN) continue;
		A[i] = A[i-1] + A[i-2];
	}
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

int kmp(const string &b, const string &a) {
	string s = a + "$" + b;
	int na = sz(a), n = sz(s);
	vi pi(n);
	int cnt = 0;
	FOR(i,1,n) {
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j]) j = pi[j-1];
		j += s[i] == s[j];
		pi[i] = j;
		if (i > na && pi[i] == na) cnt++;
	}
	return cnt;
}

ll DP[MAXN];
ll go(int x) {
	if (DP[x] != -1) return DP[x];
	if (!A[x].empty()) return DP[x] = kmp(A[x], P);
	else {
		int l = x-1, r = x-2;
		while(A[l].empty()) l -= 2;
		while(A[r].empty()) r -= 1;
		return DP[x] = kmp(A[l] + A[r], P) - go(l) - go(r) + go(x-1) + go(x-2);
	}
}


int main(){
	pre();
	int t = 1;
	while(scanf("%d\n", &N) != EOF) {
		cin >> P;
		FOR(i,0,N+1) DP[i] = -1;
		printf("Case %d: %lld\n", t++, go(N));
	}

	return 0;
}
