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

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M, K;
int A[MAXN];

void solve() {
	rii(N,M), ri(K);
	FOR(i,0,M) ri(A[i]);

	int a = (N + K - 1) / K;
	int cnta = N % K == 0 ? K : N % K;

	sort(A, A+M);
	reverse(A, A+M);
	FOR(i,0,M) {
		if (A[i] > a) {
			cout << "No" << endl;
			return;
		}
		else if (A[i] == a && cnta == 0) {
			cout << "No" << endl;
			return;
		}
		else if (A[i] == a) {
			cnta--;
		}
	}


	cout << "Yes" << endl;

}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
