#include <cstdio>
#include <cstring>

int main(){
    char S[21];
    int R, T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d %s", &R, S);

        int len = strlen(S);
        for(int i = 0; i < len; i++)
            for(int j = 0; j < R; j++)
                putchar(S[i]);
        puts("");
    }
}
