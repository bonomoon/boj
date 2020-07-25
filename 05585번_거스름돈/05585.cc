#include <cstdio>

int GetMinCoinCount(int *coin, int change) {
    int coin_cnt = 0;
    for(int i = 5; i >= 0 && change; --i) {
        coin_cnt += change/coin[i]; 
        change %= coin[i];

    } 
    return coin_cnt;
}

int main() {
    int coin[6] = {1, 5, 10, 50, 100, 500}; //엔화 동전 6개
    int change;  //타로가 받을 거스름돈
    scanf("%d", &change);

    change = 1000 - change; //타로는 1000엔 낼꺼니깐 ㅎㅎ

    printf("%d\n", GetMinCoinCount(coin, change));

    return 0;
}
