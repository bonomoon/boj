#include <cstdio>

int main() {
	int x, y;
	scanf("%d\n%d", &x, &y);
	// 1 - (+, +), 2 - (-, +), 3 - (-, -), 4 - (+, -)
	int ans = x > 0 ? y > 0 ? 1 : 4 : y > 0 ? 2 : 3;
	printf("%d\n", ans);

	return 0;
}