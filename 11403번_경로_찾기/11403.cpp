#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int adj[101][101];
int path[101];
int N;

void dfs(int v){
	for(int i = 1; i <= N; i++){
		if(adj[v][i] == 1 && path[i] == 0){
			path[i] = 1;
			dfs(i);
		}
	}
}

int main(){
	scanf("%d", &N);

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%d", &adj[i][j]);
		}
	}

	for(int i = 1; i <= N; i++){
		dfs(i);

		for(int j = 1; j <= N; j++){
			adj[i][j] = path[j];
		}
		memset(path, 0, sizeof(int)*(N+1));

	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}	
}
