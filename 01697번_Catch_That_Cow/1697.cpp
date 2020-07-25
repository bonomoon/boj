#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

queue<int> q;
int visited[100001];

int bfs(int n, int k){
    q.push(n);
	visited[n] = 1;

	int check;

	while(!q.empty()){
		check = q.front();
		q.pop();
		if(check == k)
			return visited[check] - 1; 

		if((check - 1) >= 0 && visited[check-1] == 0){
			visited[check-1] = visited[check] + 1;
			q.push(check-1);
		}
		if((check + 1) <= 100000 && visited[check+1] == 0){
			visited[check+1] = visited[check] + 1;
			q.push(check+1);
		}
		if((check*2) <= 100000 && visited[check*2] == 0){
			visited[check*2] = visited[check] + 1;
			q.push(check*2);
		}
	}
}
	
int main(){
	int n, k;

	scanf("%d %d", &n, &k);
	printf("%d\n", bfs(n, k));
}
