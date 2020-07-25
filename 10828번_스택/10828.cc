#include <cstdio>
#include <cstring>

typedef struct Stack {
    int data[10000];
    int top = 0;
};

Stack stack;

void push(int data);
bool empty();
int pop();
int size();
int top();

int main(){
    int exec_num; //Number of instruction
    scanf("%d", &exec_num);

    char str[6];
    for(int iter = 0; iter < exec_num; ++iter){
        scanf("%s", str);

        if(!strcmp(str, "push")){
            int data;
            scanf("%d", &data);
            push(data);
        }
        else if(!strcmp(str, "pop")){
            printf("%d\n", pop());
        }
        else if(!strcmp(str, "size")){
            printf("%d\n", size());
        }
        else if(!strcmp(str, "empty")){
            printf("%d\n", empty());
        }  
        else if(!strcmp(str, "top")){
            printf("%d\n", top());
        }
    }
}

void push(int data) {
    stack.data[stack.top++] = data;
}

bool empty() {
    if(stack.top <= 0) {
        return true;
    }
    else {
        return false;
    }
}

int pop() {
    if(empty()) {
        return -1;
    }
    else {
        return stack.data[--stack.top];
    }
}

int size() {
    return stack.top;
} 

int top() {
    if(empty()) {
        return -1;
    }
    else {
        return stack.data[stack.top-1];
    }
}

