#include <cstdio>

void CountAdding(int * cnt_array) {
    //f(n) = f(n-1) + f(n-2) + f(n-3)
    for(int num = 4; num <= 11; ++num) {
        cnt_array[num] = cnt_array[num-1] + cnt_array[num-2] + cnt_array[num-3];  
    }
}

int main() {
    int T, num, cnt_array[12] = {0, 1, 2, 4, }; //T: test case, num: input num
    scanf("%d", &T);

    CountAdding(cnt_array);

    while(T--) {
        scanf("%d", &num);
        printf("%d\n", cnt_array[num]);
    }

    return 0;
}
