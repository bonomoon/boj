#define MY_LOCAL_TEST

#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int cnt = 0;

void searchVirusNode(vector<int> *node, bool *check){

	stack<int> s;
	s.push(1);
	check[1] = true;

	while(!s.empty()) {
	
		int curNode = s.top();

		if(!node[curNode].empty()) {
			if(check[curNode] == false) {
				check[curNode] = true;
				cnt++;
			}
			
			int nextNode = node[curNode].back();
			node[curNode].pop_back();

			if(check[nextNode] == false)
				s.push(nextNode);

		} else {
			s.pop();
		}
	}
}

int main() {
	int N, link;

	#ifdef MY_LOCAL_TEST  
		freopen("input.txt", "r", stdin);  
		//freopen("output.txt", "w", stdout);  
	#endif

	scanf("%d", &N);
	scanf("%d", &link);

	vector<int> graph[N+1];
	bool check[N+1];
	fill(check, check + N + 1, false);

	for(int i = 0; i < link; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	searchVirusNode(graph, check);

	printf("%d\n", cnt);

	#ifdef MY_LOCAL_TEST
		fclose(stdin);
	#endif

	return 0;
}
