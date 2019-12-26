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
const int maxN = 15e5+5; // CAMBIAR ESTE

// GJNM
char w[maxN];
queue<int> q;

int main()
{
	int t;
	ri(t);
	while(t--){
		scanf("%s",w);
		int l = strlen(w);
		int i = 0;
		int ans = 0;

		while( i < l-2 ){
			if ( strncmp(  &w[i] , "twone" , 5 ) == 0){
				ans++;
				q.push(i+3);
				i = i + 5;
			}
			else if ( strncmp( &w[i] , "two" , 3 ) == 0){
				ans++;
				q.push(i+2);
				i = i + 3;
			}
			else if ( strncmp( &w[i] , "one" , 3 ) == 0){
				ans++;
				q.push(i+2);
				i = i + 3;
			}
			else 
				i++;
		}
		printf("%d\n", ans);
		while( !q.empty() ){
			printf("%d ", q.front() );
			q.pop();
		}
		printf("\n");
	}
	return 0;
}