#include <cstdio>

int recs[1001];

int solution(int n) {
    recs[1] = 1, recs[2] = 2;

    if(n == 1 || n == 2) {
        return recs[n];
    } else {
        for(int i = 3; i <= n; ++i) {
            recs[i] = (recs[i - 1] + recs[i - 2]) % 10007;
        }
        return recs[n];
    }
}

int main() {
    int n;  // 1 <= n <= 1000
    scanf("%d", &n);
    printf("%d\n", solution(n));

    return 0;
}