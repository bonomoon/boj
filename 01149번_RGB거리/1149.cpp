#include <cstdio>

int house[1001][3];
int cost[1001][3];

inline int getMin(int x, int y){
    return (x < y)? x : y;
}

inline int getMin(int x, int y, int z){
    return (x < y)?((x > z)? z:x) : ((y > z)? z:y);
}

int main(){
    int N;	//The number of house
    scanf("%d", &N);

	//cost[i][j] <- paint_cost 
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    
    //house[1][i] <- cost[1][i] (0 <= i <= 2)
    house[1][0] = cost[1][0];
    house[1][1] = cost[1][1];
    house[1][2] = cost[1][2];

	//house[i][] <- getMin(house[i-1][], house[i-1][]) + cost[i][]
    for(int i = 2; i <= N; i++){
        house[i][0] = getMin(house[i-1][1], house[i-1][2]) + cost[i][0];
        house[i][1] = getMin(house[i-1][0], house[i-1][2]) + cost[i][1];
        house[i][2] = getMin(house[i-1][0], house[i-1][1]) + cost[i][2];
    }
    
	//getMin(house[N][0], house[N][1], house[N][2])
    printf("%d\n", getMin(house[N][0], house[N][1], house[N][2]));
}
