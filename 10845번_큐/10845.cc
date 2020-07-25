#include <cstdio>

#define CAPACITY 1000

typedef struct _Queue {
    int front, rear, size;
    int array[CAPACITY];
}Queue;

Queue* CreateQueue() {
    Queue* queue = new Queue();
    queue->front = queue->size = 0;
    queue->rear = CAPACITY - 1;
    return queue;
}

void Push(Queue* queue, int item) {
    queue->rear = (queue->rear+1) % CAPACITY;
    queue->array[queue->rear] = item;
    ++queue->size;
}

bool IsEmpty(Queue* queue) {
    return (queue->size == 0);
}

int Pop(Queue* queue) {
    if(IsEmpty(queue)) {
        return -1;
    }
    int temp = queue->array[queue->front];
    queue->front = (queue->front+1) % CAPACITY;
    queue->size = queue->size - 1;

    return temp;
}

int GetSize(Queue* queue) {
    return queue->size; 
}

int GetFront(Queue* queue) {
    if(IsEmpty(queue)) {
        return -1;
    }
    return queue->array[queue->front];
}

int GetRear(Queue* queue) {
    if(IsEmpty(queue)) {
        return -1;
    }
    return queue->array[queue->rear];
}

int main() {
    Queue* queue = CreateQueue();
    int inst_num; //intruction Number
    scanf("%d", &inst_num);

    char buf[6];
    while(inst_num--) {
        scanf("%s", buf);

        if(buf[0] == 'p' && buf[1] == 'u') {
            int item;
            scanf("%d", &item);
            Push(queue, item);
        } 
        if(buf[0] == 'p' && buf[1] == 'o') {
           printf("%d\n", Pop(queue)); 
        } 
        if(buf[0] == 's' && buf[1] == 'i') {
           printf("%d\n", GetSize(queue)); 
        } 
        if(buf[0] == 'e' && buf[1] == 'm') {
           printf("%d\n", IsEmpty(queue)); 
        }  
        if(buf[0] == 'f' && buf[1] == 'r') {
           printf("%d\n", GetFront(queue)); 
        }
        if(buf[0] == 'b' && buf[1] == 'a') {
           printf("%d\n", GetRear(queue)); 
        }
        getchar();
    }

    return 0;
}
