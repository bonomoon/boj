#include <cstdio>
#include <algorithm>

struct Conference {
    int begin;
    int end;
};

int GreedyConferenceCount(struct Conference *conference, int N) {
    std::sort(conference, conference+N, [](const Conference& a, const Conference& b) {
        if(a.end == b.end) {    // 끝나는 시간이 같으면 시작시간으로 정렬
            return a.begin < b.begin;
        }
        return a.end < b.end;   // 안 같으면 걍 끝나는 시간으로 정렬 
    });
    
    int last = -1, cnt = 0;
    for(int i = 0; i < N; ++i) {
        if(last <= conference[i].begin) {
            last = conference[i].end;
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    int N; //N개의 회의
    scanf("%d", &N);

    struct Conference *conference = new Conference[N];

    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &conference[i].begin, &conference[i].end);
    }
    printf("%d\n", GreedyConferenceCount(conference, N));
    delete[] conference;
    
    return 0;
}
