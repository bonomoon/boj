#include <cstdio>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%s\n", A > B ? ">" : A == B ? "==" : "<");

    return 0;
}
