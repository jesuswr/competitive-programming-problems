#include <iostream>
#include <algorithm>


using namespace std;


int main()
{

	pair<int,char> cards[3];
	int a;
	char c;
	scanf("%d%c",&a,&c);
	cards[0]={a,c};
	scanf("%d%c",&a,&c);
	cards[1]={a,c};
	scanf("%d%c",&a,&c);
	cards[2]={a,c};
	sort(cards,cards+3);
	if (cards[0].first == cards[1].first && cards[0].second == cards[1].second && cards[1].first == cards[2].first && cards[2].second == cards[1].second) {printf("0\n");return 0;}
	if (cards[0].second==cards[1].second && cards[1].second==cards[2].second && cards[0].first==cards[1].first-1 && cards[1].first == cards[2].first-1) {printf("0\n");return 0;}
	if (cards[1].first==cards[2].first && cards[1].second==cards[2].second) {printf("1\n");return 0;}
	if (cards[1].first==cards[0].first && cards[1].second==cards[0].second) {printf("1\n");return 0;}
	if ( (cards[1].first==cards[2].first-1 || cards[1].first==cards[2].first-2) && cards[1].second == cards[2].second ) {printf("1\n");return 0;}
	if ( (cards[0].first==cards[1].first-1 || cards[0].first==cards[1].first-2) && cards[0].second == cards[1].second ) {printf("1\n");return 0;}
	printf("2\n");

}