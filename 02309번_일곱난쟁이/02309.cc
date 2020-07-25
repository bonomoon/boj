#include <cstdio>

int main() {
    int man[9];
    int res = -100;

    for(int i = 0; i < 9; ++i) {
        int loc = i-1;
        scanf("%d", &man[i]);
        res += man[i];

        int temp = man[i];
        while(loc >= 0 && temp < man[loc]){
            man[loc+1] = man[loc];
            loc = loc - 1;
        }
        man[loc+1] = temp;
    }

    for(int i = 0; i < 8; ++i) {
        for(int j = i+1; j < 9; ++j) {
            if(man[i] + man[j] == res) {
                man[i] = 0, man[j] = 0;
                i = j = 10;
            }
        }
    }

    for(const auto& m : man) {
        if(m > 0) {
            printf("%d\n", m);
        }
    }

    return 0;
}
