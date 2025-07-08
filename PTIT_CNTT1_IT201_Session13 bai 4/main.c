#include <stdio.h>
#include <stdlib.h>
typedef  struct
{
    int *arr;
    int top;
    int cap;
} stack;
stack* createStack(int cap)
{
    stack* newstack=(stack*)malloc(sizeof(stack));
    if (newstack == NULL)
    {
        printf(" chua cap phat");
        return NULL;
    }
    newstack->arr=(int*)malloc(sizeof(int)*(cap));
    if (newstack->arr == NULL)
    {
        printf("chua cap phat mang");
        free(newstack);
        return NULL;
    }
    newstack->top=-1;
    newstack->cap=cap;
    return newstack;

}
int isFull(stack* newstack)
{
    return newstack->top==newstack->cap-1;
}
int isEmpty(stack* newstack)
{
    return newstack->top==-1;

}
void push(stack* newstack, int val)
{
    //kiem tra phan tu xem có rong khong
    if (isFull(newstack))
    {
        printf(" da day ");
        return;

    }
    newstack->arr[++(newstack->top)]=val;
}
void print_list(stack* newstack)
{
    if (newstack==NULL)
    {
        printf(" stack rong khong co gi ");
        return;
    }
    if (newstack->top==-1)
    {
        printf(" stack rong khong co gi de in ");
        return ;
    }
    for (int i=newstack->top;i>=0;i--)
    {
        printf("%d",newstack->arr[i]);

    }
    printf("\n");

}

int main(void)
{
    int n;
    printf(" nhap so phantu co trong stack");
    scanf("%d",&n);
    stack* newstack=createStack(n);
    if (newstack == NULL)
    {
        printf(" tao stack loi");
        return 1;
    }
    for (int i=0;i<n;i++)
    {
        int val;
        printf(" nhap phan tu thu %d",i+1);
        scanf("%d",&val);
        push(newstack,val);
        printf("\n");
    }
    print_list(newstack);


    return 0;
}