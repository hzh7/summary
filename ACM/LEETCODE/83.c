#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode* ptr = head;
    //struct ListNode* p;
    while (ptr != NULL && ptr->next != NULL){
        if(ptr->val == ptr->next->val){
            //p = ptr->next;
            ptr->next = ptr->next->next;
            //free(p);
        }
        else
            ptr = ptr->next;
    }
    ptr = head;
    while (ptr != NULL){
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    return head;
}
int main() {
    //printf("Hello, World!\n");
    struct ListNode* p;
    struct ListNode* head;
    p = (struct ListNode*)malloc(sizeof(struct ListNode*));
    p->val = 1;
    head = p;
    p = (struct ListNode*)malloc(sizeof(struct ListNode*));
    p->val = 2;
    head->next = p;
    p->next = NULL;
    deleteDuplicates(head);
    return 0;
}