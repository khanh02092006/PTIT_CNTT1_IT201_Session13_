#include <stdio.h>
#include <stdlib.h>

// Định nghĩa stack
typedef struct {
    int *arr;
    int top;
    int cap;
} stack;

// Khởi tạo stack
stack* createStack(int cap) {
    stack* s = (stack*)malloc(sizeof(stack));
    if (s == NULL) return NULL;

    s->arr = (int*)malloc(sizeof(int) * cap);
    if (s->arr == NULL) {
        free(s);
        return NULL;
    }

    s->top = -1;
    s->cap = cap;
    return s;
}

int isFull(stack* s) {
    return s->top == s->cap - 1;
}

int isEmpty(stack* s) {
    return s->top == -1;
}

void push(stack* s, int val) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = val;
    }
}

int pop(stack* s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1;
}


void reverseArray(int *array, int size) {
    stack *s = createStack(size);
    if (s == NULL) {
        printf("Không tạo được stack.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        push(s, array[i]);
    }

    for (int i = 0; i < size; i++) {
        array[i] = pop(s);
    }

    free(s->arr);
    free(s);
}

// In mảng
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main
int main() {
    int n;
    printf("Nhập số phần tử của mảng: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Không cấp phát được mảng.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhập phần tử thứ %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Mảng ban đầu: ");
    printArray(array, n);

    reverseArray(array, n);

    printf("Mảng sau khi đảo: ");
    printArray(array, n);

    free(array);
    return 0;
}
