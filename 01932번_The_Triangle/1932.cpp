#include <cstdio>

int dp[501][501];   //값의 합 저장

inline int getMax(int x, int y){
    return (x < y)? y: x;
}

/*ex) 7
      3 8
      8 1 0
      2 7 4 4
      4 5 2 6 5
*/
int main(){
    int n, max = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d", &dp[i][j]);

            if(i >= 2) {
                if(j == 1)  //i번째 줄의 첫 노드일 때
                    dp[i][j] += dp[i-1][j];
                else if(j == i) //i번째 줄의 끝 노드일 때
                    dp[i][j] += dp[i-1][j-1];
                else    //i번째 줄의 사이 노드일 때
                    dp[i][j] += getMax(dp[i-1][j-1], dp[i-1][j]);
            }
            max = getMax(max, dp[i][j]);
        }
    }
    printf("%d\n", max);
}
