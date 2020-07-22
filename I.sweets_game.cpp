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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int D[10][5] = { {4, 8, 16, 0, 0}, {2, 4, 8, 8, 0}, {1, 2, 4, 4, 4}, {0, 1, 2, 2, 2}, {0, 0, 1, 1, 1},
	{1, 1, 1, 0, 0}, {2, 2, 2, 1, 0}, {4, 4, 4, 2, 1}, {0, 8, 8, 4, 2}, {0, 0, 16, 8, 4}
};


set<vector<int>> aux;

int dp[1 << 3][1 << 4][1 << 5][1 << 4][1 << 3];

int f(int r1, int r2, int r3, int r4, int r5) { // 1 es perdedor, 2 es ganador
	if ( dp[r1][r2][r3][r4][r5] != 0 )
		return dp[r1][r2][r3][r4][r5];

	int &ret = dp[r1][r2][r3][r4][r5] = 1;

	for (auto &v : aux) {
		int pos_r1 = r1 & v[0], pos_r2 = r2 & v[1],
		    pos_r3 = r3 & v[2], pos_r4 = r4 & v[3],
		    pos_r5 = r5 & v[4];
		if ( v[0] == pos_r1 && v[1] == pos_r2 && v[2] == pos_r3 &&
		        v[3] == pos_r4 && v[4] == pos_r5 ) {
			if ( f(r1 ^ v[0], r2 ^ v[1], r3 ^ v[2], r4 ^ v[3], r5 ^ v[4]) == 1 )
				return ret = 2;
		}
	}
	return ret;
}


int main() {
	FOR(i, 0, 10) {
		FOR(j, 0, 5) {
			FOR(k, j, 5) {
				vector<int> aux2;
				FOR(l, 0, 5) {
					if ( l < j || l > k )
						aux2.pb(0);
					else
						aux2.pb(D[i][l]);
				}
				aux.insert(aux2);
			}
		}
	}
	aux.erase({0, 0, 0, 0, 0});
	// save me
	vector<int> save_me = {1, 2, 4};
	FOR(i, 0, 3) {
		FOR(j, i, 3) {
			int ans = 0;
			FOR(k, i, j + 1) {
				ans |= save_me[k];
			}
			aux.insert({ans, 0, 0, 0, 0});
			aux.insert({0, 0, 0, 0, ans});
		}
	}
	save_me = {1, 2, 4, 8};
	FOR(i, 0, 4) {
		FOR(j, i, 4) {
			int ans = 0;
			FOR(k, i, j + 1) {
				ans |= save_me[k];
			}
			aux.insert({0, ans, 0, 0, 0});
			aux.insert({0, 0, 0, ans, 0});
		}
	}
	save_me = {1, 2, 4, 8, 16};
	FOR(i, 0, 5) {
		FOR(j, i, 5) {
			int ans = 0;
			FOR(k, i, j + 1) {
				ans |= save_me[k];
			}
			aux.insert({0, 0, ans, 0, 0});
		}
	}
	// aleluya

	int R[5] = {0, 0, 0, 0, 0};
	FOR(i, 0, 5) {
		string inp;
		getline(cin, inp);
		int put = 1;
		for (auto c : inp) {
			if ( c == ' ')
				continue;
			if ( c == 'O' )
				R[i] |= put;
			put *= 2;
		}
	}

	int ans = f(R[0], R[1], R[2], R[3], R[4]);

	if ( ans == 2 )
		printf("Karlsson\n");
	else
		printf("Lillebror\n");
	return 0;
}