#include <iostream>

using namespace std;

int rain[100001];

bool check (int start, int ind, int end){
	for (int i = start; i < ind; ++i)
	{
		if ( rain[i]<rain[ind] ) return false;
	}
	for (int i = ind+1; i < end; ++i)
	{
		if ( rain[i]<rain[ind] ) return false;
	}
	return true;

}


int main(){
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n; ++i){
		scanf("%d", &rain[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		if (check(max(0,i-x), i, min(n,i+y+1))){
			int aux = i+1;
			printf("%d\n", aux);
			return 0;
		}
	}

}
