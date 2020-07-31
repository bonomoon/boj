#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int offset[] = {0, -1, 0, 1, 0};
int map[25][25];
int cnt = 1;

void bfs(pair<int, int> start, int N) {
    int x = start.second, y = start.first;
    for (int i = 0; i < 4; ++i) {
        int offset_x = x + offset[i], offset_y = y + offset[i + 1];

        if (offset_x >= 0 && offset_x < N && offset_y >= 0 && offset_y < N) {
            if (map[offset_y][offset_x]) {
                map[offset_y][offset_x] = 0, ++cnt;
                bfs({offset_y, offset_x}, N);
            }
        }
    }
}

void solve(int N) {
	vector<int> v;

	v.push_back(0);

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if (map[i][j]) {
				map[i][j] = 0, v[0] += 1;
				bfs({i, j}, N);
				v.push_back(cnt), cnt = 1;
			}
		}
	}
	sort(v.begin() + 1, v.end());

	for(const auto& e : v) {
		printf("%d\n", e);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
	solve(N);

	return 0;
}
