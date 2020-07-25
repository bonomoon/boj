#include <cstdio>
#include <cstdlib>
#include <cmath>

typedef struct _Turret {
    int x, y, r;
} Turret;

double get_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int solve(Turret t1, Turret t2) {
    double d = get_distance(t1.x, t1.y, t2.x, t2.y);
    int r = t1.r + t2.r;

    if(d > r) {
        return 0;
    } else {
        if (d == r) {
            return 1;
        } else {
            if(d == 0) {    // 원의 중심이 같을 경우
                if(t1.r == t2.r) {
                    return -1;
                } else {
                    return 0;
                }
            } else {
                if(d == abs(t1.r - t2.r)) {
                    return 1;
                } else if(d < abs(t1.r - t2.r)) {
                    return 0;
                } else {
                    return 2;
                }
            }
        }
    }
}

int main() {
    int T = 0;
    int distance = 0;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        int d = 0;
        Turret t1, t2;
        scanf("%d %d %d %d %d %d", &t1.x, &t1.y, &t1.r, &t2.x, &t2.y, &t2.r);
        printf("%d\n", solve(t1, t2));
    }
    return 0;
}