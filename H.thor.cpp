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
const int maxN = 4e5; // CAMBIAR ESTE

// GJNM
set< pii > notif;
stack<pii> notif_from[maxN];
int t = 1;

void ins(int time, int from) {
	notif.insert({time, from});
	notif_from[from].push({time, from});
}

void del_x(int x) {
	while (!notif_from[x].empty()) {
		notif.erase(notif_from[x].top());
		notif_from[x].pop();
	}
}

void del_range(int start, int end){
	vii delet;
	for(auto it = notif.lb({start,-1}); it != notif.end() && it != notif.lb({end+1,-1}); it++){
		delet.pb(*it);
	}
	for(auto p : delet){
		notif.erase(p);
	}
}


int main() {
	int n, q;
	rii(n, q);
	while (q--) {
		int a, b;
		rii(a, b);

		if ( a == 1 ) {
			ins(t++, b);
		}
		else if ( a == 2 ) {
			del_x(b);
		}
		else {
			del_range(1, b);
		}
		printf("%lu\n", notif.size());
	}

	return 0;
}