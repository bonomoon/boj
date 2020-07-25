#include <cstdio>
#include <algorithm>

#define MAX 1000001

int min_cnt[MAX];

void CalMinCountToMakeOne(int x) {
    min_cnt[2] = 1, min_cnt[3] = 1;

    if(x <= 3) {
        return;
    }

    for(int idx = 4; idx <= x; ++idx) { 
        min_cnt[idx] = min_cnt[idx-1] + 1;

        if(!(idx % 3)) {
            min_cnt[idx] = std::min(min_cnt[idx], min_cnt[idx/3] + 1);
        }
        if(!(idx % 2)) {
            min_cnt[idx] = std::min(min_cnt[idx], min_cnt[idx/2] + 1);
        }
    }
}

int main () {
    int x;
    scanf("%d", &x);

    CalMinCountToMakeOne(x);
    printf("%d\n", min_cnt[x]);

    return 0;
}
