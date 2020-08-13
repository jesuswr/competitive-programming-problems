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

int main() {
	int t;
	ri(t);
	while (t--) {
		string s;
		cin >> s;
		int r_cnt, p_cnt, s_cnt;
		r_cnt = p_cnt = s_cnt = 0;
		FOR(i, 0, s.size()) {
			if ( s[i] == 'R' )
				r_cnt++;
			else if ( s[i] == 'P' )
				p_cnt++;
			else if ( s[i] == 'S' )
				s_cnt++;
		}
		char ans;
		if ( r_cnt == max(r_cnt, max(s_cnt, p_cnt)) )
			ans = 'P';
		else if ( p_cnt == max(r_cnt, max(s_cnt, p_cnt)) )
			ans = 'S';
		else
			ans = 'R';
		FOR(i,0,s.size()){
			printf("%c", ans);
		}
		printf("\n");

	}
	return 0;
}