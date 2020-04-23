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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
bool vis[2001][2001];
int result[maxN];
int n,k;
char nums[maxN][10];
string zero = "1110111", one = "0010010", two = "1011101", three = "1011011",
	   four = "0111010", five = "1101011", six = "1101111", seven = "1010010",
	   eight = "1111111", nine = "1111011";

int dif(int x, string &s){
	int cnt = 0;
	FOR(i,0,7){
		if (s[i]=='1' && nums[x][i]=='0')
			cnt++;
		else if (s[i]=='0' && nums[x][i]=='1')
			return 10000;
	}
	return cnt;
}


bool dfs(int x, int left){
	//printf("%d %d\n",x,left );
	if ( vis[x][left] )
		return false;


	if ( left == 0 && x == n )
		return true;
	if ( left < 0 || x >= n)
		return false;

	vis[x][left] = true;

	if ( dif(x,nine) <= left ){
		result[x] = 9;
		if ( dfs(x+1,left-dif(x,nine) ) )
			return true;
	}

	if ( dif(x,eight) <= left ){
		result[x] = 8;
		if ( dfs(x+1,left-dif(x,eight) ) )
			return true;
	}

	if ( dif(x,seven) <= left ){
		result[x] = 7;
		if ( dfs(x+1,left-dif(x,seven)) )
			return true;
	}

	if ( dif(x,six) <= left ){
		result[x] = 6;
		if ( dfs(x+1,left-dif(x,six)) )
			return true;
	}

	if ( dif(x,five) <= left ){
		result[x] = 5;
		if ( dfs(x+1,left-dif(x,five)) )
			return true;
	}
	if ( dif(x,four) <= left ){
		result[x] = 4;
		if ( dfs(x+1,left-dif(x,four)) )
			return true;
	}
	if ( dif(x,three) <= left ){
		result[x] = 3;
		if ( dfs(x+1,left-dif(x,three)) )
			return true;
	}
	if ( dif(x,two) <= left ){
		result[x] = 2;
		if ( dfs(x+1,left-dif(x,two)) )
			return true;
	}
	if ( dif(x,one) <= left ){
		result[x] = 1;
		if ( dfs(x+1,left-dif(x,one)) )
			return true;
	}
	if ( dif(x,zero) <= left ){
		result[x] = 0;
		if ( dfs(x+1,left-dif(x,zero)) )
			return true;
	}

	return false;
}


int main(){
	rii(n,k);
	FOR(i,0,n)
		scanf("%s",nums[i]);
	
	

	bool ans = dfs(0,k);
	if (!ans)
		printf("-1");
	else
		FOR(i,0,n)
			printf("%d", result[i]);
	printf("\n");
	
	return 0;
}