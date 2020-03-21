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
char s[maxN];

int main(){
	scanf("%s",s);
	int n = strlen(s);
	s[n]='z';
	int a, b, c;
	a = b = c = 0;
	FOR(i,0,n){
		if ( s[i]>s[i+1] ){
			printf("NO\n");
			return 0;
		}
		if ( s[i] == 'a' ){
			a++;
		}
		if ( s[i] == 'b' ){
			b++;
		}
		if ( s[i] == 'c' ){
			c++;
		}
	}
	if ( a && b && ( a == c || b == c ) )
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}