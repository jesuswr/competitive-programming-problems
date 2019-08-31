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
const int maxN = 2e5+5; // CAMBIAR ESTE

// GJNM
int arr[maxN];
priority_queue<int> pq[maxN];

int main()
{
	int n , k;
	rii(n,k);
	for (int i = 0; i < n; ++i)
	{
		ri(arr[i]);
		int count = 0;
		pq[arr[i]].push(0);
		while(arr[i] > 0) 
		{
		   	count++;
		   	arr[i] = arr[i] / 2;
		   	pq[arr[i]].push(-count);
		}
	}
	int mn = INF;
	int moves = 0;
	for (int i = 0; i < maxN; ++i)
	{
		if ( pq[i].size() < k) continue;
		moves = 0;
		for (int j = 0; j < k; ++j)
		{
			moves += -pq[i].top();
			pq[i].pop();
		}
		mn = min( moves, mn);
	}
	printf("%d\n",mn );
	return 0;
}