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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int c1[30];
int c2[30];
char a[110],b[110];

int main()
{
	int t, l1 , l2, s, e;
	bool cond;
	ri(t);
	while(t--){
		scanf("%s",a);
		scanf("%s",b);
		l1 = strlen(a);
		l2 = strlen(b);
		if ( l1 > l2 ){
			cond = false;
		}
		FOR(i,0,30) c1[i] = 0; 
		FOR(i,0,l1) c1[ (int)(a[i]-'a') ]++;
		FOR(i,0,l2-l1+1){
			FOR(j,0,30) c2[j] = 0;
			FOR(j,i,l1+i) c2[ (int)(b[j]-'a') ]++;
			cond = true;
			FOR(j,0,30){
				if ( c1[j] != c2[j] ) cond = false;
			}
			if ( cond ) break;
		}
		if ( cond ) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}