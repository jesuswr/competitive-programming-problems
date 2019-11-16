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
const int maxN = 1e4+5; // CAMBIAR ESTE

// GJNM
int n;
char s[maxN], t[maxN];

int main()
{
	int k;
	ri(k);
	while(k--){
		int c = 0;
		int f = 0;
		int ss = 0;
		ri(n);
		scanf("%s",s);
		scanf("%s",t);
		FOR(i,0,n){
			if ( s[i] != t[i] ){
				if ( c == 0 ){
					c++;
					f = i;
				}
				else if ( c == 1 ){
					c++;
					ss = i;
				}
				else{
					c++;
					break;
				}
			}
		}
		if ( c == 0 ) printf("Yes\n");
		else if ( c == 2 ){
			if ( t[f] == t[ss] && s[ss] == s[f] ){
				printf("Yes\n");
			}
			else printf("No\n");
		}
		else printf("No\n");
	}
	return 0;
}