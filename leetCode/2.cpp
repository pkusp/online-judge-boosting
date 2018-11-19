/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *carry = dummy;
        int sum = 0;
        while(l1||l2){
        	int n1 = l1?l1->val:0;
        	int n2 = l2?l2->val:0;
        	sum = n1+n2+sum;
        	ListNode *tmp =  new ListNode(sum%10);
        	carry->next = tmp;
        	carry = carry->next;
        	sum = sum/10;
        	if(l1) l1=l1->next;
        	if(l2) l2 = l2->next;
        }
        if(sum){
        	carry->next = new ListNode(sum);
        	carry = carry->next;
        }
        carry->next = NULL;

        return dummy->next;

    }
};