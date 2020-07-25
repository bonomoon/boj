#include <cstdio>

int main(){
	int N, M;	// N: 카드의 개수, M: 카드의 합
	int cards[100] = { 0, }, sum = 0, ans = 0;
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; ++i) {
		scanf("%d", &cards[i]);
	}

	for(int i = 0; i < N - 2; ++i) {
		for(int j = i + 1; j < N - 1; ++j) {
			for(int k = j + 1; k < N; ++k) {
				sum = cards[i] + cards[j] + cards[k];
				if(sum > ans && sum <= M) {
					ans = sum;
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}