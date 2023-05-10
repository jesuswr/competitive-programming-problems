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
const int MAXN = 5e4 + 69;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


void solve() {
	int N;
	string A, B;
	cin >> N >> A >> B;
	A = '$' + A, B = '$' + B;
	bitset<MAXN> MRK, BAD, ALL_ON;
	FOR(i,0,N+1) ALL_ON[i] = true;
	vi SUM(N+1), IDs(N+1);
	FOR(i,1,N+1) {
		IDs[i] = i;
		SUM[i] = SUM[i-1] + (A[i] == '1' ? 1 : -1);
	}
	sort(IDs.begin(), IDs.end(), [&](int a, int b){
		if (SUM[a] != SUM[b])
			return SUM[a] > SUM[b];
		return a < b;
	});
	int mn = INF;
	FOR(i,0,N+1) {
		int p = IDs[i];
		if (!p){ 
			MRK[N-p] = 1;
			continue;
		}
		if (B[p] == '1') {
			BAD = BAD | (MRK >> (N - p));
			if (SUM[p] <= 0) mn = min(mn, p);
		}
		else {
			BAD = BAD | ((MRK ^ ALL_ON) >> (N - p));
			if (SUM[p] > 0) mn = min(mn, p);
		}
		MRK[N-p] = 1;
	}
	FOR(i,1,N+1) {
		if (BAD[i] || i >= mn) cout << 0;
		else cout << 1;
	}
	cout << endl;

}


int main(){
	fastIO();
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
