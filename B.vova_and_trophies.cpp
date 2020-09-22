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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int n;
string s;
vector< pair<char, int> > arr;

int main() {
	ri(n); cin >> s;
	int i = 0;
	arr.pb({'?', 0}); arr.pb({'?', 0});
	while (i < s.size()) {
		int j = i;
		while (j < s.size() && s[j] == s[i])
			j++;
		arr.pb({s[i], j - i});
		i = j;
	}
	arr.pb({'?', 0}); arr.pb({'?', 0});
	int blocks = 0;
	for (auto p : arr) {
		if (p.F == 'G')
			blocks++;
	}
	int mx = 0;
	FOR(i, 2, arr.size() - 2) {
		if (arr[i].F != 'G')
			continue;

		mx = max(mx, arr[i].S);
		if (blocks >= 2)
			mx = max(mx, arr[i].S + 1);

		if (arr[i - 1].S == 1) {
			if (blocks == 2)
				mx = max(mx, arr[i].S + arr[i - 2].S);
			if (blocks > 2)
				mx = max(mx, arr[i].S + arr[i - 2].S + 1);
		}

		if (arr[i + 1].S == 1) {
			if (blocks == 2)
				mx = max(mx, arr[i].S + arr[i + 2].S);
			if (blocks > 2)
				mx = max(mx, arr[i].S + arr[i + 2].S + 1);
		}
	}

	printf("%d\n", mx);
	return 0;
}