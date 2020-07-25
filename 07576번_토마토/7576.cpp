#include <cstdio>
#include <queue>

int box[1000][1000];
std::queue<std::pair<int, int>> q;

int checkTomato(int row, int col) {
    int offset[] = {0, -1, 0, 1, 0}, day_cnt = -1;

    while(!q.empty()) {
        int q_size = q.size();
        ++day_cnt;

        for (int i = 0; i < q_size; ++i) {
            int x = q.front().second, y = q.front().first;
            q.pop();

            for(int j = 0; j < 4; ++j) {
                int offset_x = x + offset[j], offset_y = y + offset[j + 1];

                if(offset_x >= 0 && offset_x < col && offset_y >= 0 && offset_y < row) {    // 주변에 안 익은 토마토를 큐에 넣는다.
                    if(box[offset_y][offset_x] == 0) {
                        box[offset_y][offset_x] = 1;
                        q.push({offset_y, offset_x});
                    }
                }
            }
        }
    }

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            if(box[i][j] == 0) {
                return -1;
            }
        }
    }

    return day_cnt;
}

int main() {
    int m, n;  // m : 상자의 가로 칸의 수, n: 상자의 세로 칸의 수
    scanf("%d %d", &m, &n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf("%d", &box[i][j]);

            if(box[i][j] == 1) {      // 1일 때 큐에 넣음 (0일 때 익은 토마토들의 초기 상태)
                q.push({i, j});
            }
        }
    }

    printf("%d\n", checkTomato(n, m));

    return 0;
}