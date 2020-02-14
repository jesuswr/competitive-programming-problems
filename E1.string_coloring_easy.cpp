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
char s[300];
int order[300];

int main(){
	int n;
	ri(n);
	scanf("%s",s);
	int cmp = -1;
	FOR(i,0,n){
		if ( (int)s[i] >= cmp ){
			order[i] = 0;
			cmp = (int)s[i];
		}
		else
			order[i] = 1;
	}
	cmp = -99999;
	bool ans = true;
	FOR(i,0,n){
		if ( !order[i] )
			continue;
		if ( (int)s[i] < cmp)
			ans = false;
		else
			cmp = (int)s[i];
	}
	if ( ans ){
		printf("YES\n");
		FOR(i,0,n)
			printf("%d", order[i]);
		printf("\n");
	}
	else
		printf("NO\n");
	return 0;
}