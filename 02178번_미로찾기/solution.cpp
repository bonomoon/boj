#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int map[100][100];
int offset[] = {0, -1, 0, 1, 0};

queue<pair<int, int>> q;

int solve(int N, int M) {
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int offset_x = x + offset[i + 1], offset_y = y + offset[i];
			
            if (offset_x >= 0 && offset_x < M && offset_y >= 0 && offset_y < N) {
                if (map[offset_y][offset_x] == 1) {
                    map[offset_y][offset_x] = map[y][x] + 1;
                    q.push({offset_x, offset_y});
                }
            }
        }
    }

    return map[N - 1][M - 1];
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i) {
		char str[101];
		scanf("%s", str);
		for (int j = 0; j < M; ++j) {
			map[i][j] = str[j] - '0';
		}
	}
	
	printf("%d\n", solve(N, M));

	return 0;
}