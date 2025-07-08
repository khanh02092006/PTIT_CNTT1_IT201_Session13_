#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int cap;
} stack;

// Hàm khởi tạo stack
stack *createStack(int cap) {
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL) {
        printf("Chưa cấp phát được stack.\n");
        return NULL;
    }

    s->arr = (int *)malloc(cap * sizeof(int));
    if (s->arr == NULL) {
        printf("Lỗi: mảng chưa được cấp phát.\n");
        free(s);
        return NULL;
    }

    s->top = -1;
    s->cap = cap;
    return s;
}

// Kiểm tra đầy
int isfull(stack *s) {
    if (s == NULL) {
        printf("Stack NULL.\n");
        return 0;
    }
    return s->top == s->cap - 1;
}

// Kiểm tra rỗng
int isempty(stack *s) {
    return s->top == -1;
}

// Đẩy phần tử
void push(stack *s, int value) {
    if (isfull(s)) {
        printf("Stack đầy, không nhét được nữa.\n");
        return;
    }
    s->arr[++s->top] = value;
}

// Lấy phần tử
int pop(stack *s) {
    if (isempty(s)) {
        printf("Không có phần tử nào để lấy.\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Main
int main(void) {
    stack *mystack = createStack(5);
    if (mystack == NULL) {
        printf("Tạo stack thất bại.\n");
        return 1;
    }

    push(mystack, 10);
    push(mystack, 20);
    push(mystack, 30);
    push(mystack, 40);
    push(mystack, 50);


    printf("Pop: %d\n", pop(mystack));
    printf("Pop: %d\n", pop(mystack));
    printf("Pop: %d\n", pop(mystack));
    printf("Pop: %d\n", pop(mystack));
    printf("Pop: %d\n", pop(mystack));


    return 0;
}
