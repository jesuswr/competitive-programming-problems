#include <iostream>

char matrix[101][101];
int visited[101][101];
int rows, columns;
char word[10] = {'A','L','L','I','Z','Z','W','E','L','L'};
int ans;

void dfs(int ind, int row, int col){
	//printf("HOLAA %d %d %d \n",ind,row,col );

	if (ind == 10){
		ans = 1;
		return;
	}
	else{
		visited[row][col] = 1;

		if (row>0 && !visited[row-1][col] && matrix[row-1][col]==word[ind] && ans==0){

			dfs(ind+1,row-1,col);

		}

		if (row<rows-1 && !visited[row+1][col] && matrix[row+1][col]==word[ind]  && ans==0){

			dfs(ind+1,row+1,col);

		}

		if (col>0 && !visited[row][col-1] && matrix[row][col-1]==word[ind] && ans==0){

			dfs(ind+1,row,col-1);

		}

		if (col<columns-1 && !visited[row][col+1] && matrix[row][col+1]==word[ind] && ans==0){

			dfs(ind+1,row,col+1);

		} 

		if (col<columns-1 && row>0 && !visited[row-1][col+1] && matrix[row-1][col+1]==word[ind] && ans==0){

			dfs(ind+1,row-1,col+1);

		}

		if (col<columns-1 && row<rows-1 && !visited[row+1][col+1] && matrix[row+1][col+1]==word[ind] && ans==0){

			dfs(ind+1,row+1,col+1);

		}

		if (col>0 && row<rows-1 && !visited[row+1][col-1] && matrix[row+1][col-1]==word[ind] && ans==0){

			dfs(ind+1,row+1,col-1);

		}

		if (col>0 && row>0 && !visited[row-1][col-1] && matrix[row-1][col-1]==word[ind] && ans==0){

			dfs(ind+1,row-1,col-1);

		}

		visited[row][col] = 0;
	}

}


void checkForWord(){

	for (int i = 0; i < rows; i++)
	{


		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j]==word[0]){
				dfs(1,i,j);
			}
		}



		if (ans==1){
			break;
		}
	}

}


int main(){
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; i++)
	{

		scanf("%d %d",&rows,&columns);

		for (int j = 0; j<rows; j++){
			scanf("%s",&matrix[j][0]);
			for (int k = 0; k < columns; k++)
			{
				visited[j][k] = 0;
			}
		}

		ans = 0;

		//printf("CASO %d\n",i );

		checkForWord();

		if (ans==1){
			printf("YES\n" );
		}
		else{
			printf("NO\n");
		}
	}
}