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

void solve(multiset<int> &nums, int goal) {
	set<multiset<int>> vis; vis.insert(nums);
	queue<multiset<int>> bfs; bfs.push(nums);
	queue<vector<int>> path; path.push({});

	multiset<int> best_set;
	vector<int> best_path;
	int best_ans = INF;

	while (!bfs.empty()) {
		multiset<int> st = bfs.front(); bfs.pop();
		vector<int> st_path = path.front(); path.pop();

		for (auto y : st) {
			if ( abs(goal - best_ans) > abs(goal - y) ) {
				best_set  = st;
				best_path = st_path;
				best_ans = y;
			}
		}

		if ( goal - best_ans == 0 )
			break;

		for (auto it1 = st.begin(); it1 != st.end(); it1++) {
			for (auto it2 = st.begin(); it2 != st.end(); it2++) {
				if ( it1 == it2 )
					continue;

				if ( true ) { // jeje
					multiset<int> suma;
					vector<int> suma_path = st_path;
					suma.erase(*it1), suma.erase(*it2);
					suma.insert(*it1 + *it2);
					for (auto it3 = st.begin(); it3 != st.end(); it3++) {
						if ( it3 == it2 || it3 == it1 )
							continue;
						suma.insert(*it3);
					}
					if ( vis.find(suma) == vis.end() ) {
						vis.insert(suma);
						suma_path.pb(*it1), suma_path.pb(*it2), suma_path.pb(*it1 + *it2);
						bfs.push(suma), path.push(suma_path );
					}
				}

				if ( (*it1) % (*it2) == 0 ) { // jeje
					multiset<int> div;
					vector<int> div_path = st_path;
					div.erase(*it1), div.erase(*it2);
					div.insert(*it1 / *it2);
					for (auto it3 = st.begin(); it3 != st.end(); it3++) {
						if ( it3 == it2 || it3 == it1 )
							continue;
						div.insert(*it3);
					}
					if ( vis.find(div) == vis.end() ) {
						vis.insert(div);
						div_path.pb(*it1), div_path.pb(*it2), div_path.pb(*it1 / *it2);
						bfs.push(div), path.push(div_path );
					}
				}

				if ( *it1 - *it2 > 0 ) { // jeje
					multiset<int> resta;
					vector<int> resta_path = st_path;
					resta.erase(*it1), resta.erase(*it2);
					resta.insert(*it1 - *it2);
					for (auto it3 = st.begin(); it3 != st.end(); it3++) {
						if ( it3 == it2 || it3 == it1 )
							continue;
						resta.insert(*it3);
					}
					if ( vis.find(resta) == vis.end() ) {
						vis.insert(resta);
						resta_path.pb(*it1), resta_path.pb(*it2), resta_path.pb(*it1 - *it2);
						bfs.push(resta), path.push(resta_path );
					}
				}

				if ( true ) { // jeje
					multiset<int> multi;
					vector<int> multi_path = st_path;
					multi.erase(*it1), multi.erase(*it2);
					multi.insert( (*it1) * (*it2));
					for (auto it3 = st.begin(); it3 != st.end(); it3++) {
						if ( it3 == it2 || it3 == it1 )
							continue;
						multi.insert(*it3);
					}
					if ( vis.find(multi) == vis.end() ) {
						vis.insert(multi);
						multi_path.pb(*it1), multi_path.pb(*it2), multi_path.pb((*it1) * (*it2));
						bfs.push(multi), path.push(multi_path );
					}
				}
			}
		}
	}
	printf("Target: %d\n", goal);
	for (int i = 0; i < best_path.size(); i += 3) {
		if ( best_path[i] + best_path[i+1] == best_path[i+2] )
			printf("%d + %d = %d\n",best_path[i], best_path[i+1], best_path[i+2] );

		else if ( best_path[i] - best_path[i+1] == best_path[i+2] )
			printf("%d - %d = %d\n",best_path[i], best_path[i+1], best_path[i+2] );

		else if ( best_path[i] * best_path[i+1] == best_path[i+2] )
			printf("%d * %d = %d\n",best_path[i], best_path[i+1], best_path[i+2] );

		else if ( best_path[i] / best_path[i+1] == best_path[i+2] )
			printf("%d / %d = %d\n",best_path[i], best_path[i+1], best_path[i+2] );
	}
	printf("Best approx: %d\n\n", best_ans);
}

int main() {
	int c;
	ri(c);
	while (c--) {
		multiset<int> ayuda;
		FOR(i, 0, 6) {
			int aux; ri(aux);
			ayuda.insert(aux);
		}
		int ans; ri(ans);
		solve(ayuda, ans);
	}
	return 0;
}