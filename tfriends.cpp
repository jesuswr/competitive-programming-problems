#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>

using namespace std;

int n;
int visited[101];
char map[101][101];
stack<int> pila;

int dfs(int v){
	visited[v] = 1;

	for (int i = 1; i <= n; i++)
	{
		//printf("%c\n",map[v][i] );
		if( map[v][i]=='Y' && !visited[i] ){
			//printf("HOLA\n");
			dfs(i);
		}
	}
	pila.push(v);
}

int dfs2(int v){
	visited[v] = 1;

	for (int i = 1; i <= n; i++)
	{
		if( map[i][v]=='Y' && !visited[i] ){
			dfs2(i);
		}
	}
	
}





int main(){
	int t;
	scanf("%d",&t);
	int cont;
	int aux;
	for (int ii = 0; ii < t; ii++)
	{
		scanf("%d",&n);
		cont = 0;
		for (int i = 1; i <= n; i++)
		{
			visited[i] = 0;
			scanf("%s",&map[i][1]);
		}
		

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			visited[i] = 0;
		}

		while(!pila.empty()) {
		    aux = pila.top();
		    pila.pop();
		    //printf("%d\n",aux );
		    if (!visited[aux])
		    {
		    	cont++;
		    	dfs2(aux);
		    }
		}

		printf("%d\n", cont);


	}
}
