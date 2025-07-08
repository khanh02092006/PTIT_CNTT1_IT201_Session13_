#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 typedef  struct
 {
     int *arr;
     int top;
     int cap;
 }stack;
stack *createStack(int cap)
{
    stack* newStack = (stack*)malloc(sizeof(stack));
    if(newStack == NULL)
    {
        return NULL;
    }
    newStack->arr=(char*) malloc(sizeof(char)*(cap));
    if (newStack->arr == NULL)
    {
        printf("chua cap phat");
        return NULL;

    }
    newStack->top=-1;
    newStack->cap=cap;
    return newStack;
}
int isfullStack(stack *newstack) {
    return newstack->top == newstack->cap - 1;
}
int isemptyStack(stack *newstack)
{
    return newstack->top == -1;
}
int pop(stack *newstack)
{
    if (newstack->top>=0)
    {
        return newstack->arr[newstack->top--];

    }
    return'\0';
}
void push(stack *newstack, int item)
{
    if (isfullStack(newstack))
    {
        printf(" da day roi");
        return;
    }
    newstack->arr[++newstack->top] = item;
}
bool chuoidaonuoc(const char* str)
{
 int len=strlen(str);;
    stack *newstack = createStack(len);
    if(newstack == NULL)
    {
        printf(" stack rong");
        return false;
    }
    for(int i=0;i<len;i++)
    {
        push(newstack,str[i]);
    }
    for(int i=0;i<len;i++)
    {
        if (str[i]!=pop(newstack))
        {
            free(newstack->arr);
            free(newstack);
            return false;
        }
    }
    free(newstack->arr);
    free(newstack);
    return true;
}



int main()
{
    char str[1000];

    printf("Nhập chuỗi cần kiểm tra: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Xoá '\n' nếu có

    if (chuoidaonuoc(str)) {
        printf("Chuỗi \"%s\" là chuỗi đối xứng.\n", str);
    } else {
        printf("Chuỗi \"%s\" KHÔNG phải là chuỗi đối xứng.\n", str);
    }

    return 0;
}
