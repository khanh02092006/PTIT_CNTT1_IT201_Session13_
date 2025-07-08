#include <stdio.h>
#include <stdlib.h>

typedef  struct
 {
     int *arr;
     int top;
     int cap;

 } stack;
stack* ceatelit(int cap)
{
    stack * stacklit=(stack*)malloc(sizeof(stack));
    if (stacklit == NULL)
    {
        printf(" chua cap phat ");
        return NULL;
    }
    stacklit-> arr = (int*)malloc(cap * sizeof(int));
    if (stacklit-> arr == NULL)
    {
        printf(" chua cap phat ");
        free(stacklit);
        return NULL;
    }
    stacklit-> cap = cap;
    stacklit->top = -1;
    return stacklit;

}

int infull( stack* stacklit ){
return stacklit -> top == stacklit -> cap - 1;
}
 void push( stack* stacklit , int val )
{
    if (infull(stacklit))
    {
        printf(" stack, day ");
        return;
    }
     return stacklit->arr[++(stacklit->top)] = val;
}

int main(void)
{
 stack* mystack=ceatelit(5);
    if (mystack == NULL)
    {
        printf(" tạo thất bại ");
        return 1;
    }
    int value;
    for (int i=0; i<5; i++)
    {
        printf("  nhap so nguyen thu %d",i+1);
        scanf("%d", &value);
        push(mystack, value);
    }
    while (mystack->top != -1)
    {
        printf(" %d",mystack->arr[mystack->top--]);

    }
    return 0;
}