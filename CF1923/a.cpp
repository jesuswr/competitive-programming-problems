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

int N;
int A[MAXN];

int get_lst() {
	int x = 0;
	FOR(i,0,N) if (A[i]) x = i;
	return x;
}

int get_fst() {
	int x = N;
	for(int i = N-1; i >= 0; --i) if (A[i]) x = i;
	return x;
}



void solve() {
	ri(N);
	FOR(i,0,N) ri(A[i]);
	
	int ans = 0;
	while(1) {
		int fst = get_fst(), lst = get_lst();
		int lst_zero = -1;
		FOR(i,fst,lst+1) if (A[i] == 0) lst_zero = i;
		if (lst_zero == -1) break;
		swap(A[lst], A[lst_zero]);
		ans++;
	}	
	cout << ans << endl;
}

int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
