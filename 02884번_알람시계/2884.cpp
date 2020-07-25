#include <cstdio>

int main() {
	int H, M;	// 0:0 ~ 23: 59
	scanf("%d %d", &H, &M);

	M -= 45;

	if(M >= 0) {
		printf("%d %d\n", H, M);
	} else {
		H -= 1;
		if(H >= 0) {
			printf("%d %d\n", H, 60 + M);
		} else {
			printf("%d %d\n", 24 + H, 60 + M);
		}
	}

	return 0;
}