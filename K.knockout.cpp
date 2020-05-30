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
void output(int x){
	FOR(i,1,10){
		if ( (1<<i) & x )
			printf("%d", i);
	}
}


vector<int> get_moves(int btmsk, int sum){
	vector<int> have;
	vector<int> ans;

	FOR(i,1,10){
		if ( btmsk & (1<<i) )
			have.pb(i);
	}

	int n = have.size();
	FOR(i,0,1<<n){
		int curr_sum = 0, ret = 0;
		FOR(j,0,n){
			if ( i & (1<<j) ){
				ret |= (1<<have[j]);
				curr_sum += have[j];
			}
		}
		if ( curr_sum == sum )
			ans.pb(ret);

	}
	return ans;
}

bool vis[1<<11][14], vis2[1<<11][14];
long double dp[1<<11][14];
int path[1<<11][14];

long double get_concat(int btmsk){
	long double ret = 0;
	FOR(i,1,10){
		if ( btmsk & (1<<i) ){
			ret *= 10;
			ret += i;
		}
	}
	return ret;
}

long double f(int btmsk, int sum){
	if ( vis[btmsk][sum] )
		return dp[btmsk][sum];
	vis[btmsk][sum] = true;
	path[btmsk][sum] = -1;

	vector<int> pos_moves = get_moves(btmsk, sum);

	dp[btmsk][sum] = 213456789;
	for(auto take : pos_moves){
		long double curr = 0;
		FOR(i,1,7){
			FOR(j,1,7){
				curr += f(btmsk^take, i+j);
			}
		}
		if ( dp[btmsk][sum] > curr/36 ){
			dp[btmsk][sum] = curr/36;
			path[btmsk][sum] = take;
		}
	}

	if ( pos_moves.size() == 0 )
		dp[btmsk][sum] = get_concat(btmsk);
	
	
	return dp[btmsk][sum];
}

long double f2(int btmsk, int sum){
	if ( vis2[btmsk][sum] )
		return dp[btmsk][sum];
	vis2[btmsk][sum] = true;
	path[btmsk][sum] = -1;

	vector<int> pos_moves = get_moves(btmsk, sum);

	dp[btmsk][sum] = -1;
	for(auto take : pos_moves){
		long double curr = 0;
		FOR(i,1,7){
			FOR(j,1,7){
				curr += f2(btmsk^take, i+j);
			}
		}
		if ( dp[btmsk][sum] < curr/36 ){
			dp[btmsk][sum] = curr/36;
			path[btmsk][sum] = take;
		}
	}

	if ( pos_moves.size() == 0 )
		dp[btmsk][sum] = get_concat(btmsk);
	
	
	return dp[btmsk][sum];
}

int main(){
	int btmsk = 0;
	int s1, s2;
	char c;
	while(scanf("%c", &c), c!=' ')
		btmsk |= (1<< (c-'0'));
	rii(s1,s2);
	long double min = f(btmsk, s1+s2);
	if (path[btmsk][s1+s2] == -1){
		printf("-1 %.5Lf\n", min);
	}
	else{
		output(path[btmsk][s1+s2]);
		printf(" %.5Lf\n", min);
	}

	long double max = f2(btmsk, s1+s2);
	if (path[btmsk][s1+s2] == -1){
		printf("-1 %.5Lf\n", max);
	}
	else{
		output(path[btmsk][s1+s2]);
		printf(" %.5Lf\n", max);
	}

	return 0;
}