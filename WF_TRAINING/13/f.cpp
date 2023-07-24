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
array<int, 3> A[MAXN], B[MAXN];
bool used[MAXN];

int main(){
	ri(N);
	FOR(i,0,N) {
		FOR(j,0,2) { 
			ri(A[i][j]);
			B[i][j] = A[i][j];
		}
		A[i][2] = B[i][2] = i;
	}

	sort(A, A+N, [](auto a, auto b) {
		if (a[0] != b[0]) return a[0] < b[0];
		return a[1] > b[1];
	});
	sort(B, B+N, [](auto a, auto b) {
		return a[1] < b[1];
	});

	vi ans;
	int bi = 0;
	int first_l = -1;
	FOR(i,0,N) if (!used[i]) {
		int l = A[i][0], r = A[i][1];
		int il = max(l, first_l), ir = r;
		while(bi < N && B[bi][1] <= r) {
			il = max(il, B[bi][0]);
			ir = min(ir, B[bi][1]);
			used[bi] = 1;
			bi++;
		}
		if (il > ir) {
			cout << -1 << endl;
			return 0;
		}

		ans.pb(il);
		first_l = r + 1;
	}

	cout << sz(ans) << endl;
	for(int x : ans) cout << x << " ";
	cout << endl;


	return 0;
}
