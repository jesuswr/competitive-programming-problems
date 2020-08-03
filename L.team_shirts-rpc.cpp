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
#include <tuple>

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
string goal;
int n;


int main() {
	cin >> goal;
	ri(n);
	map<int, int> mp;
	FOR(i, 0, n) {
		string aux; cin >> aux;
		int hash = aux[0] - '0' + 1;
		if ( aux.size() > 1 )
			hash += (aux[1] - '0' + 1) * 31;
		mp[hash]++;
	}
	tuple<int, bool, map<int, int>> root; root = {0, true, mp};
	set<tuple<int, bool, map<int, int>>> vis; vis.insert(root);
	queue<tuple<int, bool, map<int, int>>> bfs; bfs.push(root);

	while ( !bfs.empty() ) {
		auto x = bfs.front(); bfs.pop();
		int ind = get<0>(x);
		bool wildcard = get<1>(x);
		map<int, int> hash = get<2>(x);
		if ( goal[ind] == '0' )
			continue;
		if ( ind == goal.size() ) {
			printf("1\n");
			exit(0);
		}

		int hash1 = goal[ind] - '0' + 1;
		if ( hash[hash1] > 0 ) {
			auto aux = x; get<2>(aux)[hash1]--; get<0>(aux)++;
			if ( !vis.count(aux) ) {
				vis.insert(aux);
				bfs.push(aux);
			}
		}
		if ( wildcard ) {
			auto aux = x; get<1>(aux) = false; get<0>(aux)++;
			if ( !vis.count(aux) ) {
				vis.insert(aux);
				bfs.push(aux);
			}
		}

		if ( ind < goal.size() - 1) {
			hash1 += 31 * (goal[ind + 1] - '0' + 1);
			if ( hash[hash1] > 0 ) {
				auto aux = x; get<2>(aux)[hash1]--; get<0>(aux) += 2;
				if ( !vis.count(aux) ) {
					vis.insert(aux);
					bfs.push(aux);
				}
			}
			if ( wildcard ) {
				auto aux = x; get<1>(aux) = false; get<0>(aux) += 2;
				if ( !vis.count(aux) ) {
					vis.insert(aux);
					bfs.push(aux);
				}
			}
		}
	}
	printf("0\n");

	return 0;
}