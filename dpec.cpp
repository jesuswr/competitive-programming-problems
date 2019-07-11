#include <iostream>
#include <queue>

using namespace std;

char map[203][203];
int cost1[203][203];
int cost2[203][203];
int cost3[203][203];
int rows, columns;
pair <int,int> person1, person2, person3;

void bfs1(int r, int c){
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

		if (ro>0 && map[ro-1][co]!='#' && cost1[ro][co]+1<cost1[ro-1][co]){
			cost1[ro-1][co] = cost1[ro][co]+1;
			rQ.push(ro-1);
			cQ.push(co);
		}

		if (co>0 && map[ro][co-1]!='#' && cost1[ro][co]+1<cost1[ro][co-1]){
			cost1[ro][co-1] = cost1[ro][co]+1;
			rQ.push(ro);
			cQ.push(co-1);
		}

		if (co<columns-1 && map[ro][co+1]!='#' &&   cost1[ro][co]+1<cost1[ro][co+1]){
			cost1[ro][co+1] = cost1[ro][co]+1;
			rQ.push(ro);
			cQ.push(co+1);
		}

		if (ro<rows-1 && map[ro+1][co]!='#' &&   cost1[ro][co]+1<cost1[ro+1][co]){
			cost1[ro+1][co] = cost1[ro][co]+1;
			rQ.push(ro+1);
			cQ.push(co);
		}
	    
	}
}

void bfs2(int r, int c){
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

		if (ro>0 && map[ro-1][co]!='#' && cost2[ro][co]+1<cost2[ro-1][co]){
			cost2[ro-1][co] = cost2[ro][co]+1;
			rQ.push(ro-1);
			cQ.push(co);
		}

		if (co>0 && map[ro][co-1]!='#' &&  cost2[ro][co]+1<cost2[ro][co-1]){
			cost2[ro][co-1] = cost2[ro][co]+1;
			rQ.push(ro);
			cQ.push(co-1);
		}

		if (co<columns-1 && map[ro][co+1]!='#' &&   cost2[ro][co]+1<cost2[ro][co+1]){
			cost2[ro][co+1] = cost2[ro][co]+1;
			rQ.push(ro);
			cQ.push(co+1);
		}

		if (ro<rows-1 && map[ro+1][co]!='#' &&   cost2[ro][co]+1<cost2[ro+1][co]){
			cost2[ro+1][co] = cost2[ro][co]+1;
			rQ.push(ro+1);
			cQ.push(co);
		}
	    
	}
}

void bfs3(int r, int c){
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

		if (ro>0 && map[ro-1][co]!='#' && cost3[ro][co]+1<cost3[ro-1][co]){
			cost3[ro-1][co] = cost3[ro][co]+1;
			rQ.push(ro-1);
			cQ.push(co);
		}

		if (co>0 && map[ro][co-1]!='#' &&  cost3[ro][co]+1<cost3[ro][co-1]){
			cost3[ro][co-1] = cost3[ro][co]+1;
			rQ.push(ro);
			cQ.push(co-1);
		}

		if (co<columns-1 && map[ro][co+1]!='#' &&  cost3[ro][co]+1<cost3[ro][co+1]){
			cost3[ro][co+1] = cost3[ro][co]+1;
			rQ.push(ro);
			cQ.push(co+1);
		}

		if (ro<rows-1 && map[ro+1][co]!='#' &&   cost3[ro][co]+1<cost3[ro+1][co]){
			cost3[ro+1][co] = cost3[ro][co]+1;
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
		scanf("%d %d", &rows, &columns);

		for (int i = 0; i < columns + 2; i++)
		{
			map[0][i] = '.';
			map[rows+1][i] = '.';
		}

		for (int i = 1; i <= rows; i++)
		{
			scanf("%s",&map[i][1]);
			for (int j = 1; j <= columns; j++)
			{
				if (map[i][j] == '1'){
					person1.first = i;
					person1.second = j;
				}
				if (map[i][j] == '2'){
					person2.first = i;
					person2.second = j;
				}
				if (map[i][j] == '3'){
					person3.first = i;
					person3.second = j;
				}

			}
		}

		for (int i = 0; i < rows + 2; i++)
		{
			map[i][0] = '.';
			map[i][columns+1] = '.';
		}

		rows += 2;
		columns +=2;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cost1[i][j] = 110000;
				cost2[i][j] = 110000;
				cost3[i][j] = 110000;
			}
		}

		cost1[person1.first][person1.second] = 0;
		cost3[person3.first][person3.second] = 0;
		cost2[person2.first][person2.second] = 0;

		bfs1(person1.first, person1.second);
		bfs2(person2.first, person2.second);
		bfs3(person3.first, person3.second);

		

		int ans = 999999999;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				ans = min (ans, max(cost1[i][j],max(cost2[i][j],cost3[i][j])));
			}
		}
		printf("%d\n", ans);

		
	}
}
