#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef  struct
{
    int *arr;
    int top;
    int  cap;

}stack;
stack* createStack(int cap)
{
    stack* newStack = (stack*)malloc(sizeof(stack));
    if(newStack == NULL)
    {
        printf("chua duoc cap phat");
        return NULL;
    }
    newStack->arr = (int*)malloc(cap * sizeof(int));
    if(newStack->arr == NULL)
    {
        printf(" chua cap phat mang");
        return NULL;
    }
    newStack->top = -1;
    newStack->cap = cap;
    return newStack;
}
//kiem tra stack day
int isfullStack(stack* newStack)
{
    return newStack->top == newStack->cap - 1;
}
// kiem tra stack rong
int isEmpty(stack* newStack)
{
    return newStack->top == -1;
}
void push(stack* newStack, int value)
{
    if(isfullStack(newStack))
    {
        printf("stack da day chua roi khong the them ");
        return ;
    }
    newStack->arr[++(newStack->top)] = value;
}
int pop(stack* newStack)
{
    if(isEmpty(newStack))
    {
        printf(" khong co phan tu nao de lay");
        return -1;

    }
    return newStack->arr[newStack->top--];
}


int main(void)
{
 stack* newStack = createStack(5);
    if (newStack == NULL)
    {
        printf(" tao ngan xep khong duoc");
        return 1;
    }
    int value;
    for (int i=0;i< 5;i++ )
    {
        printf(" nhap phan tu thu %d:",i+1);
        scanf("%d",&value);
        push(newStack,value);

    }
    printf(" phan tu dinh %d",pop(newStack));



    return 0;
}