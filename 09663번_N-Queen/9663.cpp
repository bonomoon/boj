#include <cstdio>
#include <cmath>

int col[15] = { 0, };
int answer = 0;

bool promising(int level) {
	for(int i = 0; i < level; ++i) {
		if(col[level] == col[i] || abs(col[level] - col[i]) == (level - i)) {
			return false;
		}
	}
	return true;
}

void dfs(int level, int N) {
	if(level == N) {
		++answer;
	} else {
		for(int i = 0; i < N; ++i) {
			col[level] = i;

			if(promising(level)) {
				dfs(level + 1, N);
			}
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);

	dfs(0, N);
	printf("%d\n", answer);

	return 0;
}
