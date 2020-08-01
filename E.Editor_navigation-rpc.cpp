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
int L[maxN];


int main() {
	int t;
	ri(t);
	while (t--) {
		int l; ri(l);
		FOR(i, 0, l) {
			ri(L[i + 1]);
		}
		int my_r, my_c;
		rii(my_r, my_c);
		int next_r, next_c;
		rii(next_r, next_c);

		map<pii, int> mp; mp[ {my_r, my_c}] = 0;
		queue<pii> bfs; bfs.push({my_r, my_c});

		while (true) {
			int r = bfs.front().F, c = bfs.front().S; bfs.pop();

			if ( r == next_r && c == next_c )
				break;

			if ( r > 1 ) {
				if ( mp.find({r - 1, min(L[r - 1], c)}) == mp.end() ) {
					mp[ {r - 1, min(L[r - 1], c)}] = mp[ {r, c}] + 1;
					bfs.push({r - 1, min(L[r - 1], c)});
				}
				if ( c == 0 ) {
					if ( mp.find({r - 1, min(L[r - 1], INF)}) == mp.end() ) {
						mp[ {r - 1, L[r - 1]}] = mp[ {r, c}] + 1;
						bfs.push({r - 1, L[r - 1]});
					}
				}
			}

			if ( c < L[r] ) {
				if ( mp.find({r, c + 1}) == mp.end() ) {
					mp[ {r, c + 1}] = mp[ {r, c}] + 1;
					bfs.push({r, c + 1});
				}
			}
			if ( c > 0 ) {
				if ( mp.find({r, c - 1}) == mp.end() ) {
					mp[ {r, c - 1}] = mp[ {r, c}] + 1;
					bfs.push({r, c - 1});
				}
			}

			if ( r < l ) {
				if ( mp.find({r + 1, min(L[r + 1], c)}) == mp.end() ) {
					mp[ {r + 1, min(L[r + 1], c)}] = mp[ {r, c}] + 1;
					bfs.push({r + 1, min(L[r + 1], c)});
				}
				if ( c == L[r] ) {
					if ( mp.find({r + 1, min(0, INF)}) == mp.end() ) {
						mp[ {r + 1, 0}] = mp[ {r, c}] + 1;
						bfs.push({r + 1, 0});
					}
				}
			}

		}
		printf("%d\n", mp[{next_r, next_c}]);
	}
	return 0;
}