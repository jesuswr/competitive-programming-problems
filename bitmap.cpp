#include <iostream>
#include <stack>
#include <queue>

using namespace std;


int bitmap[183][183];
int cost[183][183];
int rows, columns;
queue<int> rowQ;
queue<int> colQ;


void bfs(int r, int c){
	queue<int> rQ;
	queue<int> cQ;

	rQ.push(r);
	cQ.push(c);

	int ro, co;

	while(!rQ.empty()) {
		ro = rQ.front();
		rQ.pop();
		co = cQ.front();
		cQ.pop();

		if (ro>0 && cost[ro][co]+1<cost[ro-1][co]){
			cost[ro-1][co] = cost[ro][co]+1;
			rQ.push(ro-1);
			cQ.push(co);
		}

		if (co>0 && cost[ro][co]+1<cost[ro][co-1]){
			cost[ro][co-1] = cost[ro][co]+1;
			rQ.push(ro);
			cQ.push(co-1);
		}

		if (co<columns-1 && cost[ro][co]+1<cost[ro][co+1]){
			cost[ro][co+1] = cost[ro][co]+1;
			rQ.push(ro);
			cQ.push(co+1);
		}

		if (ro<rows-1 && cost[ro][co]+1<cost[ro+1][co]){
			cost[ro+1][co] = cost[ro][co]+1;
			rQ.push(ro+1);
			cQ.push(co);
		}
	    
	}
}



int main(){
	int n;
	scanf("%d",&n);
	for (int p = 0; p < n; p++)
	{
		scanf("%d %d",&rows,&columns);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				scanf("%1d",&bitmap[i][j]);
				if (bitmap[i][j] == 1){
					cost[i][j] = 0;
					rowQ.push(i);
					colQ.push(j);
				}
				else{
					cost[i][j] = 10000;
				}
			}
		}

		int a,b;
		while(!rowQ.empty()) {
		    a = rowQ.front();
		    b = colQ.front();
		    rowQ.pop();
		    colQ.pop();

		    bfs(a,b);
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				printf("%d ", cost[i][j]);
			}
			printf("\n");
		}



	}
}