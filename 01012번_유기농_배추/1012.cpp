#include <cstdio>

int spot[50][50]={0, };
int bug;
int M, N;

void dfs(int x, int y) {
	spot[y][x] = 0;
	
	if (spot[y][x+1] == 1 && x+1 < M) {
		dfs(x + 1, y);
	}
	if (spot[y][x - 1] == 1 && x - 1 >= 0) {
		dfs(x - 1, y);
	}
	if (spot[y+1][x] == 1 && y + 1 < N) {
		dfs(x, y+1);
	}
	if (spot[y-1][x] == 1 && y - 1 >= 0) {
		dfs(x, y-1);
	}
}
int main() {
	int T;
	int K; //M(1 <= M <= 50), N(1 <= N <= 50), K(1 <= K <= 2500)
	int x, y;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		bug=0;
		scanf("%d %d %d", &M, &N, &K);
		
		if (K == 0) {
			bug=0;
		}
		else {
			for (int j = 0; j < K; j++) {
				scanf("%d %d", &x, &y);
				spot[y][x] = 1;
			}
			for (int k = 0; k < N; k++) {
				for (int p = 0; p < M; p++) {
					if (spot[k][p] == 1) {
						bug++;
						dfs(p, k);
					}
				}
			}
		}
		printf("%d\n", bug);
	}
}
