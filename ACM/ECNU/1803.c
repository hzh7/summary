#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
};
int main() {
    int n;
    int ndata;
    int q;int a, b;
    struct Node *frist, *ptr;
    frist = (struct Node*)malloc(sizeof(struct Node));
    ptr = frist;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ndata);
        struct Node *p;
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = ndata;
        p->next = NULL;
        ptr->next = p;
        ptr = p;
    }
    scanf("%d", &q);
    while (q--){
        scanf("%d %d", &a, &b);
        ptr = frist->next;
        while (ptr->data != a){
            //printf("%d  ", ptr->data);
            ptr = ptr->next;
        }
        struct Node *p;
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = b;
        p->next = ptr->next;
        ptr->next = p;

        //打印链表
        ptr = frist->next;
        while (ptr->next != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
    //printf("Hello, World!\n");
    return 0;
}