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
char a[100], b[100];

int main(){
	int t = 1;
	int t2 ;
	ri(t2);
	while(t<=t2){
		scanf("%s",a);
		int n = strlen(a);
		int start = n+1;
		FOR(i,0,n){
			if ( a[i] == '4' ){
				a[i] = '3';
				b[i] = '1';
				start = min(start,i);
			}
			else{
				b[i] = '0';
			}
		}
		printf("Case #%d: %s ",t++, a);
		FOR(i,start,n){
			printf("%c", b[i]);
		}
		printf("\n");
	}

	return 0;
}