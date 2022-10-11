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
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
string S;

bool can_win(int cw, int a, int b, int nw) {
	if (cw != 2) return cw == 0;
	if (S[a] != S[b]) return S[a] < S[b];
	return nw == 0;
}
bool can_draw(int cw, int a, int b, int nw) {
	if (can_win(cw, a, b, nw)) return true;
	return cw == 2 && S[a] == S[b] && nw == 2;
}
int g(int a, int b, int nw) {
	if (S[a] < S[b]) return 0;
	else if (S[a] > S[b]) return 1;
	else return nw;
}

int DP[2010][2010][3];
int f(int l, int r, int c = 2) {
	if (l > r) return 2;
	if (DP[l][r][c] != -1)
		return DP[l][r][c];


	if (can_win(f(l + 2, r, g(l, l + 1, c)), l, l + 1, c) && can_win(f(l + 1, r - 1, g(l, r, c)), l, r, c))
		DP[l][r][c] = 0;
	else if (can_win(f(l, r - 2, g(r, r - 1, c)), r, r - 1, c) && can_win(f(l + 1, r - 1, g(r, l, c)), r, l, c))
		DP[l][r][c] = 0;
	else if (can_draw(f(l + 2, r, g(l, l + 1, c)), l, l + 1, c) && can_draw(f(l + 1, r - 1, g(l, r, c)), l, r, c))
		DP[l][r][c] = 2;
	else if (can_draw(f(l, r - 2, g(r, r - 1, c)), r, r - 1, c) && can_draw(f(l + 1, r - 1, g(r, l, c)), r, l, c))
		DP[l][r][c] = 2;
	else
		DP[l][r][c] = 1;
	// printf("%d %d %d : %d\n", l, r, c, DP[l][r][c]);
	// FOR(i, l, r + 1) printf("%c", S[i]);
	// printf("\n\n");
	return DP[l][r][c];
}



void solve() {
	cin >> S;
	N = S.size();
	FOR(i, 0, N) FOR(j, 0, N) FOR(k, 0, 3) DP[i][j][k] = -1;
	if (f(0, N - 1) == 0)
		printf("Alice\n");
	else if (f(0, N - 1) == 1)
		printf("Bob\n");
	else
		printf("Draw\n");
}


int main() {
	int t; ri(t);
	while (t--) solve();

	return 0;
}