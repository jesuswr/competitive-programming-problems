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
     
using namespace std;
     
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
    
#define ri(a) scanf("%d", &a);
#define rii(a,b) scanf("%d %d", &a, &b);
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c);
#define rl(a) scanf("%lld", &a);
#define rll(a,b) scanf("%lld %lld", &a, &b);
     
const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE
     
// GJNM
     
map<ll,int> mp , mp2;
ll arr[2001];
     
int main()
{
 	int n;
   	ri(n);
   	for (int i = 0; i < n; ++i)
   	{
   		rl(arr[i]);
   		if ( mp.find(arr[i]) == mp.end() ) mp[arr[i]] = 0;
   		mp[arr[i]]++;
   	}
   	int count = 0;
   	for ( auto p : mp )
   	{
   		if ( p.second > 1) count++;
   	}
   	if ( count == 0)
   	{
   		printf("0\n");
   		return 0;
   	}
   	int count2;
    
   	int ans = INF;
   	for (int i = 0; i < n; ++i)
   	{
   		count2 = count;
   		mp2.clear();
   		for (int j = i; j < n; ++j)
   		{
   			if ( mp2.find(arr[j]) == mp2.end() ) mp2[arr[j]] = 0;
   			mp2[arr[j]]++;
   			if ( mp2[arr[j]] == mp[arr[j]] - 1) count2--;
   			if ( count2 == 0 )
   			{
   				ans = min( ans , j - i + 1);
   				break;
   			}
   		}
   	}
   	printf("%d\n", ans);
}