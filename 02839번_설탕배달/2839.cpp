#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = N/5; i >= 0; i--) {
		int t = N - (i * 5);
		if (t % 3 == 0) {
			printf("%d", i + (t/3));
			break;
		}
		else {
			if (t == N) {
				printf("-1");
			}
		}
	}
}
