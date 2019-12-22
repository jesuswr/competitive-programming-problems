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
char w[500];

int main()
{
	int t;
	ri(t);
	while(t--){
		scanf("%s",w);
		int l = strlen(w);
		int s = 0;
		bool z = false;
		bool p = false;
		FOR(i,0,l){
			if ( w[i] == '0' && !z) z = true;
			else if ( (int)(w[i]-'0')%2==0 ) p = true;
			s += (int)(w[i]-'0');
		}
		if ( (s%3==0 && z && p) ) printf("red\n");
		else printf("cyan\n");
	}
	return 0;
}