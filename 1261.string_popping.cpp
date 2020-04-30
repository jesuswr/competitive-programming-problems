#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <unordered_set>
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
unordered_map<string,bool> dp;

bool f(string s){
	if ( dp.find(s) != dp.end() )
		return dp[s];

	int n = s.size(), i = 0, cnt, j;
	if (n==0)
		return true;

	while(i<n-1){
		j = i;
		cnt = 0;
		while(j<n && s[i]==s[j]){
			j++;
			cnt++;
		}
		if (cnt>1 && f( s.substr(0,i) + s.substr(j,n-j) ) )
			return dp[s] = true;
		i = j;
	}
	return dp[s] = false;
}

int main(){
	int t;
	ri(t);
	while(t--){
		string s;
		cin >> s;
		printf("%d\n", f(s));
	}
	return 0;
}