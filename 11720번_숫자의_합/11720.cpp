#include <cstdio>

char input[101];

int main(){
    int n,
        sum = 0;
    scanf("%d", &n);
    scanf("%s", input);

    for(int i = 0; i < n; i++)
        sum += input[i] - '0'; 
    printf("%d", sum);
}
