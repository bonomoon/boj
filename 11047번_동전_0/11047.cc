#include <cstdio>

int GetMinCoinCount(int *coin, int N, int K) {
    int coin_cnt = 0;
    while(K != 0) {     //K원이 0원 될때까지
        coin_cnt += K/coin[--N]; 
        K %= coin[N];
    }
    return coin_cnt;
}

int main() {
    int coin[10];
    int N, K;   //N개 동전, 동전으로 만들고 싶은 K원
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; ++i) {
        scanf("%d", &coin[i]);
    }
    
    printf("%d\n", GetMinCoinCount(coin, N, K));
    return 0;
}
