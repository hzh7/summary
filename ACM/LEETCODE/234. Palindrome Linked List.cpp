#include<iostream>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL){
			return true;
		}
		ListNode *ptr1 = head, *ptr2 = head;
		while (ptr2->next != NULL && ptr2->next->next != NULL){
			ptr1 = ptr1->next;
			ptr2 = ptr2->next->next;
		}
		if (ptr2->next != NULL){
			ptr2 = ptr2->next;
		}

		ListNode *r = NULL, *h = ptr1->next, *p = NULL;
		while (h != NULL)
		{
			r = h->next;
			h->next = p;
			p = h;
			h = r;
		}
		ptr1->next = NULL;
		ptr1 = head;

		while (ptr2 != NULL)
		{
			if (ptr1->val != ptr2->val){
				return false;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		return true;
	}
};
int main(){
	ListNode* head1 = new ListNode(1);
	ListNode* head2 = new ListNode(0);
	ListNode* head3 = new ListNode(1);
	head1->next = head2;
	head2->next = head3;
	head3->next = NULL;
	bool a = Solution().isPalindrome(head1);
	cout << a;
	getchar();
	return 0;
}