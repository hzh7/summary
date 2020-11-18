#include <stdio.h>
#include <malloc.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    //struct ListNode* p1;
    //struct ListNode* p2;
    struct ListNode* ptr;
    struct ListNode* first;
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    if(l1->val <= l2->val){
        ptr = l1;
        l1 = l1->next;
    }else{
        ptr = l2;
        l2 = l2->next;
    }
    first = ptr;
    while (l1 != NULL && l2 != NULL){
        if (l1->val <= l2->val) {
            ptr->next = l1;
            ptr = l1;
            l1 = l1->next;
        } else{
            ptr->next = l2;
            ptr = l2;
            l2 = l2->next;
        }
    }
    if(l1 == NULL)
        ptr->next = l2;
    else
        ptr->next = l1;
    /*ptr = first;
    while (ptr != NULL){
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }*/
    return first;

}
int main() {
    //printf("Hello, World!\n");
    struct ListNode* l1;
    l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2;
    l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l2->val = 1;
    struct ListNode* ptr;
    ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = 2;
    l1->next = ptr;
    ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = 4;
    ptr->next = NULL;
    l1->next->next = ptr;
    ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = 3;
    l2->next = ptr;
    ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = 4;
    ptr->next = NULL;
    l2->next->next = ptr;
    /*printf("%d", l1->val);
    printf("%d", l1->next->val);
    printf("%d\n", l1->next->next->val);
    printf("%d", l2->val);
    printf("%d", l2->next->val);
    printf("%d", l2->next->next->val);*/
    mergeTwoLists(l1, l2);
    return 0;
}