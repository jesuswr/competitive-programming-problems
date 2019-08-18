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
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
int rooms[10];
char events[maxN];

void placeLeft()
{
	for (int i = 0; i < 10; ++i)
	{
		if ( rooms[i] == 0)
		{
			rooms[i] = 1;
			return;
		}
	}
}

void placeRight()
{

	for (int i = 9; i >= 0; --i)
	{
		if ( rooms[i] == 0)
		{
			
			rooms[i] = 1;
			return;
		}
	}
}

int main()
{
	int n;
	ri(n);
	scanf("%s", events);
	for (int i = 0; i < 10; ++i)
	{
		rooms[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if ( events[i] == 'L') placeLeft();
		else if ( events[i] == 'R' ) placeRight();
		else rooms[(int)(events[i] - '0')] = 0;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d", rooms[i]);
	}
	printf("\n");

	return 0;
}