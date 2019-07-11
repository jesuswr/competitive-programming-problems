#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;


int getMin(vector<int> g[], int v){

	int visited[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = 0;
	}

	stack<int> open;

	int ans = 0;

	for (int i = 0; i < v; ++i)
	{
		if (!visited[i]){
			open.push(i);
			ans ++;
		}
		while (!open.empty()){
			int aux = open.top();
			open.pop();
			visited[aux] = 1;
			for( int w: g[aux]){
				if (!visited[w]){
					open.push(w);
				}
			}
		}
	}

	return ans;


}

int main(){
	int n;
	int m;
	scanf("%d",&n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d",&N);
		scanf("%d",&m);
		vector<int> graph[N];


		int n1,n2;
		
		for (int j = 0; j < m; j++)
		{
			scanf("%d %d",&n1,&n2);
			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}

		int ans = getMin(graph,N);
		printf("%d\n", ans);

	}
}
		