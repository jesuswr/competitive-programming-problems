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

#define ri(a) scanf("%d", &a);
#define rii(a,b) scanf("%d %d", &a, &b);
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c);
#define rl(a) scanf("%lld", &a);
#define rll(a,b) scanf("%lld %lld", &a, &b);

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 101; // CAMBIAR ESTE

// GJNM

int arr[maxN], arr2[maxN];
unordered_map<int,int> mp1, mp2;

int main()
{
	int n,m;
	ri(n);
	for ( int i = 0; i < n; i ++) {ri(arr[i]); mp1[arr[i]] = 1;}
	ri(m);
	for ( int i = 0; i < m; i ++) {ri(arr2[i]); mp2[arr2[i]] = 1;}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{

			if ( mp1.find(arr[i]+arr2[j]) == mp1.end() &&  mp2.find(arr[i]+arr2[j]) == mp2.end())
			{
				printf("%d %d\n", arr[i], arr2[j]);
				return 0;
			}
		}
	}

	return 0;
}