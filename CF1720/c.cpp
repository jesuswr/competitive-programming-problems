#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 510;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M;
char A[MAXN][MAXN];


void solve() {
	rii(N, M);
	FOR(i, 0, N) dsadsa = scanf("%s\n", A[i]);
	int bst = 0;
	int tot = 0;
	FOR(i, 0, N) FOR(j, 0, M) tot += A[i][j] == '1';

	FOR(i, 0, N - 1) FOR(j, 0, M - 1) {
		int op1 = (A[i][j] == '1') + (A[i + 1][j] == '1') + (A[i][j + 1] == '1');
		int op2 = (A[i][j] == '1') + (A[i + 1][j] == '1') + (A[i + 1][j + 1] == '1');
		int op3 = (A[i][j] == '1') + (A[i + 1][j + 1] == '1') + (A[i][j + 1] == '1');
		int op4 = (A[i + 1][j + 1] == '1') + (A[i + 1][j] == '1') + (A[i][j + 1] == '1');
		if (op1) bst = max(bst, tot - op1 + 1);
		if (op2) bst = max(bst, tot - op2 + 1);
		if (op3) bst = max(bst, tot - op3 + 1);
		if (op4) bst = max(bst, tot - op4 + 1);
		// printf("%d %d : %d          %d %d %d %d\n", i, j, bst, op1, op2, op3, op4);
	}
	printf("%d\n", bst);
}


int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}