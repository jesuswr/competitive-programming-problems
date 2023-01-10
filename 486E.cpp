#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int A[MAXN], P[MAXN];


int build_lis(){
	vi lis;
	int i = 0;
	for(int a : A) {
		auto it = lower_bound(all(lis), a);
		int ind = it - lis.begin();
		if (ind == sz(lis)) lis.pb(0);
		lis[ind] = a;
		P[i++] = ind+1;
	}
	return sz(lis);
}	


bool B[MAXN];
int MX[MAXN], CNT[MAXN];


int main(){
	ri(N);
	FOR(i,0,N) ri(A[i]);
	int sz = build_lis();
	// FOR(i,0,N) printf("%d : %d\n", A[i], P[i]);

	for(int i = N - 1; i >= 0; --i) {
		if (P[i] == sz || MX[P[i] + 1] > A[i]){
			B[i] = 1;
			MX[P[i]] = max(MX[P[i]], A[i]);
			CNT[P[i]]++;
		}
	}

	for(int i = 0; i < N; ++i){
		if (!B[i]) putchar('1');
		else if (CNT[P[i]] > 1) putchar('2');
		else putchar('3');
	}
	putchar('\n');
	return 0;
}
