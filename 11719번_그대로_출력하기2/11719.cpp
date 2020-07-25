#include <cstdio>

int main() {
	char buf[101];
	buf[0] = '\0';

	while (fgets(buf, 100, stdin)) {
		printf("%s", buf);
	}
}
