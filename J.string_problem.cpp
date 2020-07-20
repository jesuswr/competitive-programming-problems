#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5 + 20; // CAMBIAR ESTE

// GJNM
int DP[30][30];

int main() {
	string S, T; cin >> S >> T;
	int ssize = S.size();
	int tsize = T.size();
	if ( ssize != tsize ) {
		printf("-1\n");
		return 0;
	}

	FOR(i, 0, 28) FOR(j, 0, 28)
		DP[i][j] = INF;
	FOR(i, 0, 28)
		DP[i][i] = 0;

	int n; ri(n);
	scanf("%*c");
	FOR(i, 0, n) {
		char a, b;
		int cost;
		scanf("%c %c %d\n", &a, &b, &cost);
		DP[a - 'a'][b - 'a'] = min(DP[a - 'a'][b - 'a'], cost);
	}
	FOR(k,0,28) FOR(i,0,28) FOR(j,0,28)
		DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);


	int ans = 0;
	FOR(i,0,ssize){
		char a = S[i], b = T[i];
		int mn_cost = INF;
		char neww;
		FOR(j,0,28){
			if ( DP[a-'a'][j] + DP[b-'a'][j] < mn_cost ){
				mn_cost = DP[a-'a'][j] + DP[b-'a'][j];
				neww = 'a' + j;
			}
		}

		if (mn_cost == INF){
			printf("-1\n");
			return 0;
		}
		ans += mn_cost;
		S[i] = neww;
	}
	printf("%d\n", ans);
	cout << S << endl;



	return 0;
}