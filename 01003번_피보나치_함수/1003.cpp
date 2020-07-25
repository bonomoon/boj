#include <cstdio>

void solve(int N) {
    int zero[41] = {0, }, one[41] = {0, };

    zero[0] = 1, one[0] = 0;
    zero[1] = 0, one[1] = 1;

    for(int i = 2; i <= N; ++i) {
        if(zero[i] != 0 && one[i] != 0) {
            continue;
        } else {
            zero[i] = zero[i - 1] + zero[i - 2];
            one[i] = one[i - 1] + one[i - 2];
        }
    }
    printf("%d %d\n", zero[N], one[N]);
}

int main() {
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; ++i) {
        int N;
        scanf("%d", &N);
        solve(N);
    }

    return 0;
}
