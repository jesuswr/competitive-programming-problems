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

int N, K;
ll A[MAXN];
int DP[MAXN];



int main(){
	rii(N, K);
	FOR(i,0,N) lri(A[i]);
	if (K == 0) {
		cout << N << endl;
		return 0;
	}
	A[N] = INFLL;
	++N;

	sort(A, A+N);
	DP[N-1] = 0;
	for(int i = N-2; i >= 0; --i) {
		int nxt = lower_bound(A, A+N, A[i] + K) - A;
		DP[i] = max(DP[i+1], DP[nxt] + 1);
	}
	cout << DP[0] << endl;
	return 0;
}
