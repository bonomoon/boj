#include <cstdio>
#include <algorithm>

int time[1000];

int GetMinTime(int man_num) {
    int min_time = 0;
    for(int i = 0; i < man_num; ++i) {
        min_time += time[i] * (man_num-i);  //중복시간들을 다 더하면 time[0]*n + time[1]*(n-1) + ...
    }
    return min_time;
}

int main() {
    int man_num; //사람 몇 명?
    scanf("%d", &man_num);

    for(int i = 0; i < man_num; ++i) {  //시간입력
        scanf("%d", &time[i]);
    }
    getchar();  //버퍼 비우기
    std::sort(time, time + man_num); //시간 정렬

    printf("%d\n", GetMinTime(man_num));

    return 0;
}