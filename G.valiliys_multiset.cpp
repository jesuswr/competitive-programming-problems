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
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>=m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e7; // CAMBIAR ESTE

// GJNM
int trie[maxN][2];
int cnt_trie[maxN][2];
int freee = 1;

void add(int x){
	int curr = 0;
	ROF(i,30,0){
		int goal = x & (1<<i);
		goal = goal > 0;
		cnt_trie[curr][goal]++;
		if ( trie[curr][goal] == 0 )
			trie[curr][goal] = freee++;
		curr = trie[curr][goal];
	}
}

void del(int x){
	int curr = 0;
	ROF(i,30,0){
		int goal = x & (1<<i);
		goal = goal > 0;
		cnt_trie[curr][goal]--;
		curr = trie[curr][goal];
	}
}

void query(int x){
	int curr = 0;
	int ans = 0;
	if ( cnt_trie[curr][1] + cnt_trie[curr][0] == 0){
		printf("%d\n", x);
		return;
	}
	ROF(i,30,0){
		int goal = x & (1<<i);
		goal = goal > 0;
		if ( cnt_trie[curr][1-goal] > 0 ){
			ans |= (1<<i);
			curr = trie[curr][1-goal];
		}
		else
			curr = trie[curr][goal];
	}
	printf("%d\n", max(ans,x));
}



int main(){
	int q;
	ri(q);
	char c;
	int x;
	while(q--){
		scanf("%*c%c %d", &c, &x);
		if ( c == '+' )
			add(x);
		else if ( c == '-' )
			del(x);
		else
			query(x);
	}
	return 0;
}